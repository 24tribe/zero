from argparse import ArgumentParser
import json
import sys

def main():
    parser = ArgumentParser()
    parser.add_argument("response_json")
    parser.add_argument("area_id", type=int)
    parser.add_argument("output_sql")
    args = parser.parse_args()

    with open(args.response_json, "r", encoding="utf-8") as f:
        data = json.load(f)

    with open(args.output_sql, "w", encoding="utf-8") as f:
        write_sql(f, data, args.area_id)

def write_sql(f, data, area_id):
    # enemies
    print("INSERT INTO areaEnemies (areaId, areaPointId, areaEnemyRateSetId, action)", file=f)
    print("VALUES", file=f)
    first = True
    for obj in data["areaObjects"]:
        if "areaEnemyRateSetId" in obj:
            if first:
                first = False
            else:
                f.write(",")

            print(f"({area_id}, {obj["areaPointId"]}, {obj["areaEnemyRateSetId"]}, '{json.dumps(obj["action"])}')", file=f)
    print(";", file=f)

    # interactive? objects
    print("INSERT INTO areaObjects (areaId, areaObjectId, areaPointId, areaObjectBehaviorId, action)", file=f)
    print("VALUES", file=f)
    first = True
    for obj in data["areaObjects"]:
        if "areaObjectId" in obj:
            if first:
                first = False
            else:
                f.write(",")

            print(f"({area_id}, {obj["areaObjectId"]}, {obj["areaPointId"]}, {obj["areaObjectBehaviorId"]}, '{json.dumps(obj["action"])}')", file=f)
    print(";", file=f)
    

if __name__ == "__main__":
    main()