from argparse import ArgumentParser
from functools import partial

from dumpSembaLogs import get_debug_logs
from genArea import get_first_move_to_area

def main():
    parser = ArgumentParser()
    parser.add_argument("semba_db")
    parser.add_argument("out_sql")

    args = parser.parse_args()

    debug_logs = get_debug_logs(args.semba_db)

    first_move_to_area = get_first_move_to_area(debug_logs)

    read_seq_move_to_area_pairs = get_read_seq_move_to_area_pairs(debug_logs)
    rows = get_read_seq_area_action_rows(read_seq_move_to_area_pairs)
    bgm_rows = get_bgm_rows(read_seq_move_to_area_pairs)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        write_area_action_sequence_ids_sql(first_move_to_area, f)
        write_read_seq_area_action_sql(rows, f)
        write_bgm_rows_sql(bgm_rows, f)

def get_read_seq_move_to_area_pairs(debug_logs):
    result = []

    for i in range(len(debug_logs) - 1):
        debug_log = debug_logs[i]
        if debug_log["uri"] == "/adventure/read_sequence":
            next_debug_log = debug_logs[i+1]
            if next_debug_log["uri"] == "/adventure/move_to_area":
                result.append((debug_log, next_debug_log))

    return result

def get_bgm_rows(read_seq_move_to_area_pairs):
    result = []

    for read_seq, move_to_area in read_seq_move_to_area_pairs:
        sequenceRequestId = read_seq["req"]['sequenceRequestIds'][0]
        areaId = move_to_area["req"]["areaId"]

        id_ = move_to_area["res"]["areaBgm"]["id"]
        eventName = move_to_area["res"]["areaBgm"].get("eventName", "")

        result.append((sequenceRequestId, areaId, id_, eventName))

    return result

def write_bgm_rows_sql(bgm_rows, f):
    printf = partial(print, file=f)

    printf("INSERT INTO readSequenceAreaBgm (sequenceRequestId, areaId, id, eventName) VALUES")

    first = True

    for sequenceRequestId, areaId, id_, eventName in bgm_rows:
        if first:
            first = False
        else:
            f.write(", ")

        printf(f"({sequenceRequestId}, {areaId}, {id_}, '{eventName}')")

    printf(";")

def get_read_seq_area_action_rows(read_seq_move_to_area_pairs):
    result = []

    for read_seq, move_to_area in read_seq_move_to_area_pairs:
        sequenceRequestId = read_seq["req"]['sequenceRequestIds'][0]
        areaId = move_to_area["req"]["areaId"]

        if "areaBehavior" in move_to_area["res"]:
            actionSequenceId = move_to_area["res"]["areaBehavior"]["actionSequenceId"]
        else:
            actionSequenceId = 0

        result.append((sequenceRequestId, areaId, actionSequenceId))

    return result

def write_area_action_sequence_ids_sql(move_to_area, f):
    printf = partial(print, file=f)
    move_to_area = filter(lambda x: "areaBehavior" in x["res"], move_to_area)
    first = True

    printf("INSERT INTO areaActionSequenceIds (areaId, actionSequenceId) VALUES")

    for debug_log in move_to_area:
        if first:
            first = False
        else:
            f.write(", ")

        printf(f"({debug_log["req"]["areaId"]}, {debug_log["res"]["areaBehavior"]["actionSequenceId"]})")

    printf(";")

def write_read_seq_area_action_sql(rows, f):
    printf = partial(print, file=f)

    printf("INSERT INTO readSequenceAreaAction (sequenceRequestId, areaId, actionSequenceId) VALUES")

    first = True

    for sequenceRequestId, areaId, actionSequenceId in rows:
        if first:
            first = False
        else:
            f.write(", ")

        printf(f"({sequenceRequestId}, {areaId}, {actionSequenceId})")

    printf(";")

if __name__ == "__main__":
    main()