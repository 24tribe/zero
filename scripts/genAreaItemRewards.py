from argparse import ArgumentParser
import json
from collections import defaultdict
import sys

from dumpSembaLogs import get_debug_logs

# kane (3, 1, 100)
# char. exp (13, 1, 10)
# t. c. exp (7, 2, 50)

def main():
    parser = ArgumentParser()

    parser.add_argument("online_logs_db", nargs='+')

    args = parser.parse_args()

    online_logs = []

    for online_logs_db in args.online_logs_db:
        online_logs += get_debug_logs(online_logs_db)

    online_logs = filter(lambda x: x["uri"] == "/adventure/acquire_area_item", online_logs)

    content_types = {3, 13, 6, 7}

    areaItemRewards = {}

    for online_log in online_logs:
        req = online_log["req"]
        res = online_log["res"]

        assert req["areaItemId"] == res["areaItem"]["areaItemId"]
        assert res["areaItem"]["acquired"]
        assert "changedResources" in res

        if "items" in res["changedResources"] or "rewards" in res:
            assert "rewards" in res
            assert "items" in res["changedResources"]

        if "rewards" in res:
            assert len(res["rewards"]) == 1

            reward = res["rewards"][0]

            assert reward["type"] == 5

            new_contents = []

            for content in reward["contents"]:
                assert content["type"] in content_types

                if content["type"] != 6: # 6 == gear
                    new_contents.append(content)

                if content["type"] == 3: # kane
                    assert content["id"] == 1

                if content["type"] == 13: # char exp
                    assert content["id"] == 1

                if content["type"] == 7: # item?
                    # id 2: t. c. exp
                    pass

            reward["contents"] = new_contents

            areaItemRewards[req["areaItemId"]] = [reward]

    write_sql(areaItemRewards)

def write_sql(areaItemRewards):
    areaItemIds = list(areaItemRewards)
    areaItemIds.sort()

    print("INSERT INTO areaItemRewards (areaItemId, rewards) VALUES")

    first = True
    for areaItemId in areaItemIds:
        if first:
            first = False
        else:
            sys.stdout.write(",")

        rewards = areaItemRewards[areaItemId]
        print(f"({areaItemId}, '{json.dumps(rewards)}')")

    print(";")

if __name__ == "__main__":
    main()