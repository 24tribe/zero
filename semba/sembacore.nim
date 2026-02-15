import std/json
import std/strutils
import std/options

import db_connector/db_sqlite

import sembastable
import sembademo
import sembaprivate

export sembastable

type GameVersion* = enum
  gvNone, gvStable, gvDemo, gvBeta

proc logFlowOffline(db: DbConn, uri: string, req: string, res: string) =
  db.exec(
    sql"INSERT INTO debugLogsOffline (receivedAt, uri, req, res) VALUES (?, ?, ?, ?)",
    getDateNow(), uri, req, res
  )

proc sembaCallImpl*(
    uri: string, request: string, version: GameVersion,
    db: DbConn, lastBattleInfo: var Option[BattleInfo]
): string =
  let jsonReq = if request != "": parseJson(request) else: nil
  var jsonRes: JsonNode

  if uri.startsWith("/semba/"):
    jsonRes = getJsonResultPrivateApi(uri, jsonReq, db)
  elif version == gvDemo:
    jsonRes = getJsonResultDemo(uri, jsonReq, db)
  else:
    jsonRes = getJsonResultStable(uri, jsonReq, db, lastBattleInfo)

  result = if jsonRes != nil: $jsonRes else: ""

  logFlowOffline(db, uri, request, result)