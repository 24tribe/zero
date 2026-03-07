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

    with open(args.masterdata_dir/"flower_mark_level.json", "r", encoding="utf-8") as f:
        md_flower_mark_level_json = json.load(f)

    with open(args.masterdata_dir/"battle_entry.json", "r", encoding="utf-8") as f:
        md_battle_entry_json = json.load(f)

    with open(args.masterdata_dir/"battle_parameter.json", "r", encoding="utf-8") as f:
        md_battle_parameter_json = json.load(f)

    with open(args.masterdata_dir/"battle_wave.json", "r", encoding="utf-8") as f:
        md_battle_wave_json = json.load(f)

    with open(args.masterdata_dir/"enemy_level.json", "r", encoding="utf-8") as f:
        md_enemy_level_json = json.load(f)

    with open(args.masterdata_dir/"enemy.json", "r", encoding="utf-8") as f:
        md_enemy_json = json.load(f)

    with open(args.masterdata_dir/"battle_enemy.json", "r", encoding="utf-8") as f:
        md_battle_enemy_json = json.load(f)
    
    with open(args.masterdata_dir/"character_level.json", "r", encoding="utf-8") as f:
        md_character_level = json.load(f)

    with open(args.masterdata_dir/"item.json", "r", encoding="utf-8") as f:
        md_item = json.load(f)

    with open(args.masterdata_dir/"rated_reward_set.json", "r", encoding="utf-8") as f:
        md_rated_reward_set = json.load(f)

    with open(args.masterdata_dir/"dungeon_difficulty.json", "r", encoding="utf-8") as f:
        md_dungeon_difficulty_json = json.load(f)

    with open(args.masterdata_dir/"dungeon_enemy_rate.json", "r", encoding="utf-8") as f:
        md_dungeon_enemy_rate_json = json.load(f)

    with open(args.masterdata_dir/"challenge_task.json", "r", encoding="utf-8") as f:
        md_challenge_task_json = json.load(f)

    with open(args.masterdata_dir/"area_object_behavior.json", "r", encoding="utf-8") as f:
        md_area_object_behavior_json = json.load(f)

    with open(args.masterdata_dir/"challenge_route.json", "r", encoding="utf-8") as f:
        md_challenge_route_json = json.load(f)

    with open(args.masterdata_dir/"sequence_request.json", "r", encoding="utf-8") as f:
        md_sequence_request_json = json.load(f)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        gen_md_tension_card(md_tension_card_json, f)
        gen_md_ability_tension_card(md_ability_tension_card_json, f)
        gen_md_ability_efficacy(md_ability_efficacy_json, f)
        gen_md_area_change_lock(md_area_change_lock_json, f)
        gen_md_flower_mark_level(md_flower_mark_level_json, f)
        gen_md_battle_entry(md_battle_entry_json, f)
        gen_md_battle_parameter(md_battle_parameter_json, f)
        gen_md_battle_wave(md_battle_wave_json, f)
        gen_md_enemy_level(md_enemy_level_json, f)
        gen_md_enemy(md_enemy_json, f)
        gen_md_battle_enemy(md_battle_enemy_json, f)
        gen_md_character_level(md_character_level, f)
        gen_md_item(md_item, f)
        gen_md_rated_reward_set(md_rated_reward_set, f)
        gen_md_dungeon_difficulty(md_dungeon_difficulty_json, f)
        gen_md_dungeon_enemy_rate(md_dungeon_enemy_rate_json, f)
        gen_md_challenge_task(md_challenge_task_json, f)
        gen_md_area_object_behavior(md_area_object_behavior_json, f)
        gen_md_challenge_route_json(md_challenge_route_json, f)
        gen_md_sequence_request_json(md_sequence_request_json, f)


def gen_md_sequence_request_json(md_sequence_request_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("""
INSERT INTO mdSequenceRequest (
    adventureVariableId, areaChangeLockId, areaGroupId, areaId,
    areaObjectId, areaObjectState, cityId, costs, eventLiftId,
    id, rewards, type, variableChangeValue, variableOperator
) VALUES
""")

    write_rows(xprint, f, [
        (seqreq["adventure_variable_id"],
        seqreq["area_change_lock_id"],
        seqreq["area_group_id"],
        seqreq["area_id"],
        seqreq["area_object_id"],
        seqreq["area_object_state"],
        seqreq["city_id"],
        seqreq["costs"],
        seqreq["event_lift_id"],
        seqreq["id"],
        seqreq["rewards"],
        seqreq["type"],
        seqreq["variable_change_value"],
        seqreq["variable_operator"]) for seqreq in md_sequence_request_json
    ])

    xprint(";")


def gen_md_challenge_route_json(md_challenge_route_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdChallengeRoute (currentProgressId, id, nextProgressId) VALUES")

    write_rows(xprint, f, [
        (challenge_route["current_progress_id"], challenge_route["id"], challenge_route["next_progress_id"])
        for challenge_route in md_challenge_route_json
    ])

    xprint(";")


def write_rows(xprint, f, rows):
    first = True
    for row in rows:
        content = ", ".join(map(convert_to_sql, row))
        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({content})")


def gen_md_area_object_behavior(md_area_object_behavior_json, f):
    xprint = lambda *args: print(*args, file=f)

    area_object_behaviors = []
    area_object_behavior_actions = []
    area_object_behavior_conditions = []

    for area_object_behavior in md_area_object_behavior_json:
        aob_row = (
            area_object_behavior["area_object_id"],
            area_object_behavior["area_point_id"],
            area_object_behavior["challenge_progress_id"],
            area_object_behavior["id"],
        )

        area_object_behaviors.append(aob_row)

        if area_object_behavior["action"] is not None:
            action_label = area_object_behavior["action"].get("label")
            aob_action_row = (
                area_object_behavior["id"],
                area_object_behavior["action"]["area_enemy_id"],
                area_object_behavior["action"]["area_item_id"],
                area_object_behavior["action"]["battle_entry_id"],
                area_object_behavior["action"]["dungeon_id"],
                area_object_behavior["action"]["event_lift_id"],
                area_object_behavior["action"]["field_boss_id"],
                area_object_behavior["action"]["graffiti_art_id"],
                area_object_behavior["action"]["id"],
                action_label["en"] if action_label else None,
                area_object_behavior["action"]["sequence_id"],
                area_object_behavior["action"]["sequence_request_id"],
                area_object_behavior["action"]["type"],
                area_object_behavior["action"]["warp_point_id"],
            )

            area_object_behavior_actions.append(aob_action_row)

        if area_object_behavior["condition"] is not None:
            aob_condition_row = (
                area_object_behavior["id"],
                area_object_behavior["condition"]["area_object_id"],
                area_object_behavior["condition"]["area_object_state"],
                area_object_behavior["condition"]["id"],
                area_object_behavior["condition"]["type"],
            )

            area_object_behavior_conditions.append(aob_condition_row)

    xprint("""
INSERT INTO mdAreaObjectBehavior (areaObjectId, areaPointId, challengeProgressId, id)
VALUES
""")

    write_rows(xprint, f, area_object_behaviors)

    xprint(";")

    xprint("""
INSERT INTO mdAreaObjectBehaviorAction
(areaObjectBehaviorId, areaEnemyId, areaItemId, battleEntryId,
 dungeonId, eventLiftId, fieldBossId, graffitiArtId, id, label_en,
 sequenceId, sequenceRequestId, type, warpPointId)
VALUES
""")

    write_rows(xprint, f, area_object_behavior_actions)

    xprint(";")

    xprint("""
INSERT INTO mdAreaObjectBehaviorCondition
(areaObjectBehaviorId, areaObjectId, areaObjectState, id, type)
VALUES
""")

    write_rows(xprint, f, area_object_behavior_conditions)

    xprint(";")


def gen_md_challenge_task(md_challenge_task_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("""
INSERT INTO mdChallengeTask
(challengeProgressId, count, id, summaryChallengeId,
 targetAreaObjectBehaviorId, targetAreaPointId, targetNineSequenceId,
 targetRadius, taskConditionKeyId, taskConditionType, totalTaskConditionId)
VALUES
""")

    first = True

    for challenge_task in md_challenge_task_json:
        task_condition = challenge_task["task_condition"]
        row = (
            challenge_task["challenge_progress_id"],
            challenge_task["count"],
            challenge_task["id"],
            challenge_task["summary_challenge_id"],
            challenge_task["target_area_object_behavior_id"],
            challenge_task["target_area_point_id"],
            challenge_task["target_nine_sequence_id"],
            challenge_task["target_radius"],
            task_condition["key_id"] if task_condition is not None else None,
            task_condition["type"] if task_condition is not None else None,
            challenge_task["total_task_condition_id"]
        )

        content = ", ".join(map(convert_to_sql, row))

        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({content})")

    xprint(";")


def gen_md_dungeon_enemy_rate(md_dungeon_enemy_rate_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("""
INSERT INTO mdDungeonEnemyRate
(id, dungeonEnemyRateSetId, areaEnemyId, battleEntryId)
VALUES
""")

    first = True

    for dungeon_enemy_rate in md_dungeon_enemy_rate_json:
        row = (
            dungeon_enemy_rate["id"],
            dungeon_enemy_rate["dungeon_enemy_rate_set_id"],
            dungeon_enemy_rate["area_enemy_id"],
            dungeon_enemy_rate["battle_entry_id"],
        )

        content = ", ".join(map(convert_to_sql, row))

        if first:
            first = False
        else:
            f.write(", ")

        xprint(f"({content})")

    xprint(";")


def gen_md_dungeon_difficulty(md_dungeon_difficulty_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("""
INSERT INTO mdDungeonDifficulty
(id, bonusRatedRewardSetIds, bossRatedRewardSetIds, enemyLevel, enemyTrainingScoreId, goalEnemyRateSetId)
VALUES
""")

    first = True

    for dungeon_difficulty in md_dungeon_difficulty_json:
        row = (
            dungeon_difficulty["id"],
            dungeon_difficulty["bonus_rated_reward_set_ids"],
            dungeon_difficulty["boss_rated_reward_set_ids"],
            dungeon_difficulty["enemy_level"],
            dungeon_difficulty["enemy_training_score_id"],
            dungeon_difficulty["goal_enemy_rate_set_id"]
        )

        content = ", ".join(map(convert_to_sql, row))

        if first:
            first = False
        else:
            f.write(", ")

        xprint(f"({content})")

    xprint(";")


def gen_md_rated_reward_set(md_rated_reward_set, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdRatedRewardSet (id, rewardId, rewardQuantity, rewardType) VALUES")

    first = True

    for rated_reward_set in md_rated_reward_set:
        id_ = rated_reward_set["id"]
        for reward in rated_reward_set["rewards"]:
            row = (id_, reward["id"], reward["quantity"], reward["type"])
            content = ", ".join(map(convert_to_sql, row))
            if first:
                first = False
            else:
                f.write(", ")

            xprint(f"({content})")

    xprint(";")


def gen_md_item(md_item, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdItem (id, itemType, maxQuantity, rarity, soldGold, value) VALUES")

    first = True

    for item in md_item:
        row = (
            item["id"],
            item["item_type"],
            item["max_quantity"],
            item["rarity"],
            str(item["sold_gold"]) if item["sold_gold"] is not None else "",
            item["value"],
        )

        content = ", ".join(map(convert_to_sql, row))

        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({content})")

    xprint(";")


def gen_md_character_level(md_character_level, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdCharacterLevel (level, exp, statusFactor) VALUES")

    first = True

    for character_level in md_character_level:
        level = character_level["level"]
        exp = character_level["exp"]
        status_factor = character_level["status_factor"]

        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({level}, {exp}, {status_factor})")

    xprint(";")


def gen_md_battle_enemy(md_battle_enemy_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdBattleEnemy (id, enemyId) VALUES")

    first = True

    for battle_enemy in md_battle_enemy_json:
        battle_enemy_id = battle_enemy["id"]
        enemy_id = battle_enemy["enemy_id"]

        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({battle_enemy_id}, {enemy_id})")

    xprint(";")


def gen_md_enemy(md_enemy_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdEnemy (id, dropExp, attack, defense, hp) VALUES")

    first = True

    for enemy in md_enemy_json:
        enemy_id = enemy["id"]
        drop_exp = enemy["drop_exp"]
        attack = enemy["attack"]
        defense = enemy["defense"]
        hp = enemy["hp"]

        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({enemy_id}, {drop_exp}, {attack}, {defense}, {hp})")

    xprint(";")

def gen_md_enemy_level(md_enemy_level_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdEnemyLevel (level, dropExpFactor, atkStatusFactor, defStatusFactor, hpStatusFactor) VALUES")

    first = True
    for enemy_level in md_enemy_level_json:
        level = enemy_level["level"]
        drop_exp_factor = enemy_level["drop_exp_factor"]
        atk_status_factor = enemy_level["atk_status_factor"]
        def_status_factor = enemy_level["def_status_factor"]
        hp_status_factor = enemy_level["hp_status_factor"]
        if first:
            first = False
        else:
            f.write(",")
        xprint(f"({level}, {drop_exp_factor}, {atk_status_factor}, {def_status_factor}, {hp_status_factor})")

    xprint(";")


def gen_md_battle_wave(md_battle_wave_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdBattleWave (id, battleEnemyId) VALUES")
    first = True
    for battle_wave in md_battle_wave_json:
        battle_wave_id = battle_wave["id"]
        for battle_enemy_id in battle_wave["enemies"]:
            if first:
                first = False
            else:
                f.write(",")

            xprint(f"({battle_wave_id}, {battle_enemy_id})")

    xprint(";")


def gen_md_battle_parameter(md_battle_parameter_json, f):
    xprint = lambda *args: print(*args, file=f)

    battle_parameters = []
    battle_parameter_waves = []

    for battle_parameter in md_battle_parameter_json:
        battle_parameter_id = battle_parameter["id"]
        drop_exp_factor = battle_parameter["drop_exp_factor"]
        battle_parameters.append((battle_parameter_id, drop_exp_factor))
        for battle_wave_id in battle_parameter["enemy_waves"]:
            battle_parameter_waves.append((battle_parameter_id, battle_wave_id))

    xprint("INSERT INTO mdBattleParameter (id, dropExpFactor) VALUES")
    first = True
    for battle_parameter_id, drop_exp_factor in battle_parameters:
        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({battle_parameter_id}, {drop_exp_factor})")
    xprint(";\n")

    xprint("INSERT INTO mdBattleParameterWave (battleParameterId, battleWaveId) VALUES")
    first = True
    for battle_parameter_id, battle_wave_id in battle_parameter_waves:
        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({battle_parameter_id}, {battle_wave_id})")

    xprint(";")

def gen_md_battle_entry(md_battle_entry_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdBattleEntry (id, enemyLevel, battleParameterId) VALUES")

    first = True
    for battle_entry in md_battle_entry_json:
        battle_entry_id = battle_entry["id"]
        enemy_level = battle_entry["enemy_level"]
        battle_parameter_id = battle_entry["battle_parameter_id"]

        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({battle_entry_id}, {enemy_level}, {battle_parameter_id})")

    xprint(";")


def gen_md_flower_mark_level(md_flower_mark_level_json, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO mdFlowerMarkLevel (requiredFlowerMark, characterMaxLevel) VALUES")

    first = True
    for flower_mark_level in md_flower_mark_level_json:
        required_flower_mark = flower_mark_level["required_flower_mark"]
        character_max_level = flower_mark_level["character_max_level"]

        if character_max_level is not None:
            if first:
                first = False
            else:
                f.write(",")
            xprint(f"({required_flower_mark}, {character_max_level})")

    xprint(";")


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
        val = val.replace("'", "''")
        return f"'{val}'"
    elif isinstance(val, (dict, list)):
        return f"'{json.dumps(val)}'"
    elif val is None:
        return "null"
    else:
        print(f"bad val: {repr(val)}")
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