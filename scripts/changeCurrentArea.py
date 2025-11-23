from pathlib import Path
from argparse import ArgumentParser
import sqlite3
import sys
import json

def main():
    parser = ArgumentParser()
    parser.add_argument("semba_db")
    parser.add_argument("area_id", type=int)
    args = parser.parse_args()

    semba_db = Path(args.semba_db)

    if not semba_db.exists():
        print(f"error: semba_db '{semba_db}' doesn't exists", file=sys.stderr)
        sys.exit(1)

    con = sqlite3.connect(semba_db)
    cur = con.cursor()
    res = cur.execute("SELECT val FROM userData WHERE keyName='status'")
    status = res.fetchone()[0]
    status = json.loads(status)
    last_area_id = status["currentAreaKeyId"]
    status["currentAreaKeyId"] = args.area_id
    status = json.dumps(status)
    cur.execute("UPDATE userData SET val=? WHERE keyName='status'", (status, ))
    con.commit()
    print(f"OK, changed from {last_area_id} to {args.area_id}")

if __name__ == "__main__":
    main()