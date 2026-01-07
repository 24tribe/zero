from argparse import ArgumentParser
from functools import partial
import json
import sys

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

    printf("INSERT INTO readSequence (sequenceRequestId, areaObjects, changedResources, nineSequenceId) VALUES ")

    first = True
    for debug_log in debug_logs:
        if debug_log["uri"] == "/adventure/read_sequence":
            if first:
                first = False
            else:
                f.write(", ") 

            seqReqId = 0
            nineSequenceId = 0

            seqRequestIds = debug_log["req"].get("sequenceRequestIds", [])
            nineSequences = debug_log["req"].get("nineSequences", [])

            if len(seqRequestIds) > 0:
                seqReqId = seqRequestIds[0]

            if len(nineSequences) > 0:
                nineSequenceId = nineSequences[0]["id"]

            changedResources = debug_log["res"]["changedResources"]
            areaObjects = debug_log["res"].get("areaObjects")

            areaObjectsStr = (json.dumps(areaObjects) if areaObjects is not None else "").replace("'", "''")

            changedResourcesJson = json.dumps(changedResources).replace("'", "''")

            printf(f"({seqReqId}, '{areaObjectsStr}', '{changedResourcesJson}', {nineSequenceId})")
    
    printf(";")


if __name__ == "__main__":
    main()