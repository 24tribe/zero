"""
Not found:  2562 U-DX Robot
Not found:  2572 Deadly Red Alert
Not found:  2601 S.H.A.R.K / Backgammon
Not found:  2602 Brave Diver / Solitaire
Not found:  1002 Tsuki Iroha
Not found:  2421 Ooze (slimes)
Not found:  1016 Sui Yakumo
"""

from argparse import ArgumentParser
import json


def main():
    parser = ArgumentParser()
    parser.add_argument("online_logs_json")
    parser.add_argument("out_sql")
    args = parser.parse_args()

    with open(args.online_logs_json, "r", encoding="utf-8") as f:
        online_logs = json.load(f)

    enemyGroupRewards = getEnemyGroupRewards(online_logs)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        write_enemy_group_rewards(enemyGroupRewards, f)


def write_enemy_group_rewards(enemyGroupRewards, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("INSERT INTO enemyGroupRewards (enemyGroupId, rewardGroupId) VALUES")

    first = True

    for enemy_group_id, reward_group_id in enemyGroupRewards.items():
        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({enemy_group_id}, {reward_group_id})")

    xprint(";")


def getEnemyGroupRewards(online_logs):
    battle_finish_logs = filter(lambda x: x["uri"] == "/battle/finish", online_logs)
    battle_finish_logs = list(battle_finish_logs)

    rewardData = []

    for battle_finish_log in battle_finish_logs:
        req = battle_finish_log["req"]
        res = battle_finish_log["res"]
        encounteredEnemyIds = req["encounteredEnemyIds"]
        if "rewards" in res:
            rewards = res["rewards"]
            if rewards[0]["type"] == 6:
                contents = rewards[0]["contents"]
                item_set = set()
                for content in contents:
                    if content["type"] == 7:
                        item_set.add(content["id"])

                rewardData.append((encounteredEnemyIds, item_set))

    rewardData.sort(key=lambda x: x[0])

    enemyGroupRewards = {}

    for enemyIds, rewardIds in rewardData:
        for enemyId in enemyIds:
            enemyGroupId = enemyId//100
            if enemyGroupId not in enemyGroupRewards and len(rewardIds) == 1:
                enemyGroupRewards[enemyGroupId] = list(rewardIds)[0]//10

    return enemyGroupRewards


if __name__ == "__main__":
    main()
