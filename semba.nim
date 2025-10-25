import std/json
import std/strutils
import system/ansi_c
import std/math
import std/times

import db_connector/db_sqlite

var db = open("build/semba.db", "", "", "")

proc dupString(str: string): cstring =
  let s = str.cstring
  result = cast[cstring](c_malloc((s.len + 1).csize_t))
  copyMem(result, s, s.len + 1)

proc adventure_AreaObject(jsonReq: JsonNode): JsonNode =
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

  var areaItemsRes = newSeq[JsonNode]()

  let areaItems = db.getAllRows(sql"SELECT areaItemId FROM areaItems WHERE areaId = ?", areaId)

  for areaItem in areaItems:
    areaItemsRes.add(%*{"areaItemId": parseInt(areaItem[0])})

  return %*{"areaObjects": areaObjects, "areaItems": areaItemsRes}

proc tip_Release(jsonReq: JsonNode): JsonNode =
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

  return %*{
    "changedResources": {"tips": tips},
    "areaObjects": areaObjects
  }

proc getDistance(x1: float, y1: float, z1: float, x2: float, y2: float, z2: float): float =
  return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2) + pow(z2-z1, 2))

proc getUserStatus(): JsonNode =
  let statusRow = db.getRow(sql"SELECT val FROM userData WHERE keyName = ?", "status")
  return parseJson(statusRow[0])

proc setUserStatus(status: JsonNode) =
  db.exec(sql"UPDATE userData SET val = ? WHERE keyName = ?", $status, "status")

proc updatePos(status: var JsonNode, fromAreaId: int, toAreaId: int) =
  let gatesRows = db.getAllRows(sql"""
    SELECT fromPosX, fromPosY, fromPosZ, toPosX, toPosY, toPosZ, toDirection
    FROM gates
    WHERE fromAreaId = ? AND toAreaId = ?
  """, fromAreaId, toAreaId)

  let currentPosX = parseFloat(status["currentPositionCoordinates"]["x"].getStr())
  let currentPosY = parseFloat(status["currentPositionCoordinates"]["y"].getStr())
  let currentPosZ = parseFloat(status["currentPositionCoordinates"]["z"].getStr())

  var hasDist = false
  var smallestDist = 0.0
  var foundToPosX = 0.0
  var foundToPosY = 0.0
  var foundToPosZ = 0.0
  var foundToDirection = 0

  for gateRow in gatesRows:
    let fromPosX = parseFloat(gateRow[0])
    let fromPosY = parseFloat(gateRow[1])
    let fromPosZ = parseFloat(gateRow[2])

    let dist = getDistance(fromPosX, fromPosY, fromPosZ, currentPosX, currentPosY, currentPosZ)

    if not hasDist or dist < smallestDist:
      hasDist = true
      smallestDist = dist
      foundToPosX = parseFloat(gateRow[3])
      foundToPosX = parseFloat(gateRow[4])
      foundToPosX = parseFloat(gateRow[5])
      foundToDirection = parseInt(gateRow[6])

  if not hasDist:
    echo "[SembaCall] Warning: updatePos couldn't find a gate..."
  else:
    status["currentPositionCoordinates"] = %*{"x": foundToPosX, "y": foundToPosY, "z": foundToPosZ}

proc adventure_MoveToArea(jsonReq: JsonNode): JsonNode =
  let areaId = jsonReq["areaId"].getInt()
  let areaBgmRow = db.getRow(sql"SELECT id, eventName FROM areaBgm WHERE areaId = ?", areaId)

  let currentLocation = jsonReq["currentLocation"]

  var status = getUserStatus()

  let fromAreaId = currentLocation["areaKeyId"].getInt()

  if fromAreaId == areaId:
    status["currentAreaType"] = currentLocation["areaType"]
    status["currentDirection"] = currentLocation["direction"]
    status["currentPositionCoordinates"] = currentLocation["positionCoordinates"]
    status["currentAreaKeyId"] = currentLocation["areaKeyId"]
  else:
    # FIXME: should update status["currentAreaType"] here
    updatePos(status, fromAreaId, areaId)
    status["currentAreaKeyId"] = %*areaId

  setUserStatus(status)

  return %*{
    "areaBgm": {"id": parseInt(areaBgmRow[0]), "eventName": areaBgmRow[1]},
    "changedResources": {
      "status": status
    }
  }

#[
{
  "battleEntryIds": [
    2000042
  ],
  "lineCharacterIds": [
    100201,
    100101
  ],
  "battleTriggers": [
    {
      "triggerType": "area_object",
      "triggerIds": [
        30701301
      ]
    }
  ],
  "advantageType": "advantage",
  "isAttackHit": true,
  "currentLocation": {
    "areaType": 1,
    "direction": 5,
    "positionCoordinates": {
      "x": 9.360747,
      "y": 46.2933769,
      "z": -19.6981583
    },
    "areaKeyId": 300401
  },
  "bloodStainLocation": {
    "areaKeyId": 300401,
    "areaType": 1,
    "positionCoordinates": {
      "x": 8.889949,
      "y": 46.28351,
      "z": -20.2399845
    }
  }
}
]#

#[
{
  "battleEntryIds": [
    2000016,
    2000015
  ],
  "lineCharacterIds": [
    100101
  ],
  "battleTriggers": [
    {
      "triggerIds": [
        300401701,
        300401702
      ]
    }
  ],
  "advantageType": "advantage",
  "isAttackHit": true,
  "currentLocation": {
    "areaType": 1,
    "direction": 7,
    "positionCoordinates": {
      "x": -4.79455566,
      "y": 53.6070023,
      "z": -8.03439
    },
    "areaKeyId": 300401
  },
  "bloodStainLocation": {
    "areaKeyId": 300401,
    "areaType": 1,
    "positionCoordinates": {
      "x": -1.59099984,
      "y": 53.6070023,
      "z": -7.590285
    }
  }
}
]#

proc battle_Start(jsonReq: JsonNode): JsonNode =
  discard

#[
{
  "characterUpdates": [
    {
      "characterId": 100201,
      "hp": 370
    },
    {
      "characterId": 100101,
      "hp": 511
    }
  ],
  "battleTaskTopics": [
    {
      "type": "qte",
      "count": 4
    },
    {
      "type": "special_attack",
      "count": 2
    }
  ],
  "encounteredEnemyIds": [
    224303
  ],
  "battleTimeSecond": 55,
  "taskConditionResult": {
    "usedSkills": [
      {
        "characterSkillId": 1002016,
        "count": 2
      },
      {
        "characterSkillId": 1001016,
        "count": 2
      },
      {
        "characterSkillId": 1001014,
        "count": 1
      },
      {
        "characterSkillId": 1002014,
        "count": 1
      }
    ],
    "enemyStabilityBreaks": [
      {
        "enemyId": 224303,
        "count": 2
      }
    ]
  }
}
]#
proc battle_Finish(jsonReq: JsonNode): JsonNode =
  discard

proc user_CrossDate(jsonReq: JsonNode): JsonNode =
  # FIXME: move status loggedInAt update to user_LogIn
  let status = getUserStatus()
  let loggedInAt = $(now().utc)
  status["loggedInAt"] = %*loggedInAt
  setUserStatus(status)
  return %*{
    "changedResources": {
      "status": status,
      "notifications": {
        "gacha": {
          "executableGachaIds": [
            1
          ]
        },
        "mail": true,
        "itemRequest": false
      }
    }
  }

# jsonReq: { "characterUpdates": [ { "characterId": 100101, "hp": 511 } ] }
proc adventure_UpdateCharacterStatus(jsonReq: JsonNode): JsonNode =
  # FIXME: complete this
  return %*{
    "changedResources": {
    }
  }

proc sembaCallUnsafe(uri: cstring, request: cstring): cstring {.exportc.} =
  let jsonReq = if request != "": parseJson($request) else: nil
  var jsonRes: JsonNode

  if uri == "echo":
    let dataUpper = jsonReq["data"].getStr().toUpperAscii()
    jsonRes = %*{"data": dataUpper}
  elif uri == "/auth/steam_user":
    jsonRes = %*{"userId": "696969696969"}
  elif uri == "/auth/nonce":
    jsonRes = %*{"nonce": "6969696969696969"}
  elif uri == "/auth/sign_in":
    jsonRes = %*{"sessionToken": "69696969-6969-6969-6969-696969696969", "language": 2}
  elif uri == "/adventure/area_object":
    jsonRes = adventure_AreaObject(jsonReq)
  elif uri == "/tip/release":
    jsonRes = tip_Release(jsonReq)
  elif uri == "/adventure/move_to_area":
    jsonRes = adventure_MoveToArea(jsonReq)
  elif uri == "/battle/start":
    jsonRes = battle_Start(jsonReq)
  elif uri == "/battle/finish":
    jsonRes = battle_Finish(jsonReq)
  elif uri == "/user/cross_date":
    jsonRes = user_CrossDate(jsonReq)
  elif uri == "/adventure/update_character_status":
    jsonRes = adventure_UpdateCharacterStatus(jsonReq)
  else:
    jsonRes = nil

  result = if jsonRes != nil: dupString($jsonRes) else: nil

  echo "[SembaCall] uri: ", uri
  echo "[SembaCall] request: ", request
  echo "[SembaCall] response: ", result

proc SembaCall(uri: cstring, request: cstring): cstring {.exportc.} =
  try:
    result = sembaCallUnsafe(uri, request)
  except:
    echo("Nim Exception: " & getCurrentExceptionMsg())
    result = nil