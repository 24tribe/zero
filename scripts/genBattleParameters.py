from argparse import ArgumentParser
from functools import partial
import json
import sys
import itertools

def main():
    parser = ArgumentParser()
    parser.add_argument("online_logs_json")
    parser.add_argument("output_sql")
    args = parser.parse_args()

    with open(args.online_logs_json, "r", encoding="utf-8") as f:
        debug_logs = json.load(f)

    with open(args.output_sql, "w", encoding="utf-8") as f:
        write_sql(debug_logs, f)

def write_sql(debug_logs, f):
    printf = partial(print, file=f)

    printf("INSERT INTO battleParameters (id, enemies) VALUES ")

    all_battle_parameters = []

    first = True
    for debug_log in debug_logs:
        if debug_log["uri"] == "/battle/start":
            battle_parameters = debug_log["res"]["battleParameters"]

            all_battle_parameters.append(battle_parameters)

    seen_ids = set()
            
    for battle_parameter in itertools.chain.from_iterable(all_battle_parameters):
        if battle_parameter["id"] in seen_ids:
            continue

        seen_ids.add(battle_parameter["id"])

        if first:
            first = False
        else:
            f.write(", ") 
        printf(f"({battle_parameter["id"]}, '{json.dumps(battle_parameter["enemies"])}')")
    
    printf(";")


if __name__ == "__main__":
    main()