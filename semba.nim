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

    let res = %*{"areaObjects": areaObjects}
    result = DupString($res)
  elif uri == "/tip/release":
    var tips = newSeq[JsonNode]()
    for node in jsonReq["tipIds"]:
      tips.add(%*{"tipId": node.num, "releasedAt": "2025-09-10T02:17:06Z"})

    let res = %*{"changedResources": {"tips": tips}}
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