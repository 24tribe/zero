from argparse import ArgumentParser
from pathlib import Path
import json
import re

def get_game_infos(log):
    currentAtBatGameInfo, nextAtBatGameInfo = None, None

    if "currentAtBatGameInfo" in log["res"]:
        currentAtBatGameInfo = log["res"]["currentAtBatGameInfo"]

    if "nextAtBatGameInfo" in log["res"]:
        nextAtBatGameInfo = log["res"]["nextAtBatGameInfo"]

    return currentAtBatGameInfo, nextAtBatGameInfo

def main():
    parser = ArgumentParser()
    parser.add_argument("logs_json")
    parser.add_argument("out_dir")
    args = parser.parse_args()

    with open(args.logs_json, "r", encoding="utf-8") as f:
        logs = json.load(f)

    xb_uris = set(("/xb/start", "/xb/update_tension", "/xb/play"))

    logs = filter(lambda x: x["uri"] in xb_uris, logs)
    xbId = 10001 # FIXME: don't hardcode to first xb match
    logs = filter(lambda x: x["req"]["xbId"] == xbId, logs)
    logs = list(logs)

    pat = re.compile(r"[^a-zA-Z0-9_]")

    out_dir = Path(args.out_dir)
    out_dir.mkdir(exist_ok=True)

    for i, log in enumerate(logs):
        currentAtBatGameInfo, nextAtBatGameInfo = get_game_infos(log)

        name = f"{i:02d}_{log["receivedAt"]}_{log["uri"]}"
        name = pat.sub("_", name)

        print(name)

        if currentAtBatGameInfo != None:
            with open(out_dir / f"{name}_currentAtBatGameInfo.json", "w", encoding="utf-8") as f:
                f.write(json.dumps(currentAtBatGameInfo))

        if nextAtBatGameInfo != None:
            with open(out_dir / f"{name}_nextAtBatGameInfo.json", "w", encoding="utf-8") as f:
                f.write(json.dumps(nextAtBatGameInfo))


if __name__ == "__main__":
    main()