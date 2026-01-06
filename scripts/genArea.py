from argparse import ArgumentParser
from functools import partial
import json

def main():
    parser = ArgumentParser()
    parser.add_argument("online_logs_json")
    parser.add_argument("out_sql")

    args = parser.parse_args()

    with open(args.online_logs_json, "r", encoding="utf-8") as f:
        debug_logs = json.load(f)

    first_move_to_area = get_first_move_to_area(debug_logs)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        write_bgm_area_sql(first_move_to_area, f)

def write_bgm_area_sql(first_move_to_area, f):
    printf = partial(print, file=f)

    printf("INSERT INTO areaBgm (areaId, id, eventName) VALUES")

    first = True

    for debug_log in first_move_to_area:
        if first:
            first = False
        else:
            f.write(", ")

        areaId = debug_log["req"]["areaId"]
        areaBgmId = debug_log["res"]["areaBgm"]["id"]
        eventName = debug_log["res"]["areaBgm"].get("eventName", "")

        printf(f"({areaId}, {areaBgmId}, '{eventName}')")
 
    printf(";")

def get_first_move_to_area(debug_logs):
    area_ids = set()
    move_to_area = filter(lambda debug_log: debug_log["uri"] == "/adventure/move_to_area", debug_logs)
    result = []

    for debug_log in move_to_area:
        area_id = debug_log["req"]["areaId"]
        if area_id not in area_ids:
            area_ids.add(area_id)
            result.append(debug_log)

    return result

if __name__ == "__main__":
    main()