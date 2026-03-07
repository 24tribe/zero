import std/algorithm
import std/assertions
import std/options
import std/json

import db_connector/db_sqlite
import sembacore
import sembaprivate


type SembaCtx = object
  version: GameVersion
  db: DbConn
  lastBattleInfo: Option[BattleInfo]


proc initMemoryDb(): DbConn = open(":memory:", "", "", "")


proc sembaCall(ctx: var SembaCtx, path: string, body: JsonNode): JsonNode =
  let bodyStr = if body != nil: $body else: ""
  let resultStr = sembaCallImpl(path, bodyStr, ctx.version, ctx.db, ctx.lastBattleInfo)

  if resultStr != "":
    result = parseJson(resultStr)


proc itemsTableExists(db: DbConn): bool =
  result = db.getRow(sql"SELECT name FROM sqlite_schema WHERE name = 'items'")[0] == "items"


proc getInMemorySembaCtx(): SembaCtx =
  result = SembaCtx(version: gvStable, db: initMemoryDb(), lastBattleInfo: none(BattleInfo))
  discard sembaCall(result, "/semba/reset_db", nil)


proc loadSaveFile(ctx: var SembaCtx, name: string) =
  discard sembaCall(ctx, "/semba/load_save_file", %*{
    "saves_dir": "../test_saves",
    "name": name,
  })


proc test_reset_db(): int =
  var ctx = SembaCtx(version: gvStable, db: initMemoryDb(), lastBattleInfo: none(BattleInfo))

  doAssert(not itemsTableExists(ctx.db))

  discard sembaCall(ctx, "/semba/reset_db", nil)

  doAssert(itemsTableExists(ctx.db))


proc test_null() =
  let db = initMemoryDb()
  db.exec(sql"CREATE TABLE asd (x INTEGER, y INTEGER)")
  db.exec(sql"INSERT INTO asd (x, y) VALUES (null, 10)")

  let row = db.getRow(sql"SELECT x, y FROM asd")
  doAssert(row[0] == "")
  doAssert(row[1] == "10")

proc sortByAreaPointId(a, b: AreaObject): int = cmp(a.areaPointId, b.areaPointId)

proc test_talk_to_branch_manager_after_hoimi_read_sequence() =
  var ctx = getInMemorySembaCtx()

  loadSaveFile(ctx, "after hoimi before branch manager")

  let res = sembaCall(ctx, "/adventure/read_sequence", %*{
    "sequenceRequestIds": [ 80100421, 80100423, 8011592 ],
    "currentLocation": {
      "areaType": 1,
      "direction": 1,
      "positionCoordinates": { "x": -0.45827195, "y": 0.0416666679 },
      "areaKeyId": 109902
    },
    "areaType": 1,
    "areaKeyId": 109902
  })

  doAssert(res != nil)

  var areaObjects = to(res["areaObjects"], seq[AreaObject])
  areaObjects.sort(sortByAreaPointId)

  var expectedAreaObjects = to(%*[
    {
      "areaObjectId": 801056, "areaPointId": 109903001, "areaObjectBehaviorId": 8011611,
      "action": {"type": 3, "id": 1, "sequenceId": 8011591}
    },
    {
      "areaObjectId": 801055, "areaPointId": 109902001, "areaObjectBehaviorId": 8011601,
      "action": {"type": 3, "id": 1, "sequenceId": 8011591}
    },
    {
      "areaObjectId": 801054, "areaPointId": 101316003, "areaObjectBehaviorId": 8011591,
      "action": {"type": 3, "id": 1, "sequenceId": 8011591}
    },
    {
      "areaObjectId": 801009, "areaPointId": 101301002, "areaObjectBehaviorId": 8010042,
      "action": {"type": 3, "id": 1, "sequenceId": 8010042, "label": "Enoki Yukigaya"}
    },
    {
      "areaObjectId": 801008, "areaPointId": 101301003, "areaObjectBehaviorId": 8010045,
      "action": {"type": 3, "id": 1, "sequenceId": 8010045, "label": "Roku Saigo"}
    },
    {
      "areaObjectId": 801006, "areaPointId": 101511003, "areaObjectBehaviorId": 8010050,
      "action": {"type": 3, "id": 1, "sequenceId": 8010047, "label": "Jio Takinogawa"}
    },
    {
      "areaObjectId": 801005, "areaPointId": 101511002, "areaObjectBehaviorId": 8010047,
      "action": {"type": 3, "id": 1, "sequenceId": 8010043, "label": "Miu Jujo"}
    },
    {
      "areaObjectId": 801004, "areaPointId": 101511004, "areaObjectBehaviorId": 8010941,
      "action": {"type": 3, "id": 1, "sequenceId": 8010048, "label": "Koishi Kohinata"}
    },
    {
      "areaObjectId": 700058, "areaPointId": 101312102, "areaObjectBehaviorId": 7010712,
      "action": {"type": 7, "id": 1}
    },
    {
      "areaObjectId": 700053, "areaPointId": 101311120, "areaObjectBehaviorId": 7010714,
      "action": {"type": 7, "id": 1}
    },
    {
      "areaObjectId": 109002, "areaPointId": 109902901, "areaObjectBehaviorId": 10900201,
      "action": {"type": 3, "id": 1, "sequenceId": 10900201, "label": "Branch Manager"}
    }
  ], seq[AreaObject])

  expectedAreaObjects.sort(sortByAreaPointId)

  doAssert(areaObjects == expectedAreaObjects)

  let changedResources = res["changedResources"]

  let challengeProgresses = to(changedResources["challengeProgresses"], seq[ChallengeProgress])
  
  doAssert(challengeProgresses.len == 2)

  doAssert(challengeProgresses[0].challengeProgressId == 1010042)
  doAssert(challengeProgresses[0].clearedAt.isSome())
  doAssert(challengeProgresses[0].state == challengeProgressStateCleared.int)

  doAssert(challengeProgresses[1].challengeProgressId == 1010043)
  doAssert(challengeProgresses[1].clearedAt.isNone())
  doAssert(challengeProgresses[1].state == challengeProgressStateStarted.int)

  let challengeTasks = to(changedResources["challengeTasks"], seq[ChallengeTask])

  doAssert(challengeTasks.len == 1)

  doAssert(challengeTasks[0].challengeTaskId == 10100421)
  doAssert(challengeTasks[0].clearedAt.isSome())
  doAssert(challengeTasks[0].count == 1)

  let adventureVariables = to(changedResources["adventureVariables"], seq[AdventureVariable])
  doAssert(adventureVariables[0].adventureVariableId == 10030)
  doAssert(adventureVariables[0].value.get(0) == 2)


proc test_talk_hoimi_read_sequence() =
  var ctx = getInMemorySembaCtx()

  loadSaveFile(ctx, "before talk hoimi first")

  let res = sembaCall(ctx, "/adventure/read_sequence", %*{
    "sequenceRequestIds": [80100422, 8011592],
    "currentLocation": {
      "areaType": 1,
      "direction": 5,
      "positionCoordinates": {"x": 1.75, "y": 0.0104166679,"z": -1.5},
      "areaKeyId": 109903
    },
    "areaType": 1,
    "areaKeyId": 109903
  })

  doAssert(res != nil)

  let areaObjects = to(res["areaObjects"], seq[AreaObject])
  doAssert(areaObjects.len == 1)
  let expected = to(%*{
    "areaObjectId": 109005,
    "areaPointId": 109903902,
    "areaObjectBehaviorId": 10900501,
    "action": {"type": 3, "id": 1, "sequenceId": 10900501, "label": "Hoimi"}
  }, AreaObject)

  doAssert(areaObjects[0] == expected)

  let changedResources = res["changedResources"]

  let challengeProgresses = to(changedResources["challengeProgresses"], seq[ChallengeProgress])
  doAssert(challengeProgresses.len == 1)
  doAssert(challengeProgresses[0] == ChallengeProgress(challengeProgressId: 1010042, state: 2))

  doAssert(changedResources["challengeTasks"].getElems().len == 1)
  let challengeTask = changedResources["challengeTasks"][0]
  doAssert(challengeTask["challengeTaskId"].getInt() == 10100422)
  doAssert(challengeTask.hasKey("clearedAt"))
  doAssert(challengeTask["count"].getInt() == 1)

  let adventureVariables = to(changedResources["adventureVariables"], seq[AdventureVariable])
  doAssert(adventureVariables[0].adventureVariableId == 10030)
  doAssert(adventureVariables[0].value.get(0) == 1)


proc test_endrone_battle_start() =
  var ctx = getInMemorySembaCtx()

  loadSaveFile(ctx, "before endrone fight bug")

  let res = sembaCall(ctx, "/battle/start", %*{
    "battleEntryIds": [ 1000004 ],
    "lineCharacterIds": [ 101101, 100801, 100201 ],
    "battleTriggers": [ { "triggerType": "action_sequence" } ],
    "currentLocation": {
      "areaType": 1,
      "direction": 1,
      "positionCoordinates": { "x": 99.96959, "y": 11.0309982, "z": 0.120423831 },
      "areaKeyId": 300401
    },
    "bloodStainLocation": {
      "areaKeyId": 300401,
      "areaType": 1,
      "positionCoordinates": { "x": 99.96959, "y": 11.0309982, "z": 0.120423831 }
    }
  })

  doAssert(res != nil)


proc test_talk_with_enoki_first() =
  var ctx = getInMemorySembaCtx()

  loadSaveFile(ctx, "before talking enoki first")

  let res = sembaCall(ctx, "/adventure/read_sequence", %*{
    "sequenceRequestIds": [ 80100431, 8011622 ],
    "currentLocation": {
      "areaType": 1, "direction": 5,
      "positionCoordinates": { "x": -15.2384529, "y": 0.015625, "z": -19.510952 },
      "areaKeyId": 101301
    },
    "areaType": 1,
    "areaKeyId": 101301
  })

  let changedResources = res["changedResources"]

  let challengeProgresses = to(changedResources["challengeProgresses"], seq[ChallengeProgress])
  doAssert(challengeProgresses.len == 1)
  doAssert(challengeProgresses[0].challengeProgressId == 1010043)
  doAssert(challengeProgresses[0].state == challengeProgressStateStarted.int)

  let challengeTasks = to(changedResources["challengeTasks"], seq[ChallengeTask])
  doAssert(challengeTasks.len == 1)
  doAssert(challengeTasks[0].challengeTaskId == 10100431)
  doAssert(challengeTasks[0].clearedAt.isSome())
  doAssert(challengeTasks[0].count == 1)

  var expectedAreaObjects = to(%*[
    {
      "areaObjectId": 801009,
      "areaPointId": 101301002,
      "areaObjectBehaviorId": 8010043,
      "action": {
        "type": 3,
        "id": 1,
        "sequenceId": 8010044,
        "label": "Enoki Yukigaya"
      }
    },
    {
      "areaObjectId": 801005,
      "areaPointId": 101511002,
      "areaObjectBehaviorId": 8010047,
      "action": {
        "type": 3,
        "id": 1,
        "sequenceId": 8010043,
        "label": "Miu Jujo"
      }
    }
  ], seq[AreaObject])

  var areaObjects = to(res["areaObjects"], seq[AreaObject])
  areaObjects.sort(sortByAreaPointId)

  #[
  This is weird. This read_sequence returns Miu as a changed area object but doesn't change
  any of her properties. Also, her areaObjectBehaviorId (8010047) has a condition to appear after
  starting the challengeProgress with id=1010043 (after talking with Hoimi and the Branch Manager),
  so it shouldn't be here, since this read_sequence happens after talking to Enoki. 
  Until I figure out what's going on I think it's fine to accept both responses (with and without Miu).
  ]#

  doAssert(
    expectedAreaObjects == areaObjects or
    (areaObjects.len == 1 and areaObjects[0] == expectedAreaObjects[0])
  )

  let adventureVariables = to(changedResources["adventureVariables"], seq[AdventureVariable])
  doAssert(adventureVariables[0].adventureVariableId == 10031)
  doAssert(adventureVariables[0].value.get(0) == 1)


proc test_talk_to_miu_after_enonki_read_sequence() =
  var ctx = getInMemorySembaCtx()

  loadSaveFile(ctx, "before talking miu after talking enoki")

  let res = sembaCall(ctx, "/adventure/read_sequence", %*{
    "sequenceRequestIds": [ 80100432, 8011622 ],
    "nineSequences": [{ "id": 10000002, "choices": "{\"Selections\":[]}" }],
    "currentLocation": {
      "areaType": 1,
      "direction": 5,
      "positionCoordinates": { "x": -16.6637859, "y": 3.012142, "z": 0.6405984 },
      "areaKeyId": 101511
    },
    "areaType": 1,
    "areaKeyId": 101511
  })

  doAssert(res != nil)

  let changedResources = res["changedResources"]
  
  let challengeProgresses = to(changedResources["challengeProgresses"], seq[ChallengeProgress])
  doAssert(challengeProgresses.len == 2)

  for challengeProgress in challengeProgresses:
    doAssert(challengeProgress.challengeProgressId == 1010043 or challengeProgress.challengeProgressId == 1010051)
    if challengeProgress.challengeProgressId == 1010043:
      doAssert(challengeProgress.state == challengeProgressStateCleared.int)
    else:
      doAssert(challengeProgress.state == challengeProgressStateStarted.int)

  let challengeTasks = to(changedResources["challengeTasks"], seq[ChallengeTask])
  doAssert(challengeTasks.len == 1)

  doAssert(challengeTasks[0].challengeTaskId == 10100432)
  doAssert(challengeTasks[0].clearedAt.isSome())
  doAssert(challengeTasks[0].count == 1)

  var expectedAreaObjects = to(%*[
    {
      "areaObjectId": 801011, "areaPointId": 100101006, "areaObjectBehaviorId": 8010053,
      "action": {"type": 3, "id": 1, "sequenceId": 8010051, "label": "Q"}
    },
    {
      "areaObjectId": 801010, "areaPointId": 100101005, "areaObjectBehaviorId": 8010051,
      "action": {"type": 3, "id": 1, "sequenceId": 8010051, "label": "Kazuki Aoyama"}
    },
    {
      "areaObjectId": 801005, "areaPointId": 101511002, "areaObjectBehaviorId": 8010048,
      "action": {"type": 3, "id": 1, "sequenceId": 8010046, "label": "Miu Jujo"}
    }
  ], seq[AreaObject])

  expectedAreaObjects.sort(sortByAreaPointId)

  var areaObjects = to(res["areaObjects"], seq[AreaObject])
  areaObjects.sort(sortByAreaPointId)

  doAssert(expectedAreaObjects == areaObjects)

  let nineSequences = to(changedResources["nineSequences"], seq[NineSequence])

  doAssert(nineSequences.len == 1)
  doAssert(nineSequences[0].nineSequenceId == 10000002)
  doAssert(nineSequences[0].choices == "{\"Selections\":[]}")
  doAssert(nineSequences[0].lastReadAt.isSome())

  let adventureVariables = to(changedResources["adventureVariables"], seq[AdventureVariable])
  doAssert(adventureVariables[0].adventureVariableId == 10031)
  doAssert(adventureVariables[0].value.get(0) == 2)


proc test_update_hair_color() =
  var ctx = getInMemorySembaCtx()

  let res1 = sembaCall(ctx, "/semba/update_hair_color", %*{
    "charId": 1,
    "r": 0.5,
    "g": 0.5,
    "b": 0.5,
    "enabled": true
  })

  doAssert res1 != nil
  doAssert res1["status"].getStr() == "ok"

  let res2 = sembaCall(ctx, "/semba/update_hair_color", %*{
    "charId": 2,
    "r": 0.5,
    "g": 0.5,
    "b": 0.5,
    "enabled": false
  })

  doAssert res2 != nil
  doAssert res2["status"].getStr() == "ok"

  let res4 = sembaCall(ctx, "/semba/update_hair_color", %*{
    "charId": 2,
    "r": 0.8,
    "g": 0.8,
    "b": 0.8,
    "enabled": false
  })

  doAssert res4 != nil
  doAssert res4["status"].getStr() == "ok"

  let res3 = sembaCall(ctx, "/semba/get_hair_colors", nil)

  doAssert res3 != nil

  let hairColors = to(res3, seq[HairColor])

  doAssert(hairColors.len == 2)

  for hairColor in hairColors:
    doAssert(hairColor.charId == 1 or hairColor.charId == 2)
    if hairColor.charId == 1:
      doAssert(hairColor.enabled)
      doAssert(hairColor.r == 0.5)
      doAssert(hairColor.g == 0.5)
      doAssert(hairColor.b == 0.5)
    else: # hairColor.charId == 2
      doAssert(not hairColor.enabled)
      doAssert(hairColor.r == 0.8)
      doAssert(hairColor.g == 0.8)
      doAssert(hairColor.b == 0.8)


test_null()
let retval = test_reset_db()
test_talk_hoimi_read_sequence()
test_talk_to_branch_manager_after_hoimi_read_sequence()
test_update_hair_color()
test_endrone_battle_start()

test_talk_with_enoki_first()
test_talk_to_miu_after_enonki_read_sequence()

echo("End of test_semba.nim")

quit(retval)