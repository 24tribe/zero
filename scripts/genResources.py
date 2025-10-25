from argparse import ArgumentParser
from functools import partial
import json
import sys

def main():
    parser = ArgumentParser()
    parser.add_argument("user_login_response_json")
    parser.add_argument("output_sql")
    args = parser.parse_args()

    with open(args.user_login_response_json, "r", encoding="utf-8") as f:
        data = json.load(f)

    with open(args.output_sql, "w", encoding="utf-8") as f:
        write_sql(f, data)

def write_sql(f, data):
    printf = partial(print, file=f)

    gen_tension_cards(printf, f, data)
    gen_challenge_progresses(printf, f, data)
    gen_tips(printf, f, data)
    gen_total_tasks(printf, f, data)
    gen_tutorial_states(printf, f, data)
    gen_shop_products(printf, f, data)
    gen_characters(printf, f, data)

def gen_characters(printf, f, data):
    printf("""
INSERT INTO characters
(characterId, exp, hp, attack, defense, maxHp, receivedAt, characterOwnershipType,
criticalRate, criticalDamageRate, movementSpeed, damageInflictedRate, tensionIncreaseRate,
cpRecastRate, spGaugeIncreaseRate, attackSpeed, characterCostumeId, abnormalityParamSet,
trainingScoreLevelScore, trainingScoreRankScore, actionPointMax,
actionPointRate, actionPointConsumption, damageTakenRate)
VALUES
""")
    first = True
    for c in data["resources"]['characters']:
        if first:
            first = False
        else:
            f.write(",")

        f.write("(")
        f.write(f"{c["characterId"]}, ")
        printf("""240, 511, 106, 105, 511, "2025-09-10T02:22:51Z", 1,
5, 50, 6, 100, 100,
100, 100, 100, 1001001, '{"oily": {"burstResistance": 100, "burstResistanceLimit": 100}, "pressure": {"burstResistance": 100, "burstResistanceLimit": 100}, "scared": {"burstResistance": 100, "burstResistanceLimit": 100}, "electric": {"burstResistance": 100, "burstResistanceLimit": 100}, "unfortified": {"burstResistance": 100, "burstResistanceLimit": 100}}',
2, 1, 1000,
3000, 160, 1)""")
    
    printf(";")

def gen_shop_products(printf, f, data):
    printf("INSERT INTO shopProducts (val)")
    printf("VALUES")

    first = True
    for sp in data["masterData"]['shopProducts']:
        if first:
            first = False
        else:
            f.write(",")

        printf(f"('{json.dumps(sp)}')")
    
    printf(";")

def gen_tutorial_states(printf, f, data):
    printf("INSERT INTO tutorialStates (tutorialStatusKey, enabled)")
    printf("VALUES")

    first = True
    for ts in data["resources"]['tutorialStates']:
        if first:
            first = False
        else:
            f.write(",")

        if "enabled" in ts:
            if ts["enabled"]:
                enabled = "true"
            else:
                enabled = "false"
        else:
            enabled = ""

        printf(f"({ts["tutorialStatusKey"]}, '{enabled}')")
    
    printf(";")

def gen_tips(printf, f, data):
    printf("INSERT INTO tips (tipId, releasedAt)")
    printf("VALUES")

    first = True
    for tip in data["resources"]['tips']:
        if first:
            first = False
        else:
            f.write(",")

        printf(f"({tip["tipId"]}, '{tip["releasedAt"]}')")
    
    printf(";")

def gen_total_tasks(printf, f, data):
    printf("INSERT INTO totalTasks (conditionId)")
    printf("VALUES")
    
    first = True
    for total_task in data["resources"]['totalTasks']:
        if first:
            first = False
        else:
            f.write(",")

        printf(f"({total_task["conditionId"]})")
    
    printf(";")

def gen_challenge_progresses(printf, f, data):
    printf("INSERT INTO challengeProgresses (challengeProgressId, clearedAt, state)")
    printf("VALUES")

    first = True
    for prog in data["resources"]['challengeProgresses']:
        if first:
            first = False
        else:
            f.write(",")

        printf(f"({prog["challengeProgressId"]}, '{prog["clearedAt"] if "clearedAt" in prog else ""}', {prog["state"]})")
    
    printf(";")

def gen_tension_cards(printf, f, data):
    printf("INSERT INTO tensionCards (tensionCardId, receivedAt, maxLevel, abilityEfficacies, trainingScoreLevelScore, entityId, isLocked)") 
    printf("VALUES")

    first = True
    for tc in data["resources"]["tensionCards"]:
        if first:
            first = False
        else:
            f.write(",")

        printf(f"({tc["tensionCardId"]}, '{tc["receivedAt"]}', {tc["maxLevel"]}, '{json.dumps(tc["abilityEfficacies"])}', {tc["trainingScoreLevelScore"]}, {tc["entityId"]}, {"true" if "isLocked" in tc and tc["isLocked"] else "false"})")

    printf(";")

if __name__ == "__main__":
    main()