from argparse import ArgumentParser
from functools import partial
import json
import sys
import itertools

from dump_semba_logs import get_debug_logs

def main():
    parser = ArgumentParser()
    parser.add_argument("semba_db")
    parser.add_argument("output_sql")
    args = parser.parse_args()

    debug_logs = get_debug_logs(args.semba_db)

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

            
    for battle_parameter in itertools.chain.from_iterable(all_battle_parameters):
        if first:
            first = False
        else:
            f.write(", ") 
        printf(f"({battle_parameter["id"]}, '{json.dumps(battle_parameter["enemies"])}')")
    
    printf(";")


if __name__ == "__main__":
    main()