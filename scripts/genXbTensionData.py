from argparse import ArgumentParser
from collections import defaultdict
import json

from genGameInfos import get_game_infos

def main():
    parser = ArgumentParser()
    parser.add_argument("online_logs_json")
    parser.add_argument("out_sql")
    args = parser.parse_args()

    with open(args.online_logs_json, "r", encoding="utf-8") as f:
        online_logs = json.load(f)

    xb_uris = set(("/xb/start", "/xb/update_tension", "/xb/play"))

    online_logs = filter(lambda x: x["uri"] in xb_uris, online_logs)
    xbId = 10001 # FIXME: don't hardcode to first xb match
    online_logs = filter(lambda x: x["req"]["xbId"] == xbId, online_logs)
    online_logs = list(online_logs)

    tension_data = gen_tension_data(online_logs)
    zone_area_suggestion_ids = getZoneAreaSuggestionIds(online_logs)

    for k, v in tension_data.items():
        print(k, v)

    for k, v in zone_area_suggestion_ids.items():
        print(k, v)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        write_tension_data_sql(tension_data, f)
        write_zone_area_suggestion_ids(zone_area_suggestion_ids, f)

def write_zone_area_suggestion_ids(zone_area_suggestion_ids, f):
    xprint = lambda *args: print(*args, file=f)
    xprint("""
INSERT INTO zoneAreaSuggestionIds (tensionFluctuationId, idx, content) VALUES
    """)

    first = True

    for tensionFluctuationId, contentList in zone_area_suggestion_ids.items():
        i = 1 # i == 0 doesn't have changes in zone_area_suggestion_ids
        for content in contentList:
            if i == 2: # missing in logs
                i += 1

            if first:
                first = False
            else:
                f.write(", ")

            con = json.dumps(content)
            xprint(f"({tensionFluctuationId}, {i}, '{con}')")
            i += 1
    
    xprint(";")

def write_tension_data_sql(tension_data, f):
    xprint = lambda *args: print(*args, file=f)
    xprint("""
INSERT INTO tensionData (tensionFluctuationId, topTeamDelta, bottomTeamDelta, topTeamSkitIndex, bottomTeamSkitIndex) VALUES
    """)

    first = True

    for xbId, td in tension_data.items():
        topTeamSkitIndex = td["topTeamSkitIndex"] if td["topTeamSkitIndex"] is not None else -1
        bottomTeamSkitIndex = td["bottomTeamSkitIndex"] if td["bottomTeamSkitIndex"] is not None else -1
        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({xbId}, {td['topTeamDelta']}, {td['bottomTeamDelta']}, {topTeamSkitIndex}, {bottomTeamSkitIndex})")
    
    xprint(";")


def gen_skit_indexes(currentAtBatEventInfo, bottomTeam, topTeam):
    tensionInfos = currentAtBatEventInfo["logicEventInfos"][3]["tensionInfos"]

    topTeamSkitIndex = None
    bottomTeamSkitIndex = None

    for tensionInfo in tensionInfos:
        if tensionInfo.get("isPlayer", False):
            if topTeam.get("isPlayerTeam", False):
                topTeamSkitIndex = tensionInfo["skitIndex"]
            else:
                bottomTeamSkitIndex = tensionInfo["skitIndex"]
        else:
            if topTeam.get("isPlayerTeam", False):
                bottomTeamSkitIndex = tensionInfo["skitIndex"]
            else:
                topTeamSkitIndex = tensionInfo["skitIndex"]

    return {
        "topTeamSkitIndex": topTeamSkitIndex,
        "bottomTeamSkitIndex": bottomTeamSkitIndex
    }

def getZoneAreaSuggestionIds(online_logs):
    result = defaultdict(list)

    for i, online_log in enumerate(online_logs):
        if online_log["uri"] == "/xb/update_tension":
            assert len(online_log["req"]["tensionFluctuationIds"]) == 1
            tensionFluctuationId = online_log["req"]["tensionFluctuationIds"][0]

            currentAtBatGameInfo = online_log["res"]["currentAtBatGameInfo"]

            last_log = online_logs[i-1]

            lastGameInfo = get_last_game_info(last_log)

            topTeam = currentAtBatGameInfo["topTeam"]
            bottomTeam = currentAtBatGameInfo["bottomTeam"]

            currentAtBatEventInfo = currentAtBatGameInfo["currentAtBatEventInfo"]

            lastTopTeam = lastGameInfo["topTeam"]
            lastBottomTeam = lastGameInfo["bottomTeam"]

            lastZoneAreas = {x.get("index", 0): x for x in lastGameInfo["bottomTeam"]["zoneAreas"]}
            zoneAreas = {x.get("index", 0): x for x in currentAtBatGameInfo["bottomTeam"]["zoneAreas"]}

            assert len(lastZoneAreas) == len(zoneAreas)

            diff = []

            for i, zoneArea in zoneAreas.items():
                lastPlayerSuggests = lastZoneAreas[i]["playerSuggests"]
                assert len(lastPlayerSuggests) == 1
                lastMembers = lastPlayerSuggests[0].get("members", [])
                assert len(lastMembers) <= 1

                playerSuggests = zoneArea["playerSuggests"]
                assert len(playerSuggests) == 1
                members = playerSuggests[0].get("members", [])
                assert len(members) <= 1

                assert len(members) == len(lastMembers)

                if len(members) == 1 and lastMembers[0]["suggestionId"] != members[0]["suggestionId"]:
                    diff.append({
                        "zoneAreaIndex": i,
                        "suggestionId": members[0]["suggestionId"]
                    })

            if diff != []:
                result[tensionFluctuationId].append(diff)

    return result

def gen_tension_data(online_logs):
    tensionFluctuationIds = set()
    result = {}

    for i, online_log in enumerate(online_logs):
        if online_log["uri"] == "/xb/update_tension":
            assert len(online_log["req"]["tensionFluctuationIds"]) == 1
            tensionFluctuationId = online_log["req"]["tensionFluctuationIds"][0]

            if tensionFluctuationId in tensionFluctuationIds:
                continue

            tensionFluctuationIds.add(tensionFluctuationId)

            currentAtBatGameInfo = online_log["res"]["currentAtBatGameInfo"]

            last_log = online_logs[i-1]

            lastGameInfo = get_last_game_info(last_log)

            topTeam = currentAtBatGameInfo["topTeam"]
            bottomTeam = currentAtBatGameInfo["bottomTeam"]

            currentAtBatEventInfo = currentAtBatGameInfo["currentAtBatEventInfo"]

            lastTopTeam = lastGameInfo["topTeam"]
            lastBottomTeam = lastGameInfo["bottomTeam"]

            topTeamDelta = calc_delta(topTeam, lastTopTeam)
            bottomTeamDelta = calc_delta(bottomTeam, lastBottomTeam)

            skitIndexes = gen_skit_indexes(currentAtBatEventInfo, bottomTeam, topTeam)

            result[tensionFluctuationId] = {
                "topTeamSkitIndex": skitIndexes["topTeamSkitIndex"],
                "bottomTeamSkitIndex": skitIndexes["bottomTeamSkitIndex"],
                "topTeamDelta": topTeamDelta,
                "bottomTeamDelta": bottomTeamDelta
            }

    return result

def get_last_game_info(last_log):
    currentAtBatGameInfo, nextAtBatGameInfo = get_game_infos(last_log)

    if nextAtBatGameInfo is not None:
        gameInfo = nextAtBatGameInfo
    else:
        gameInfo = currentAtBatGameInfo

    return gameInfo


def get_tension_infos(tensionInfos, topTeam, bottomTeam):
    topTeamTensionInfo = None
    bottomTeamTensionInfo = None

    for tensionInfo in tensionInfos:
        if tensionInfo.get("isPlayer", False):
            if topTeam.get("isPlayerTeam", False):
                topTeamTensionInfo = tensionInfo
            else:
                bottomTeamTensionInfo = tensionInfo
        else:
            if topTeam.get("isPlayerTeam", False):
                bottomTeamTensionInfo = tensionInfo
            else:
                topTeamTensionInfo = tensionInfo

    return topTeamTensionInfo, bottomTeamTensionInfo

def calc_delta(team, lastTeam):
    tensionValue = team.get("tensionValue", 0)
    lastTensionValue = lastTeam.get("tensionValue", 0)
    return tensionValue - lastTensionValue

if __name__ == "__main__":
    main()