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
    printf("INSERT INTO tensionCards (tensionCardId, receivedAt, maxLevel, abilityEfficacies, trainingScoreLevelScore, entityId, isLocked)") 
    printf("VALUES")

    first = True
    for tc in data["resources"]["tensionCards"]:
        if first:
            first = False
        else:
            f.write(",")

        printf(f"({tc["tensionCardId"]}, '{tc["receivedAt"]}', {tc["maxLevel"]}, '{json.dumps(tc["abilityEfficacies"])}', {tc["trainingScoreLevelScore"]}, {tc["entityId"]}, {"true" if tc["isLocked"] else "false"})")

    printf(";")

    printf("INSERT INTO challengeProgresses (challengeProgressId, clearedAt, state)")
    printf("VALUES")

    first = True
    for prog in data["resources"]['challengeProgresses']:
        if first:
            first = False
        else:
            f.write(",")

        print(prog)
        printf(f"({prog["challengeProgressId"]}, '{prog["clearedAt"] if "clearedAt" in prog else ""}', {prog["state"]})")
    
    printf(";")

if __name__ == "__main__":
    main()