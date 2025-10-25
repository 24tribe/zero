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

proc getNotifications(): JsonNode =
  return %*{
    "gacha": {
      "executableGachaIds": [
        1
      ]
    },
    "mail": true,
    "itemRequest": false
  }

proc user_CrossDate(jsonReq: JsonNode): JsonNode =
  # FIXME: move status loggedInAt update to user_LogIn
  let status = getUserStatus()
  let loggedInAt = $(now().utc)
  status["loggedInAt"] = %*loggedInAt
  setUserStatus(status)
  return %*{
    "changedResources": {
      "status": status,
      "notifications": getNotifications()
    }
  }

# jsonReq: { "characterUpdates": [ { "characterId": 100101, "hp": 511 } ] }
proc adventure_UpdateCharacterStatus(jsonReq: JsonNode): JsonNode =
  # FIXME: complete this
  return %*{
    "changedResources": {
    }
  }

proc getTensionCards(): seq[JsonNode] =
  let tensionCardsRows = db.getAllRows(sql"""
    SELECT tensionCardId, receivedAt, maxLevel, abilityEfficacies, trainingScoreLevelScore,
      entityId, isLocked FROM tensionCards
  """)

  for tensionCardRow in tensionCardsRows:
    let tensionCardId = parseInt(tensionCardRow[0])
    let receivedAt = tensionCardRow[1]
    let maxLevel = parseInt(tensionCardRow[2])
    let abilityEfficacies = parseJson(tensionCardRow[3])
    let trainingScoreLevelScore = parseInt(tensionCardRow[4])
    let entityId = parseInt(tensionCardRow[5])
    let isLocked = if parseInt(tensionCardRow[6]) == 1: true else: false

    result.add(%*{
      "tensionCardId": tensionCardId,
      "receivedAt": receivedAt,
      "maxLevel": maxLevel,
      "abilityEfficacies": abilityEfficacies,
      "trainingScoreLevelScore": trainingScoreLevelScore,
      "entityId": entityId,
      "isLocked": isLocked
    })

proc getFormationsStr(): string =
  # FIXME: proper implementation
  result = """[{"members": {"character1Id": 100101, "character1OwnershipType": 1}, "cards": {}}, {"number": 1, "members": {"character1Id": 100101, "character1OwnershipType": 1}, "cards": {"tensionCard1Id": 5, "tensionCard2Id": 4, "tensionCard3Id": 3, "tensionCard4Id": 2, "tensionCard5Id": 1}}, {"number": 2, "members": {"character1Id": 100101, "character1OwnershipType": 1}, "cards": {}}, {"number": 3, "members": {"character1Id": 100101, "character1OwnershipType": 1}, "cards": {}}, {"number": 4, "members": {"character1Id": 100101, "character1OwnershipType": 1}, "cards": {}}, {"number": 5, "members": {"character1Id": 100101, "character1OwnershipType": 1}, "cards": {}}, {"number": 6, "members": {"character1Id": 100101, "character1OwnershipType": 1}, "cards": {}}, {"number": 7, "members": {"character1Id": 100101, "character1OwnershipType": 1}, "cards": {}}, {"number": 8, "members": {"character1Id": 100101, "character1OwnershipType": 1}, "cards": {}}, {"number": 9, "members": {"character1Id": 100101, "character1OwnershipType": 1}, "cards": {}}, {"number": 10, "members": {"character1Id": 100101, "character1OwnershipType": 1}, "cards": {}}]"""

proc getChallengeProgresses(): seq[JsonNode] =
  let challengeProgressesRows = db.getAllRows(sql"""
    SELECT challengeProgressId, clearedAt, state
    FROM challengeProgresses
  """)

  for challengeProgressRow in challengeProgressesRows:
    let challengeProgressId = parseInt(challengeProgressRow[0])
    let clearedAt = challengeProgressRow[1]
    let state = parseInt(challengeProgressRow[2])

    if clearedAt != "":
      result.add(%*{
        "challengeProgressId": challengeProgressId,
        "clearedAt": clearedAt,
        "state": state
      })
    else:
      result.add(%*{
        "challengeProgressId": challengeProgressId,
        "state": state
      })

proc getCharacters(): seq[JsonNode] =
  let charactersRows = db.getAllRows(sql"""
    SELECT characterId, exp, hp, attack, defense, maxHp, receivedAt, characterOwnershipType,
    criticalRate, criticalDamageRate, movementSpeed, damageInflictedRate, tensionIncreaseRate,
    cpRecastRate, spGaugeIncreaseRate, attackSpeed, characterCostumeId, abnormalityParamSet,
    trainingScoreLevelScore, trainingScoreRankScore, actionPointMax,
    actionPointRate, actionPointConsumption, damageTakenRate FROM characters
  """)

  for characterRow in charactersRows:
    let characterId = parseInt(characterRow[0])
    let exp = parseInt(characterRow[1])
    let hp = parseInt(characterRow[2])
    let attack = parseInt(characterRow[3])
    let defense = parseInt(characterRow[4])
    let maxHp = parseInt(characterRow[5])
    let receivedAt = characterRow[6]
    let characterOwnershipType = parseInt(characterRow[7])
    let criticalRate = parseInt(characterRow[8])
    let criticalDamageRate = parseInt(characterRow[9])
    let movementSpeed = parseInt(characterRow[10])
    let damageInflictedRate = parseInt(characterRow[11])
    let tensionIncreaseRate = parseInt(characterRow[12])
    let cpRecastRate = parseInt(characterRow[13])
    let spGaugeIncreaseRate = parseInt(characterRow[14])
    let attackSpeed = parseInt(characterRow[15])
    let characterCostumeId = parseInt(characterRow[16])
    let abnormalityParamSet = parseJson(characterRow[17])
    let trainingScoreLevelScore = parseInt(characterRow[18])
    let trainingScoreRankScore = parseInt(characterRow[19])
    let actionPointMax = parseInt(characterRow[20])
    let actionPointRate = parseInt(characterRow[21])
    let actionPointConsumption = parseInt(characterRow[22])
    let damageTakenRate = parseInt(characterRow[23])

    result.add(%*{
      "characterId": characterId,
      "exp": exp,
      "hp": hp,
      "attack": attack,
      "defense": defense,
      "maxHp": maxHp,
      "receivedAt": receivedAt,
      "characterOwnershipType": characterOwnershipType,
      "criticalRate": criticalRate,
      "criticalDamageRate": criticalDamageRate,
      "movementSpeed": movementSpeed,
      "damageInflictedRate": damageInflictedRate,
      "tensionIncreaseRate": tensionIncreaseRate,
      "cpRecastRate": cpRecastRate,
      "spGaugeIncreaseRate": spGaugeIncreaseRate,
      "attackSpeed": attackSpeed,
      "characterCostumeId": characterCostumeId,
      "abnormalityParamSet": abnormalityParamSet,
      "trainingScoreLevelScore": trainingScoreLevelScore,
      "trainingScoreRankScore": trainingScoreRankScore,
      "actionPointMax": actionPointMax,
      "actionPointRate": actionPointRate,
      "actionPointConsumption": actionPointConsumption,
      "damageTakenRate": damageTakenRate
    })

proc getNineSequences(): seq[JsonNode] =
  let nineSequencesRows = db.getAllRows(sql"""
    SELECT nineSequenceId, expiresAt, lastReceiveAt, lastReadAt
    FROM nineSequences
  """)

  for nineSequenceRow in nineSequencesRows:
    let nineSequenceId = parseInt(nineSequenceRow[0])
    let expiresAt = nineSequenceRow[1]
    let lastReceiveAt = nineSequenceRow[2]
    let lastReadAt = nineSequenceRow[3]

    result.add(%*{
      "nineSequenceId": nineSequenceId,
      "expiresAt": expiresAt,
      "lastReceiveAt": lastReceiveAt,
      "lastReadAt": lastReadAt
    })

proc getTips(): seq[JsonNode] =
  let tipsRows = db.getAllRows(sql"""
    SELECT tipId, releasedAt
    FROM tips
  """)

  for tipRow in tipsRows:
    let tipId = parseInt(tipRow[0])
    let releasedAt = tipRow[1]

    result.add(%*{
      "tipId": tipId,
      "releasedAt": releasedAt
    })

proc user_LogIn(): JsonNode =
  return %*{
    "resources": {
      "wallet": {},
      "characters": getCharacters(),
      "status": getUserStatus(),
      "tensionCards": getTensionCards(),
      "formations": parseJson(getFormationsStr()),
      "characterMountingPowerCommon": {},
      "notifications": getNotifications(),
      "challenges": [{"challengeId": 100, "state": 8}],
      "challengeProgresses": getChallengeProgresses(),
      "areas": [{"areaId": 300401}, {"areaId": 300402}],
      "nineSequences": getNineSequences(),
      "tips": getTips()
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
  elif uri == "/user/log_in":
    jsonRes = user_LogIn()
  else:
    jsonRes = nil

  result = if jsonRes != nil: dupString($jsonRes) else: nil

proc SembaCall(uri: cstring, request: cstring): cstring {.exportc.} =
  try:
    result = sembaCallUnsafe(uri, request)
  except:
    echo("Nim Exception: " & getCurrentExceptionMsg())
    result = nil