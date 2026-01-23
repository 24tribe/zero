from argparse import ArgumentParser
import json

def main():
    parser = ArgumentParser()
    parser.add_argument("online_logs_json")
    parser.add_argument("out_sql")
    args = parser.parse_args()

    with open(args.online_logs_json, "r", encoding="utf-8") as f:
        online_logs = json.load(f)

    battle_pairs = get_battle_pairs(online_logs)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        write_battle_finish_area_objects_sql(battle_pairs, f)

# TODO: why the battle entry id 1000004 isn't here?
def write_battle_finish_area_objects_sql(battle_pairs, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO battleFinishAreaObjects (battleEntryId, areaObjects) VALUES")

    first = True
    for battle_start, battle_finish in battle_pairs:
        assert battle_start is not None
        assert battle_finish is not None
        area_objects = battle_finish["res"].get("areaObjects", [])
        if area_objects:
            battle_entry_id = battle_start["req"]["battleEntryIds"][0]
            if first:
                first = False
            else:
                f.write(",")
                xprint(f"({battle_entry_id}, '{json.dumps(area_objects)}')")

    xprint(";")


"""
Returns the battle_start/battle_finish pairs found in the online logs
"""
def get_battle_pairs(online_logs):
    battle_start = None

    result = []

    for i, log in enumerate(online_logs):
        if log["uri"] == "/battle/start":
            battle_start = log
        elif log["uri"] == "/battle/finish":
            if battle_start is not None:
                result.append((battle_start, log))
                battle_start = None

    return result


if __name__ == "__main__":
    main()