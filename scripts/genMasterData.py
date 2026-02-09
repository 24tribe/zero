"""
This script receives the directory with the master data json files
and produces a sql script to import them in the semba db
"""

from argparse import ArgumentParser
from pathlib import Path
import json


def main():
    parser = ArgumentParser()
    parser.add_argument("masterdata_dir", type=Path)
    parser.add_argument("out_sql")
    args = parser.parse_args()

    with open(args.masterdata_dir/"tension_card.json", "r", encoding="utf-8") as f:
        md_tension_card_json = json.load(f)

    with open(args.masterdata_dir/"ability_tension_card.json", "r", encoding="utf-8") as f:
        md_ability_tension_card_json = json.load(f)

    with open(args.masterdata_dir/"ability_efficacy.json", "r", encoding="utf-8") as f:
        md_ability_efficacy_json = json.load(f)

    with open(args.masterdata_dir/"area_change_lock.json", "r", encoding="utf-8") as f:
        md_area_change_lock_json = json.load(f)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        gen_md_tension_card(md_tension_card_json, f)
        gen_md_ability_tension_card(md_ability_tension_card_json, f)
        gen_md_ability_efficacy(md_ability_efficacy_json, f)
        gen_md_area_change_lock(md_area_change_lock_json, f)


def gen_md_area_change_lock(md_area_change_lock_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdAreaChangeLock (id, areaId) VALUES")

    first = True
    for area_change_lock in md_area_change_lock_json:
        id_ = area_change_lock["id"]
        for area_id in area_change_lock["area_ids"]:
            if first:
                first = False
            else:
                f.write(",")

            row = (id_, area_id)
            row = list(map(convert_to_sql, row))
            xprint(f"({', '.join(row)})")

    xprint(";")


def convert_to_sql(val):
    if isinstance(val, int):
        return str(val)
    elif isinstance(val, str):
        return f"'{val}'"
    elif isinstance(val, (dict, list)):
        return f"'{json.dumps(val)}'"
    else:
        assert False


def gen_md_ability_efficacy(md_ability_efficacy_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("""
INSERT INTO mdAbilityEfficacy
(abilityEfficacyId, abilityEfficacyGroupId, coolTimeMillisecond, effectCoolTimeMillisecond,
activeTimeMillisecond, efficacyType, probability, activateConditions, deactivateConditions,
sustainConditions, targetConditions, fValues, values_, uiViewPriority, effectValueSteps,
targetType) VALUES
""")

    first = True

    for md_ability_efficacy in md_ability_efficacy_json:
        abilityEfficacyId = md_ability_efficacy["id"]
        abilityEfficacyGroupId = md_ability_efficacy["ability_efficacy_group_id"]
        abilityEfficacyGroupId = abilityEfficacyGroupId if abilityEfficacyGroupId is not None else 0
        coolTimeMillisecond = md_ability_efficacy["cool_time_millisecond"]
        effectCoolTimeMillisecond = md_ability_efficacy["effect_cool_time_millisecond"]
        activeTimeMillisecond = md_ability_efficacy["active_time_millisecond"]
        efficacyType = md_ability_efficacy["efficacy_type"]
        probability = md_ability_efficacy["probability"]
        activateConditions = md_ability_efficacy["activate_conditions"]
        deactivateConditions = md_ability_efficacy["deactivate_conditions"]
        sustainConditions = md_ability_efficacy["sustain_conditions"]
        targetConditions = md_ability_efficacy["target_conditions"]
        fValues = md_ability_efficacy["f_values"]
        values = md_ability_efficacy["values"]
        uiViewPriority = md_ability_efficacy["ui_view_priority"]
        effectValueSteps = md_ability_efficacy["effect_value_steps"]
        targetType = md_ability_efficacy["target_type"]

        row = (
            abilityEfficacyId, abilityEfficacyGroupId, coolTimeMillisecond,
            effectCoolTimeMillisecond, activeTimeMillisecond, efficacyType,
            probability, activateConditions, deactivateConditions, sustainConditions,
            targetConditions, fValues, values, uiViewPriority, effectValueSteps, targetType
        )

        row = map(convert_to_sql, row)
        row = list(row)

        if first:
            first = False
        else:
            f.write(",")

        line = ", ".join(row)
        line = f"({line})"

        xprint(line)

    xprint(";")


def gen_md_ability_tension_card(md_ability_tension_card_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdAbilityTensionCard (abilityTensionCardId, abilities) VALUES")

    first = True
    for md_ability_tension_card in md_ability_tension_card_json:
        ability_tension_card_id = md_ability_tension_card["id"]
        abilities = json.dumps(md_ability_tension_card["abilities"])

        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({ability_tension_card_id}, '{abilities}')")

    xprint(";")


def gen_md_tension_card(md_tension_card_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdTensionCard (tensionCardId, abilityTensionCardId) VALUES")

    first = True
    for md_tension_card in md_tension_card_json:
        tension_card_id = md_tension_card["id"]
        ability_tension_card_id = md_tension_card["ability_tension_card_id"]

        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({tension_card_id}, {ability_tension_card_id})")

    xprint(";")


if __name__ == "__main__":
    main()