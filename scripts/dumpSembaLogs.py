from argparse import ArgumentParser
import sqlite3
import re
import json
import sys

def get_debug_logs(semba_db):
    con = sqlite3.connect(semba_db)

    cur = con.cursor()

    res = cur.execute("SELECT receivedAt, uri, req, res FROM debugLogs")
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
    parser.add_argument("semba_db", nargs="+")
    args = parser.parse_args()

    debug_logs = []

    for semba_db in args.semba_db:
        debug_logs += get_debug_logs(semba_db)
        
    json.dump(debug_logs, sys.stdout)
             
if __name__ == "__main__":
    main()