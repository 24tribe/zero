from argparse import ArgumentParser
import sqlite3
import re
import json
import sys

def main():
    parser = ArgumentParser()
    parser.add_argument("semba_db")
    args = parser.parse_args()

    con = sqlite3.connect(args.semba_db)

    cur = con.cursor()

    res = cur.execute("SELECT receivedAt, uri, req, res FROM debugLogs")
    data = res.fetchall()

    result = []

    for receivedAt, uri, req, res in data:
        result.append({
            "receivedAt": receivedAt,
            "uri": uri,
            "req": req,
            "res": res
        })

    json.dump(result, sys.stdout)
             
if __name__ == "__main__":
    main()