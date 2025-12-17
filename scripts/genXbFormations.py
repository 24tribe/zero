from argparse import ArgumentParser
import json

def main():
    parser = ArgumentParser()
    parser.add_argument("online_logs_json")
    parser.add_argument("out_sql")
    args = parser.parse_args()

    with open(args.online_logs_json, "r", encoding="utf-8") as f:
        online_logs = json.load(f)

    xb_formation_flows = filter(lambda x: x["uri"] == "/xb/formation", online_logs)

    xb_id_to_res = map(lambda x: (x["req"]["xbId"], x["res"]), xb_formation_flows)
    xb_id_to_res = dict(xb_id_to_res)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        write_sql(xb_id_to_res, f)

def write_sql(xb_id_to_res, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO xbFormations (xbId, content) VALUES ")

    first = True
    for xbId, content in xb_id_to_res.items():
        if first:
            first = False
        else:
            f.write(", ")

        xprint(f"({xbId},'{json.dumps(content)}')")
    
    xprint(";")


if __name__ == "__main__":
    main()