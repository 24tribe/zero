from argparse import ArgumentParser
from collections import defaultdict
import json

def main():
    parser = ArgumentParser()
    parser.add_argument("online_logs_json")
    parser.add_argument("out_sql")
    args = parser.parse_args()

    with open(args.online_logs_json, "r", encoding="utf-8") as f:
        online_logs = json.load(f)

    xb_start_logs = filter(lambda x: x["uri"] == "/xb/start", online_logs)
    xb_start_logs = list(xb_start_logs)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        write_sql(xb_start_logs, f)

def write_sql(xb_start_logs, f):
    xprint = lambda *args: print(*args, file=f)
    xprint("INSERT INTO xbStartGameInfos (xbId, content) VALUES")
    first = True
    for xb_start_log in xb_start_logs:
        if first:
            first = False
        else:
            f.write(", ")

        xbId = xb_start_log["req"]["xbId"]
        gameInfo = xb_start_log["res"]["nextAtBatGameInfo"]

        xprint(f"({xbId}, '{json.dumps(gameInfo)}')")

    xprint(";")


if __name__ == "__main__":
    main()