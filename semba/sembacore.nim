import std/json
import std/strutils

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

proc addOfflineLog*(db: DbConn, offlineLog: JsonNode) =
  let receivedAt = offlineLog["receivedAt"].getStr()
  let uri = offlineLog["uri"].getStr()
  let req = offlineLog["req"].getStr()
  let res = offlineLog["res"].getStr()

  db.exec(
    sql"INSERT INTO debugLogsOffline (receivedAt, uri, req, res) VALUES (?, ?, ?, ?)",
    receivedAt, uri, req, res
  )

proc getOfflineLogs*(db: DbConn): seq[JsonNode] =
  let rows = db.getAllRows(sql"SELECT receivedAt, uri, req, res FROM debugLogsOffline")

  for row in rows:
    let receivedAt = row[0]
    let uri = row[1]
    let req = row[2]
    let res = row[3]

    result.add(%*{
      "receivedAt": receivedAt,
      "uri": uri,
      "req": req,
      "res": res
    })

proc sembaCallImpl*(
    uri: string, request: string, version: GameVersion,
    db: DbConn, lastBattleStartReq: var BattleStartRequest
): string =
  let jsonReq = if request != "": parseJson(request) else: nil
  var jsonRes: JsonNode

  if uri.startsWith("/semba/"):
    jsonRes = getJsonResultPrivateApi(uri, jsonReq, db)
  elif version == gvDemo:
    jsonRes = getJsonResultDemo(uri, jsonReq, db)
  else:
    jsonRes = getJsonResultStable(uri, jsonReq, db, lastBattleStartReq)

  result = if jsonRes != nil: $jsonRes else: ""

  logFlowOffline(db, uri, request, result)