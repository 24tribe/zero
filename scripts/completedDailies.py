from argparse import ArgumentParser

from dumpSembaLogs import get_debug_logs

def main():
    parser = ArgumentParser()
    parser.add_argument("semba_db", nargs="+")
    args = parser.parse_args()

    debug_logs = []

    for semba_db in args.semba_db:
        debug_logs += get_debug_logs(semba_db)

    itemIdList = get_happy_worker_item_list(debug_logs)

    itemIds, itemIdChallengeTasks = get_happy_worker_item_challenge_tasks(debug_logs)

    completedItemIds = get_completed_happy_worker_items(itemIds, itemIdChallengeTasks, debug_logs)

    itemIdList |= completedItemIds

    itemIdList = list(itemIdList)
    itemIdList.sort()

    for itemId in itemIdList:
        completed = itemId in completedItemIds
        print(f"{itemId=}, {completed=}")

def happy_worker_items_ids_to_set(happy_worker_items):
    return set(map(lambda x: x["happyWorkerItemId"], happy_worker_items))

def get_happy_worker_item_list(debug_logs):
    debug_logs = list(filter(lambda x: x["uri"] == "/happy_worker/list", debug_logs))

    happy_worker_item_ids = None

    for debug_log in debug_logs:
        if happy_worker_item_ids is None:
            happy_worker_item_ids = happy_worker_items_ids_to_set(debug_log["res"]["happyWorkerItems"])
        else:
            happy_worker_item_ids |= happy_worker_items_ids_to_set(debug_log["res"]["happyWorkerItems"])

    return happy_worker_item_ids

def is_challenge_task_completed(challengeTaskId, debug_logs):
    for debug_log in debug_logs:
        for challengeTask in debug_log["res"]["changedResources"]["challengeTasks"]:
            if (challengeTask["challengeTaskId"] == challengeTaskId
                and "clearedAt" in challengeTask
                and "count" in challengeTask
                and challengeTask["count"] > 0
            ):
                return True

    return False

def get_completed_happy_worker_items(itemIds, itemIdChallengeTasks, debug_logs):
    def has_challenge_task(x):
        return (
            (x["uri"] == "/adventure/read_sequence" or x["uri"] == "/battle/finish")
            and "changedResources" in x["res"]
            and "challengeTasks" in x["res"]["changedResources"]
            and len(challengeTasks := x["res"]["changedResources"]["challengeTasks"]) > 0
            and len(list(map(lambda ct: "clearedAt" in ct, challengeTasks))) > 0
        )

    debug_logs = list(filter(has_challenge_task, debug_logs))

    completedItemIds = set()

    for itemId in itemIds:
        challengeTasks = itemIdChallengeTasks[itemId]
        completed = True

        for challengeTask in challengeTasks:
            if not is_challenge_task_completed(challengeTask["challengeTaskId"], debug_logs):
                # print(f"{challengeTask} not completed")
                completed = False
                break

        if completed:
            completedItemIds.add(itemId)

    return completedItemIds


def get_happy_worker_item_challenge_tasks(debug_logs):
    debug_logs = filter(lambda x: x["uri"] == "/happy_worker/start", debug_logs)

    itemIdChallengeTasks = {}

    for debug_log in debug_logs:
        req = debug_log["req"]
        if req is None: # bugged
            continue
        res = debug_log["res"]

        itemIdChallengeTasks[req["happyWorkerItemId"]] = res["changedResources"]["challengeTasks"]

    itemIds = list(itemIdChallengeTasks)
    itemIds.sort()

    return itemIds, itemIdChallengeTasks


if __name__ == "__main__":
    main()