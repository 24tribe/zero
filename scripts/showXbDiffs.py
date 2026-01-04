from argparse import ArgumentParser
from tempfile import TemporaryDirectory
import json
import sqlite3
import subprocess

import jsondiff as jd

def main():
    parser = ArgumentParser()
    parser.add_argument("semba_exe")
    parser.add_argument("semba_sql")
    parser.add_argument("online_logs_json")
    parser.add_argument("--count", type=int)
    args = parser.parse_args()

    with open(args.online_logs_json, "r", encoding="utf-8") as f:
        online_logs = json.load(f)

    with TemporaryDirectory() as temp_dir:
        semba_db = f"{temp_dir}/semba.db"
        recreate_semba_db(args.semba_sql, semba_db)
        show_xb_diffs(online_logs, semba_db, args.semba_exe, args.count)

def recreate_semba_db(semba_sql, filename):
    with open(semba_sql, "r", encoding="utf-8") as f:
        content = f.read()

    con = sqlite3.connect(filename)

    cur = con.cursor()
    cur.executescript(content)
    
    con.commit()
    con.close()

def semba_call(semba_exe, semba_db, uri, req):
    content = subprocess.check_output([semba_exe, semba_db, uri, json.dumps(req)]).decode("utf-8")
    try:
        return json.loads(content)
    except json.JSONDecodeError:
        print(content)
        raise

def is_xb_log(online_log):
    xb_uris = set(("/xb/start", "/xb/update_tension", "/xb/play"))
    return (
        online_log["uri"] in xb_uris
        and online_log["req"]["xbId"] == 10001
    )

def show_xb_diffs(online_logs, semba_db, semba_exe, count):
    xb_logs = list(filter(is_xb_log, online_logs))

    if count is None:
        count = len(xb_logs)

    for _, online_log in zip(range(count), xb_logs):
        print("uri: ", online_log["uri"])
        print("req: ", online_log["req"])

        res = semba_call(semba_exe, semba_db, online_log["uri"], online_log["req"])

        diff = jd.diff(res, online_log["res"], marshal=True, syntax="explicit")
        if diff == {}:
            print("OK: diff == {}")
        else:
            print("NOT OK!!")
            print(json.dumps(diff, indent=2))

        print("===========================================")

if __name__ == "__main__":
    main()