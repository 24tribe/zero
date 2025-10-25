from argparse import ArgumentParser
import sqlite3
import re
import json
import sys

def get_offline_debug_logs(semba_db):
    con = sqlite3.connect(semba_db)

    cur = con.cursor()

    res = cur.execute("SELECT receivedAt, uri, req, res FROM debugLogsOffline")
    data = res.fetchall()

    result = []

    for receivedAt, uri, req, res in data:
        result.append({
            "receivedAt": receivedAt,
            "uri": uri,
            "req": json.loads(req) if req != "" else None,
            "res": json.loads(res) if res != "" else None
        })

    return result

def main():
    parser = ArgumentParser()
    parser.add_argument("semba_db")
    parser.add_argument("save_file")
    args = parser.parse_args()

    reqs = [[debug_log["uri"], debug_log["req"]] for debug_log in get_offline_debug_logs(args.semba_db)]

    save = {"version": 1, "reqs": reqs}
    
    with open(args.save_file, "w", encoding="utf-8") as f:
        json.dump(save, f)

    print("OK")
             
if __name__ == "__main__":
    main()