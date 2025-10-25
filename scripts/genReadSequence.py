from argparse import ArgumentParser
from functools import partial
import json
import sys

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

    printf("INSERT INTO readSequence (sequenceRequestId, areaObjects, changedResources) VALUES ")

    first = True
    for debug_log in debug_logs:
        if debug_log["uri"] == "/adventure/read_sequence":
            if first:
                first = False
            else:
                f.write(", ") 

            seqReqId = debug_log["req"]["sequenceRequestIds"][0]
            changedResources = debug_log["res"]["changedResources"]
            areaObjects = debug_log["res"]["areaObjects"]

            printf(f"({seqReqId}, '{json.dumps(areaObjects)}', '{json.dumps(changedResources)}')")
    
    printf(";")


if __name__ == "__main__":
    main()