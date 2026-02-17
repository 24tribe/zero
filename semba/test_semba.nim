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


proc test_reset_db(): int =
  var ctx = SembaCtx(version: gvStable, db: initMemoryDb(), lastBattleInfo: none(BattleInfo))

  doAssert(not itemsTableExists(ctx.db))

  discard sembaCall(ctx, "/semba/reset_db", nil)

  doAssert(itemsTableExists(ctx.db))


let retval = test_reset_db()

echo("End of test_semba.nim")

quit(retval)