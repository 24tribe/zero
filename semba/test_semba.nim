import std/assertions
import std/options
import std/json

import db_connector/db_sqlite
import sembacore

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


proc test_talk_hoimi_read_sequence() =
  var ctx = getInMemorySembaCtx()

  discard sembaCall(ctx, "/semba/load_save_file", %*{
    "saves_dir": "../test_saves",
    "name": "before talk hoimi first",
  })

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
  doAssert(changedResources["challengeProgresses"] == %*[{"challengeProgressId": 1010042, "state": 2}])
  doAssert(changedResources["challengeTasks"].getElems().len == 1)

  let challengeTask = changedResources["challengeTasks"][0]
  doAssert(challengeTask["challengeTaskId"].getInt() == 10100422)
  doAssert(challengeTask.hasKey("clearedAt"))
  doAssert(challengeTask["count"].getInt() == 1)


test_null()
let retval = test_reset_db()
test_talk_hoimi_read_sequence()

echo("End of test_semba.nim")

quit(retval)