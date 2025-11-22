from argparse import ArgumentParser
from pathlib import Path
import sys
import itertools
import sqlite3
import json
import re

from dumpSembaLogs import get_debug_logs

alphanum = re.compile(r"\w")

def censor(online_log):
    if online_log["uri"] == "/auth/sign_up":
        online_log["req"]["deviceSecret"] = alphanum.sub("F", online_log["req"]["deviceSecret"])
        online_log["req"]["deviceUniqueId"] = alphanum.sub("F", online_log["req"]["deviceUniqueId"])
        online_log["req"]["deviceModel"] = "PC"
    elif online_log["uri"] == "/auth/sign_up_google":
        online_log["req"]["deviceSecret"] = alphanum.sub("F", online_log["req"]["deviceSecret"])
        online_log["req"]["deviceUniqueId"] = alphanum.sub("F", online_log["req"]["deviceUniqueId"])
        online_log["req"]["deviceModel"] = "PC"
        online_log["req"]["code"] = alphanum.sub("F", online_log["req"]["code"])
        online_log["req"]["codeVerifier"] = alphanum.sub("F", online_log["req"]["codeVerifier"])
    elif online_log["uri"] == "/user/link_google":
        online_log["req"]["code"] = alphanum.sub("F", online_log["req"]["code"])
        online_log["req"]["codeVerifier"] = alphanum.sub("F", online_log["req"]["codeVerifier"])

    return online_log

def main():
    parser = ArgumentParser()
    parser.add_argument("semba_db", nargs="+")
    parser.add_argument("out_db")
    args = parser.parse_args()
    out_db_path = Path(args.out_db)

    if out_db_path.exists():
        print(f"error: {out_db_path} exists", file=sys.stderr)
        sys.exit(1)

    online_logs = []

    for semba_db_path in args.semba_db:
        online_logs += get_debug_logs(semba_db_path)

    online_logs.sort(key=lambda x: x["receivedAt"])
    online_logs = [censor(x) for x in online_logs]

    with open("onlineLogs.sql", "r", encoding="utf-8") as f:
        schema = f.read()

    online_logs_dump = [
        (x["receivedAt"], x["uri"], json.dumps(x["req"]), json.dumps(x["res"])) for x in online_logs
    ]

    con = sqlite3.connect(out_db_path)
    cur = con.cursor()
    cur.executescript(schema)
    cur.executemany("""
        INSERT INTO debugLogs (receivedAt, uri, req, res)
        VALUES (?, ?, ?, ?)
    """, online_logs_dump)

    con.commit()

    print("OK")

if __name__ == "__main__":
    main()