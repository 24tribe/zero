import std/json
import std/strutils
import system/ansi_c

import db_connector/db_sqlite

var db = open("semba.db", "", "", "")

proc DupString(str: string): cstring =
  let s = str.cstring
  result = cast[cstring](c_malloc((s.len + 1).csize_t))
  copyMem(result, s, s.len + 1)

proc SembaCallUnsafe(uri: cstring, request: cstring): cstring {.exportc.} =
  let jsonReq = if request != "": parseJson($request) else: nil

  if uri == "echo":
    let dataUpper = jsonReq["data"].getStr().toUpperAscii()
    let resJson = %*{"data": dataUpper}
    result = DupString($resJson)
  elif uri == "/auth/steam_user":
    let res = %*{"userId": "696969696969"}
    result = DupString($res)
  elif uri == "/auth/nonce":
    let res = %*{"nonce": "6969696969696969"}
    result = DupString($res)
  elif uri == "/auth/sign_in":
    let res = %*{"sessionToken": "69696969-6969-6969-6969-696969696969", "language": 2}
    result = DupString($res)
  elif uri == "/adventure/area_object":
    let areaId = jsonReq["areaId"].getInt()
    let rows = db.getAllRows(sql"""
      SELECT areaObjectId, areaPointId, areaObjectBehaviorId, action
      FROM areaObjects
      WHERE areaId = ?
    """, areaId)

    var areaObjects = newSeq[JsonNode]();

    for row in rows:
      areaObjects.add(%*{
        "areaObjectId": parseInt(row[0]),
        "areaPointId": parseInt(row[1]),
        "areaObjectBehaviorId": parseInt(row[2]),
        "action": parseJson(row[3])
      })

    let enemies = db.getAllRows(sql"""
      SELECT areaPointId, areaEnemyRateSetId, action
      FROM areaEnemies
      WHERE areaId = ?
    """, areaId)

    for enemy in enemies:
      areaObjects.add(%*{
        "areaPointId": parseInt(enemy[0]),
        "areaEnemyRateSetId": parseInt(enemy[1]),
        "action": parseJson(enemy[2])
      })

    let res = %*{"areaObjects": areaObjects}
    result = DupString($res)
  elif uri == "/tip/release":
    var tips = newSeq[JsonNode]()
    var areaObjects = newSeq[JsonNode]()

    for node in jsonReq["tipIds"]:
      let tipId = node.num
      tips.add(%*{"tipId": tipId, "releasedAt": "2025-09-10T02:17:06Z"})

      let newAreaObjects = db.getAllRows(sql"""
        SELECT areaObjectId, newAreaPointId, newAreaObjectBehaviorId, newAction
        FROM tipRelease
        WHERE tipId = ?
      """, tipId)

      for areaObject in newAreaObjects:
        areaObjects.add(%*{
          "areaObjectId": parseInt(areaObject[0]),
          "areaPointId": parseInt(areaObject[1]),
          "areaObjectBehaviorId": parseInt(areaObject[2]),
          "action": parseJson(areaObject[3]),
        })

      db.exec(sql"""
        UPDATE areaObjects
        SET areaPointId = t.newAreaPointId,
            areaObjectBehaviorId = t.newAreaObjectBehaviorId,
            action = t.newAction
        FROM tipRelease as t
        WHERE t.tipId = ? AND areaObjects.areaId = t.areaId AND areaObjects.areaObjectId = t.areaObjectId
      """, tipId)


    let res = %*{
      "changedResources": {"tips": tips},
      "areaObjects": areaObjects
    }

    result = DupString($res)
  else:
    result = nil

  echo uri, request, result

proc SembaCall(uri: cstring, request: cstring): cstring {.exportc.} =
  try:
    result = SembaCallUnsafe(uri, request)
  except:
    echo("Nim Exception: " & getCurrentExceptionMsg())
    result = nil