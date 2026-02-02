import std/json
import std/math
import std/sequtils
import std/strutils
import std/times
import std/tables
import std/sets
import std/random

import db_connector/db_sqlite
import protojson

type BattleStartRequest* = object
    val*: JsonNode

type SembaError = object of CatchableError

type AreaItemContentType = enum
    kaneContentType = 3,
    gearContentType = 6,
    itemContentType = 7,
    charExpContentType = 13

type TensionData = object
  topTeamDelta: int
  bottomTeamDelta: int
  topTeamSkitIndex: int
  bottomTeamSkitIndex: int

type GachaButton = enum
  gachaButtonSingle = 1,
  gachaButtonTen = 2

type GachaCardType = enum 
  gachaCardCharacter = 4,
  gachaCardTensionCard = 9

type RewardType = enum
  rewardCharacter = 4,
  rewardCharacterPiece = 5,
  rewardItem = 7,
  rewardTensionCard = 9

type GachaRateSetId = enum
  normalGachaRateSetId = 101,
  promisedGachaRateSetId = 102,
  guaranteedGachaRateSetId = 103

const minEventFloorNodeId = 113101
const maxEventFloorNodeId = 113128

const respiteUnitTutorialStatusKey = 43

const dbCharacterFields* = """
  characters.characterId, exp, hp, attack, defense, maxHp, receivedAt, characterOwnershipType,
  criticalRate, criticalDamageRate, movementSpeed, damageInflictedRate, tensionIncreaseRate,
  cpRecastRate, spGaugeIncreaseRate, attackSpeed, characterCostumeId, abnormalityParamSet,
  trainingScoreLevelScore, trainingScoreRankScore, actionPointMax,
  actionPointRate, actionPointConsumption, damageTakenRate, limitBreak
"""

const selectCharacterSql = """
  SELECT """ & dbCharacterFields & """
  FROM characters FULL JOIN characterLimitBreaks
  ON characters.characterId = characterLimitBreaks.characterId
"""

const dbTensionCardsFields = """
  tensionCardId, receivedAt, maxLevel, abilityEfficacies,
  trainingScoreLevelScore, entityId, isLocked
"""

const dbTensionCardsFieldsJoin = """
  tensionCardId, receivedAt, maxLevel, abilityEfficacies,
  trainingScoreLevelScore, tensionCards.entityId, isLocked, limitBreak
"""

const selectTensionCardSql = """
  SELECT """ & dbTensionCardsFieldsJoin & """
  FROM tensionCards FULL JOIN tensionCardLimitBreaks
  ON tensionCards.entityId = tensionCardLimitBreaks.entityId
"""

proc getDateNow*(): string = $(now().utc)

proc updateTensionCardLimitBreak(db: DbConn, entityId: int, limitBreak: int) =
  db.exec(sql"""
    INSERT INTO tensionCardLimitBreaks (entityId, limitBreak) VALUES (?, ?)
    ON CONFLICT (entityId) DO
    UPDATE SET limitBreak = excluded.limitBreak
  """, entityId, limitBreak)

proc getCharacterPiece(db: DbConn, characterId: int): JsonNode =
  let row = db.getRow(
    sql"SELECT characterId, quantity FROM characterPieces WHERE characterId = ?", characterId
  )

  let quantity = if row[0] == "": 0 else: parseInt(row[1])

  result = %*{
    "characterId": characterId,
    "quantity": quantity,
  }

proc getCharacterPieces(db: DbConn): seq[JsonNode] =
  let rows = db.getAllRows(sql"SELECT characterId, quantity FROM characterPieces")
  for row in rows:
    let characterId = parseInt(row[0])
    let quantity = parseInt(row[1])

    result.add(%*{
      "characterId": characterId,
      "quantity": quantity
    })

proc parseCharacterRow*(characterRow: Row): JsonNode =
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
  let limitBreak = if characterRow[24] == "": 0 else: parseInt(characterRow[24])

  return %*{
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
    "damageTakenRate": damageTakenRate,
    "limitBreak": limitBreak,
  }

proc getCharacter(db: DbConn, characterId: int): JsonNode =
  let row = db.getRow(sql(selectCharacterSql & " WHERE characters.characterId = ?"), characterId)

  if row[0] == "":
    raise newException(SembaError, "Couldn't find character for characterId=" & $characterId)

  result = parseCharacterRow(row)

proc updateCharacterPiece(db: DbConn, characterPiece: JsonNode) =
  let characterId = characterPiece["characterId"].getInt()
  let quantity = characterPiece.getOrDefault("quantity").getInt()

  db.exec(sql"""
    INSERT INTO characterPieces (characterId, quantity) VALUES (?, ?)
    ON CONFLICT (characterId) DO
    UPDATE SET quantity = excluded.quantity
  """, characterId, quantity)

#[
Add one character piece to the db, returns the changed count of character pieces
]#
proc addCharacterPiece(db: DbConn, characterId: int): int =
  let row = db.getRow(sql"SELECT quantity FROM characterPieces")

  if row[0] == "":
    result = 1
  else:
    result = parseInt(row[0]) + 1

  updateCharacterPiece(db, %*{"characterId": characterId, "quantity": result})

proc getAreaBgms*(db: DbConn): seq[JsonNode] =
  let rows = db.getAllRows(sql"SELECT areaId, id, eventName FROM areaBgm")

  for row in rows:
    let areaId = parseInt(row[0])
    let id = parseInt(row[1])
    let eventName = row[2]

    result.add(%*{
      "areaId": areaId,
      "id": id,
      "eventName": eventName
    })

proc addAreaBgm*(db: DbConn, areaBgm: JsonNode) =
  let areaId = areaBgm["areaId"].getInt()
  let id = areaBgm["id"].getInt()
  let eventName = areaBgm["eventName"].getStr()

  db.exec(sql"""
    INSERT INTO areaBgm (areaId, id, eventName) VALUES (?, ?, ?)
  """, areaId, id, eventName)

proc addClearedAchievement*(db: DbConn, clearedAchievement: JsonNode) =
  let id = clearedAchievement["id"].getInt()
  let eventFloorNodeId = clearedAchievement["eventFloorNodeId"].getInt()

  db.exec(
    sql"INSERT INTO clearedAchievements (id, eventFloorNodeId) VALUES (?, ?)",
    id, eventFloorNodeId
  )

proc getClearedAchievements*(db: DbConn): seq[JsonNode] =
  let rows = db.getAllRows(sql"SELECT id, eventFloorNodeId FROM clearedAchievements")

  for row in rows:
    let id = parseInt(row[0])
    let eventFloorNodeId = parseInt(row[1])
    result.add(%*{"id": id, "eventFloorNodeId": eventFloorNodeId})

proc getClearedAchievementIds(db: DbConn, eventFloorNodeId: int): set[uint16] =
  let rows = db.getAllRows(
    sql"SELECT id FROM clearedAchievements WHERE eventFloorNodeId = ?", eventFloorNodeId
  )

  for row in rows:
    let clearedAchievementId = parseInt(row[0])
    result.incl(clearedAchievementId.uint16)

proc getEventFloorNodes(db: DbConn): seq[JsonNode] =
  for eventFloorNodeId in minEventFloorNodeId..maxEventFloorNodeId:
    var eventFloorNode = %*{
      "eventFloorNodeId": eventFloorNodeId,
      "unlockedAt": "2025-03-20T18:56:05Z"
    }

    let clearedAchievementIds = toSeq(getClearedAchievementIds(db, eventFloorNodeId))

    if clearedAchievementIds.len > 0:
      eventFloorNode["clearedAchievementIds"] = %*clearedAchievementIds

    result.add(eventFloorNode)

proc updateQuestStates(db: DbConn, questId: int, score: int): seq[JsonNode] =
  let row = db.getRow(sql"SELECT clearCount, bestScore FROM questStates WHERE questId = ?", questId)

  var clearCount = 1
  var bestScore = score

  if row[0] == "":
    db.exec(sql"""
      INSERT INTO questStates (questId, clearCount, bestScore)
      VALUES (?, 1, ?)
    """, questId, bestScore)
  else:
    clearCount += parseInt(row[0])
    let lastBestScore = parseInt(row[1])
    if lastBestScore > bestScore:
      bestScore = lastBestScore
    else:
      db.exec(
        sql"UPDATE questStates SET clearCount = ?, bestScore = ? WHERE questId = ?",
        clearCount, bestScore, questId
      )

  result.add(%*{
    "questId": questId,
    "clearCount": clearCount,
    "bestScore": bestScore
  })

proc event_ListNode(db: DbConn): JsonNode =
  let eventFloorNodes = getEventFloorNodes(db)
  return %*{
    "changedResources": {
      "eventFloorNodes": eventFloorNodes,
    }
  }

proc addQuestState*(db: DbConn, questState: JsonNode) =
  let questId = questState["questId"].getInt()
  let clearCount = questState["clearCount"].getInt()
  let bestScore = questState["bestScore"].getInt()

  db.exec(
    sql"INSERT INTO questStates (questId, clearCount, bestScore) VALUES (?, ?, ?)",
    questId, clearCount, bestScore
  )

proc getQuestStates*(db: DbConn): seq[JsonNode] =
  let rows = db.getAllRows(sql"SELECT questId, clearCount, bestScore FROM questStates")

  for row in rows:
    let questId = parseInt(row[0])
    let clearCount = parseInt(row[1])
    let bestScore = parseInt(row[2])

    result.add(%*{
      "questId": questId,
      "clearCount": clearCount,
      "bestScore": bestScore
    })

proc getUserStatus*(db: DbConn): JsonNode =
  let statusRow = db.getRow(sql"SELECT val FROM userData WHERE keyName = ?", "status")
  return parseJson(statusRow[0])

proc adventure_WarpAreaLocator(db: DbConn, jsonReq: JsonNode): JsonNode =
  let warpAreaId = jsonReq["warpAreaId"].getInt()

  if warpAreaId == 101: # Mita's Hideout
    return %*{
      "changedResources": {
        "status": getUserStatus(db)
      }
    }
  else:
    return nil

proc updateEventFloorNodes(db: DbConn, eventFloorNodeId: int, clearedAchievementIds: set[uint16]): seq[JsonNode] =
  let ids = clearedAchievementIds + getClearedAchievementIds(db, eventFloorNodeId)

  for id in ids:
    db.exec(sql"""
      INSERT INTO clearedAchievements (id, eventFloorNodeId)
      VALUES (?, ?)
      ON CONFLICT (id) DO
      UPDATE SET eventFloorNodeId = excluded.eventFloorNodeId
    """, id, eventFloorNodeId)

  let res = %*{
    "eventFloorNodeId": eventFloorNodeId,
    "unlockedAt": "2025-03-20T18:56:05Z",
  }

  res["clearedAchievementIds"] = %*toSeq(ids)

  result.add(res)

proc adventure_ReleaseEventLift(jsonReq: JsonNode): JsonNode =
  return %*{
    "changedResources": {}
  }

proc event_FinishNode(db: DbConn, jsonReq: JsonNode): JsonNode =
  let eventFloorNodeId = jsonReq["eventFloorNodeId"].getInt()
  let questResult = jsonReq{"questResult"}.getStr("success")
  let clearedAchievementIds: JsonNode = jsonReq{"clearedAchievementIds"}

  result = %*{
    "changedResources": {
    }
  }

  if questResult == "success":
    let score = jsonReq["result"]["score"].getInt()
    let questStates = updateQuestStates(db, eventFloorNodeId, score)
    result["changedResources"]["questStates"] = %*questStates

    var ids: set[uint16] = {}
    if clearedAchievementIds != nil:
      for id in clearedAchievementIds:
        ids.incl(id.getInt().uint16)

    let eventFloorNodes = updateEventFloorNodes(db, eventFloorNodeId, ids)
    result["changedResources"]["eventFloorNodes"] = %*eventFloorNodes

proc getEventLiftAreaObject(areaPointId: int): JsonNode =
  return %*{
    "areaObjectId": 141001,
    "areaPointId": areaPointId,
    "areaObjectBehaviorId": 14100101,
    "action": {
        "type": 10,
        "id": 1,
        "eventLiftId": 14100101
    }
  }

proc getLuxPhantasmaAreaObjects(): seq[JsonNode] =
  # 130801921: event lift
  # 130801922: bar counter
  # 130801923: kazuki first encounter in event
  result.add(getEventLiftAreaObject(130801921))

proc getAreaObjects*(db: DbConn): seq[JsonNode] =
  let rows = db.getAllRows(sql"""
    SELECT areaId, areaObjectId, areaPointId, areaObjectBehaviorId, action
    FROM areaObjects
  """)

  for row in rows:
    let areaId = parseInt(row[0])
    let areaObjectId = parseInt(row[1])
    let areaPointId = parseInt(row[2])
    let areaObjectBehaviorId = parseInt(row[3])
    var action: JsonNode = nil

    if row[4] != "":
      action = parseJson(row[4])

    let areaObject = %*{
      "areaId": areaId,
      "areaObjectId": areaObjectId,
      "areaPointId": areaPointId,
      "areaObjectBehaviorId": areaObjectBehaviorId,
    }

    if action != nil:
      areaObject["action"] = action

    result.add(areaObject)

proc addAreaObject*(db: DbConn, areaObject: JsonNode) =
  let areaId = areaObject["areaId"].getInt()
  let areaObjectId = areaObject["areaObjectId"].getInt()
  let areaPointId = areaObject["areaPointId"].getInt()
  let areaObjectBehaviorId = areaObject["areaObjectBehaviorId"].getInt()
  let action = areaObject.getOrDefault("action")
  let actionStr = if action != nil: $action else: ""

  db.exec(sql"""
    INSERT INTO areaObjects (areaId, areaObjectId, areaPointId, areaObjectBehaviorId, action)
    VALUES (?, ?, ?, ?, ?)
  """, areaId, areaObjectId, areaPointId, areaObjectBehaviorId, actionStr)

proc addAreaEnemy*(db: DbConn, areaEnemy: JsonNode) =
  let areaId = areaEnemy["areaId"].getInt()
  let areaPointId = areaEnemy["areaPointId"].getInt()
  let areaEnemyRateSetId = areaEnemy["areaEnemyRateSetId"].getInt()
  let action = $(areaEnemy["action"])

  db.exec(sql"""
    INSERT INTO areaEnemies (areaId, areaPointId, areaEnemyRateSetId, action)
    VALUES (?, ?, ?, ?)
  """, areaId, areaPointId, areaEnemyRateSetId, action)

proc getAreaEnemies*(db: DbConn): seq[JsonNode] =
  let rows = db.getAllRows(sql"""
    SELECT areaId, areaPointId, areaEnemyRateSetId, action
    FROM areaEnemies
  """)

  for row in rows:
    let areaId = parseInt(row[0])
    let areaPointId = parseInt(row[1])
    let areaEnemyRateSetId = parseInt(row[2])
    let action = parseJson(row[3])

    let areaEnemy = %*{
      "areaId": areaId,
      "areaPointId": areaPointId,
      "areaEnemyRateSetId": areaEnemyRateSetId,
      "action": action 
    }

    result.add(areaEnemy)

proc parseAreaObjectRow(row: Row): JsonNode =
  var areaObjectId = parseInt(row[0])
  var areaPointId = parseInt(row[1])
  var areaObjectBehaviorId = parseInt(row[2])
  let actionStr = row[3]
  let action = if actionStr != "": parseJson(actionStr) else: nil

  result = %*{
    "areaObjectId": areaObjectId,
    "areaPointId": areaPointId,
    "areaObjectBehaviorId": areaObjectBehaviorId,
  }

  if action != nil:
    result["action"] = action

proc parseAreaEnemyRow(row: Row): JsonNode =
  let areaPointId = parseInt(row[0])
  let areaEnemyRateSetId = parseInt(row[1])
  let action = parseJson(row[2])

  result = %*{
    "areaPointId": areaPointId,
    "areaEnemyRateSetId": areaEnemyRateSetId,
    "action": action 
  }

proc adventure_AreaObject(db: DbConn, jsonReq: JsonNode): JsonNode =
  let areaId = jsonReq["areaId"].getInt()
  let rows = db.getAllRows(sql"""
    SELECT areaObjectId, areaPointId, areaObjectBehaviorId, action
    FROM areaObjects
    WHERE areaId = ?
  """, areaId)

  var areaObjects = newSeq[JsonNode]();

  if areaId == 130801: # Mita's Hideout
    areaObjects = getLuxPhantasmaAreaObjects()

  for row in rows:
    let areaObject = parseAreaObjectRow(row)
    areaObjects.add(areaObject)

  let enemyRows = db.getAllRows(sql"""
    SELECT areaPointId, areaEnemyRateSetId, action
    FROM areaEnemies
    WHERE areaId = ?
  """, areaId)

  for row in enemyRows:
    let areaEnemy = parseAreaEnemyRow(row)
    areaObjects.add(areaEnemy)

  var areaItemsRes = newSeq[JsonNode]()

  let areaItems = db.getAllRows(sql"SELECT areaItemId FROM areaItems WHERE areaId = ?", areaId)

  for areaItem in areaItems:
    areaItemsRes.add(%*{"areaItemId": parseInt(areaItem[0])})

  return %*{"areaObjects": areaObjects, "areaItems": areaItemsRes}

proc addTip*(db: DbConn, tip: JsonNode) =
  let tipId = tip["tipId"].getInt()
  let releasedAt = tip["releasedAt"].getStr()
  db.exec(sql"INSERT INTO tips (tipId, releasedAt) VALUES (?, ?)", tipId, releasedAt)

proc tip_Release*(db: DbConn, jsonReq: JsonNode): JsonNode =
  var tips = newSeq[JsonNode]()
  var areaObjects = newSeq[JsonNode]()

  for node in jsonReq["tipIds"]:
    let tipId = node.num

    let tip = %*{"tipId": tipId, "releasedAt": "2025-09-10T02:17:06Z"}
    addTip(db, tip)
    tips.add(tip)

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
      WHERE t.tipId = ? AND areaObjects.areaObjectId = t.areaObjectId
    """, tipId)

  return %*{
    "changedResources": {"tips": tips},
    "areaObjects": areaObjects
  }

proc getDistance(x1: float, y1: float, z1: float, x2: float, y2: float, z2: float): float =
  return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2) + pow(z2-z1, 2))

proc setUserStatus*(db: DbConn, status: JsonNode) =
  db.exec(sql"UPDATE userData SET val = ? WHERE keyName = ?", $status, "status")

proc updatePos(db: DbConn, status: var JsonNode, fromAreaId: int, toAreaId: int) =
  let gatesRows = db.getAllRows(sql"""
    SELECT fromPosX, fromPosY, fromPosZ, toPosX, toPosY, toPosZ, toDirection
    FROM gates
    WHERE fromAreaId = ? AND toAreaId = ?
  """, fromAreaId, toAreaId)

  let currentPosX = status["currentPositionCoordinates"]["x"].getFloat()
  let currentPosY = status["currentPositionCoordinates"]["y"].getFloat()
  let currentPosZ = status["currentPositionCoordinates"]["z"].getFloat()

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

proc updateStatusFromCurrentLocation(status: var JsonNode, currentLocation: JsonNode) =
  status["currentAreaType"] = currentLocation["areaType"]
  status["currentDirection"] = currentLocation["direction"]
  status["currentPositionCoordinates"] = currentLocation["positionCoordinates"]
  status["currentAreaKeyId"] = currentLocation["areaKeyId"]

proc updateStatusFromStatusLocation(status: var JsonNode, otherStatus: JsonNode) =
  status["currentAreaType"] = otherStatus["currentAreaType"]
  status["currentDirection"] = otherStatus["currentDirection"]
  status["currentPositionCoordinates"] = otherStatus["currentPositionCoordinates"]
  status["currentAreaKeyId"] = otherStatus["currentAreaKeyId"]

proc getAreaActionSequenceIds*(db: DbConn): seq[JsonNode] =
  let rows = db.getAllRows(sql"SELECT areaId, actionSequenceId FROM areaActionSequenceIds")

  for row in rows:
    let areaId = parseInt(row[0])
    let actionSequenceId = parseInt(row[1])
    result.add(%*{
      "areaId": areaId,
      "actionSequenceId": actionSequenceId,
    })

proc addAreaActionSequenceId*(db: DbConn, areaActionSequenceId: JsonNode) =
  let areaId = areaActionSequenceId["areaId"].getInt()
  let actionSequenceId = areaActionSequenceId["actionSequenceId"].getInt()

  db.exec(
    sql"INSERT INTO areaActionSequenceIds (areaId, actionSequenceId) VALUES (?, ?)",
    areaId, actionSequenceId
  )

proc getActionSequenceId(db: DbConn, areaId: int): int =
  let row = db.getRow(sql"SELECT actionSequenceId FROM areaActionSequenceIds WHERE areaId = ?", areaId)
  result = if row[0] != "": parseInt(row[0]) else: 0

proc getAreaBgm(db: DbConn, areaId: int): JsonNode =
  let areaBgmRow = db.getRow(sql"SELECT id, eventName FROM areaBgm WHERE areaId = ?", areaId)

  if areaBgmRow[0] == "":
    raise newException(SembaError, "Couldn't find areaBgm for areaId=" & $areaId)

  let areaBgmId = parseInt(areaBgmRow[0])
  let eventName = areaBgmRow[1]

  result = %*{"id": areaBgmId}

  if eventName != "":
    result["eventName"] = %*eventName

proc hasArea(db: DbConn, areaId: int): bool =
  let row = db.getRow(sql"SELECT areaId FROM areas WHERE areaId=?", areaId)
  return row[0] != ""

proc addArea*(db: DbConn, areaId: int) =
  db.exec(sql"""
    INSERT INTO areas (areaId) VALUES (?)
    ON CONFLICT DO NOTHING
  """, areaId)

proc adventure_MoveToArea(db: DbConn, jsonReq: JsonNode): JsonNode =
  let areaId = jsonReq["areaId"].getInt()

  var changedAreas = newSeq[JsonNode]()

  if not hasArea(db, areaId):
    addArea(db, areaId)
    changedAreas.add(%*{"areaId": areaId})

  let currentLocation = jsonReq["currentLocation"]

  var status = getUserStatus(db)

  let fromAreaId = currentLocation["areaKeyId"].getInt()

  if fromAreaId == areaId:
    updateStatusFromCurrentLocation(status, currentLocation)
  else:
    # FIXME: should update status["currentAreaType"] here
    updatePos(db, status, fromAreaId, areaId)
    status["currentAreaKeyId"] = %*areaId

  setUserStatus(db, status)

  let areaBgm = getAreaBgm(db, areaId)

  result = %*{
    "areaBgm": areaBgm,
    "changedResources": {
      "status": status,
      "areas": changedAreas
    }
  }

  let actionSequenceId = getActionSequenceId(db, areaId)

  if actionSequenceId != 0:
    result["areaBehavior"] = %*{"actionSequenceId": actionSequenceId}

proc parseTensionCardRow(tensionCardRow: Row): JsonNode =
  let tensionCardId = parseInt(tensionCardRow[0])
  let receivedAt = tensionCardRow[1]
  let maxLevel = parseInt(tensionCardRow[2])
  let abilityEfficacies = parseJson(tensionCardRow[3])
  let trainingScoreLevelScore = parseInt(tensionCardRow[4])
  let entityId = parseInt(tensionCardRow[5])
  let isLocked = if parseInt(tensionCardRow[6]) == 1: true else: false
  let limitBreak = if tensionCardRow[7] == "": 0 else: parseInt(tensionCardRow[7])

  return %*{
    "tensionCardId": tensionCardId,
    "receivedAt": receivedAt,
    "maxLevel": maxLevel,
    "abilityEfficacies": abilityEfficacies,
    "trainingScoreLevelScore": trainingScoreLevelScore,
    "entityId": entityId,
    "isLocked": isLocked,
    "limitBreak": limitBreak
  }

proc getTensionCards*(db: DbConn): seq[JsonNode] =
  let tensionCardsRows = db.getAllRows(sql(selectTensionCardSql))

  for tensionCardRow in tensionCardsRows:
    result.add(parseTensionCardRow(tensionCardRow))

proc getTensionCard(db: DbConn, entityId: int): JsonNode =
  let row = db.getRow(sql(selectTensionCardSql & " WHERE tensionCards.entityId = ?"), entityId)

  if row[0] == "":
    raise newException(SembaError, "Couldn't find tensionCard for entityId=" & $entityId)

  result = parseTensionCardRow(row)

proc addTensionCard*(db: DbConn, tensionCard: JsonNode) =
  let tensionCardId = tensionCard["tensionCardId"].getInt()
  let receivedAt = tensionCard["receivedAt"].getStr()
  let maxLevel = tensionCard["maxLevel"].getInt()
  let abilityEfficacies = $tensionCard["abilityEfficacies"]
  let trainingScoreLevelScore = tensionCard["trainingScoreLevelScore"].getInt()
  let entityId = tensionCard["entityId"].getInt()
  let isLocked = if tensionCard["isLocked"].getBool(): 1 else: 0
  let limitBreak = tensionCard.getOrDefault("limitBreak").getInt()

  db.exec(
    sql("INSERT INTO tensionCards (" & dbTensionCardsFields & ") VALUES (?, ?, ?, ?, ?, ?, ?)"),
    tensionCardId, receivedAt, maxLevel, abilityEfficacies,
    trainingScoreLevelScore, entityId, isLocked
  )

  updateTensionCardLimitBreak(db, entityId, limitBreak)

proc getEquippedTensionCards(db: DbConn): seq[JsonNode] =
  # FIXME: should return current formation tension cards

  let tensionCardsRows = db.getAllRows(sql(selectTensionCardSql & " LIMIT 5"))

  for tensionCardRow in tensionCardsRows:
    result.add(parseTensionCardRow(tensionCardRow))

proc getBattleParameters(db: DbConn, battleEntryIds: JsonNode): seq[JsonNode] =
  # FIXME: fix n+1
  for battleEntryId in battleEntryIds:
    let id = battleEntryId.getInt()
    let battleParameterRow = db.getRow(sql"""
      SELECT enemies FROM battleParameters WHERE id = ?
    """, id)

    if battleParameterRow[0] == "":
      raise newException(SembaError, "Couldn't find battleParameters for battleEntryId=" & $battleEntryId)

    let enemies = parseJson(battleParameterRow[0])

    result.add(%*{
      "id": id,
      "enemies": enemies
    })

proc battle_Start(db: DbConn, lastBattleStartReq: var BattleStartRequest, jsonReq: JsonNode): JsonNode =
  lastBattleStartReq.val = jsonReq

  var characters = newSeq[JsonNode]()

  # FIXME: fix this n+1 problem
  for lineCharacterId in jsonReq["lineCharacterIds"]:
    let character = getCharacter(db, lineCharacterId.getInt())
    characters.add(character)

  let status = getUserStatus(db)

  let currentLocation = jsonReq["currentLocation"]
  
  status["currentAreaKeyId"] = currentLocation["areaKeyId"]
  status["currentAreaType"] = currentLocation["areaType"]
  status["currentDirection"] = currentLocation["direction"]
  status["currentPositionCoordinates"] = currentLocation["positionCoordinates"]

  setUserStatus(db, status)

  let battleParameters = getBattleParameters(db, jsonReq["battleEntryIds"])

  let advantageType = jsonReq.getOrDefault("advantageType")

  result = %*{
    "characters": characters,
    "tensionCards": getEquippedTensionCards(db),
    "changedResources": {
      "status": status
    },
    "battleParameters": battleParameters,
    "battleTriggers": jsonReq["battleTriggers"]
  }

  if advantageType != nil:
    result["advantageType"] = advantageType

proc setCharacterHp(db: DbConn, characterId: int, hp: int) =
  db.exec(sql"UPDATE characters SET hp = ? WHERE characterId = ?", hp, characterId)

proc getCharacters*(db: DbConn): seq[JsonNode] =
  let charactersRows = db.getAllRows(sql(selectCharacterSql))

  for characterRow in charactersRows:   
    result.add(parseCharacterRow(characterRow))

proc addCharacter*(db: DbConn, character: JsonNode) =
  let characterId = character["characterId"].getInt()
  let exp = character["exp"].getInt()
  let hp = character["hp"].getInt()
  let attack = character["attack"].getInt()
  let defense = character["defense"].getInt()
  let maxHp = character["maxHp"].getInt()
  let receivedAt = character["receivedAt"].getStr()
  let characterOwnershipType = character["characterOwnershipType"].getInt()
  let criticalRate = character["criticalRate"].getInt()
  let criticalDamageRate = character["criticalDamageRate"].getInt()
  let movementSpeed = character["movementSpeed"].getInt()
  let damageInflictedRate = character["damageInflictedRate"].getInt()
  let tensionIncreaseRate = character["tensionIncreaseRate"].getInt()
  let cpRecastRate = character["cpRecastRate"].getInt()
  let spGaugeIncreaseRate = character["spGaugeIncreaseRate"].getInt()
  let attackSpeed = character["attackSpeed"].getInt()
  let characterCostumeId = character["characterCostumeId"].getInt()
  let abnormalityParamSet = $character["abnormalityParamSet"]
  let trainingScoreLevelScore = character["trainingScoreLevelScore"].getInt()
  let trainingScoreRankScore = character["trainingScoreRankScore"].getInt()
  let actionPointMax = character["actionPointMax"].getInt()
  let actionPointRate = character["actionPointRate"].getInt()
  let actionPointConsumption = character["actionPointConsumption"].getInt()
  let damageTakenRate = character["damageTakenRate"].getInt()

  db.exec(sql"""
    INSERT INTO characters
    (characterId, exp, hp, attack, defense, maxHp, receivedAt, characterOwnershipType,
     criticalRate, criticalDamageRate, movementSpeed, damageInflictedRate, tensionIncreaseRate,
     cpRecastRate, spGaugeIncreaseRate, attackSpeed, characterCostumeId, abnormalityParamSet,
     trainingScoreLevelScore, trainingScoreRankScore, actionPointMax, actionPointRate,
     actionPointConsumption, damageTakenRate)
    VALUES
    (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
  """, characterId, exp, hp, attack, defense, maxHp, receivedAt, characterOwnershipType,
     criticalRate, criticalDamageRate, movementSpeed, damageInflictedRate, tensionIncreaseRate,
     cpRecastRate, spGaugeIncreaseRate, attackSpeed, characterCostumeId, abnormalityParamSet,
     trainingScoreLevelScore, trainingScoreRankScore, actionPointMax, actionPointRate,
     actionPointConsumption, damageTakenRate
  )

proc removeAreaObject(db: DbConn, areaKeyId: int, triggerId: int) =
  db.exec(sql"DELETE FROM areaObjects WHERE areaId=? AND areaObjectBehaviorId=?", areaKeyId, triggerId);

proc removeAreaEnemy(db: DbConn, areaKeyId: int, triggerId: int) =
  db.exec(sql"DELETE FROM areaEnemies WHERE areaId=? AND areaPointId=?", areaKeyId, triggerId);

proc getBattleFinishAreaObjects(db: DbConn, battleEntryId: int): JsonNode =
  let row = db.getRow(
    sql"SELECT areaObjects FROM battleFinishAreaObjects WHERE battleEntryId = ?", battleEntryId
  )

  return if row[0] != "": parseJson(row[0]) else: nil

proc updateAreaObjects(db: DbConn, areaObjects: JsonNode) =
  for areaObject in areaObjects:
    let areaPointId = areaObject["areaPointId"].getInt()
    let areaId = areaPointId div 1000
    let areaEnemyRateSetId = areaObject.getOrDefault("areaEnemyRateSetId")
    let action = $(areaObject["action"])

    if areaEnemyRateSetId == nil:
      let areaObjectId = areaObject["areaObjectId"].getInt()
      let areaObjectBehaviorId = areaObject["areaObjectBehaviorId"].getInt()

      db.exec(sql"""
        INSERT INTO areaObjects (areaId, areaObjectId, areaPointId, areaObjectBehaviorId, action)
        VALUES (?, ?, ?, ?, ?)
        ON CONFLICT (areaId, areaObjectId) DO
        UPDATE SET areaPointId = excluded.areaPointId,
                  areaObjectBehaviorId = excluded.areaObjectBehaviorId,
                  action = excluded.action
      """, areaId, areaObjectId, areaPointId, areaObjectBehaviorId, action)
    else:
      db.exec(sql"""
        INSERT INTO areaEnemies (areaId, areaPointId, areaEnemyRateSetId, action)
        VALUES (?, ?, ?, ?)
        ON CONFLICT (areaPointId) DO
        UPDATE SET areaEnemyRateSetId = excluded.areaEnemyRateSetId,
                   action = excluded.action
      """, areaId, areaPointId, areaEnemyRateSetId, action)

proc battle_Finish(db: DbConn, lastBattleStartReq: var BattleStartRequest, jsonReq: JsonNode): JsonNode =
  var characterExps = newSeq[JsonNode]()

  for characterUpdate in jsonReq["characterUpdates"]:
    let characterId = characterUpdate["characterId"].getInt()
    let hp = characterUpdate["hp"].getInt()

    setCharacterHp(db, characterId, hp)

    characterExps.add(%*{
      "characterId": characterId,
      # FIXME: calculate exp
      "exp": 154,
      "dropExp": 154
    })

  var areaObjects: JsonNode = nil

  if lastBattleStartReq.val != nil:
    let areaKeyId = lastBattleStartReq.val["currentLocation"]["areaKeyId"].getInt()

    for battleTrigger in lastBattleStartReq.val["battleTriggers"]:
      let triggerType = battleTrigger.getOrDefault("triggerType")
      var isAreaObject = triggerType != nil and triggerType.getStr() == "area_object"
      var isActionSequence = triggerType != nil and triggerType.getStr() == "action_sequence"

      if not isActionSequence:
        for triggerId in battleTrigger["triggerIds"]:
          if isAreaObject:
            removeAreaObject(db, areaKeyId, triggerId.getInt())
          else:
            removeAreaEnemy(db, areaKeyId, triggerId.getInt())

    areaObjects = getBattleFinishAreaObjects(db, lastBattleStartReq.val["battleEntryIds"][0].getInt())

    lastBattleStartReq.val = nil

  let status = getUserStatus(db)

  result = %*{
    "characterExps": characterExps,
    "rewards": [
      {
        "type": 6,
        "contents": [
          {
            "type": 7,
            "id": 50021,
            "quantity": 1,
            "isNew": true
          }
        ]
      }
    ],
    "changedResources": {
      "status": status,
      "characters": getCharacters(db)
    }
  }

  if areaObjects != nil:
    result["areaObjects"] = areaObjects
    updateAreaObjects(db, areaObjects)

proc getGachaNotification(db: DbConn): JsonNode =
  let rows = db.getAllRows(sql"SELECT gachaId FROM gachas")
  var ids = newSeq[int]()

  for row in rows:
    ids.add(parseInt(row[0]))

  return %*{
    "executableGachaIds": ids
  }

proc getNotifications(db: DbConn): JsonNode =
  let gacha = getGachaNotification(db)
  return %*{
    "gacha": gacha,
    "mail": true,
    "itemRequest": false
  }

proc user_CrossDate*(db: DbConn, jsonReq: JsonNode): JsonNode =
  # FIXME: move status loggedInAt update to user_LogIn
  let status = getUserStatus(db)
  let loggedInAt = getDateNow()
  status["loggedInAt"] = %*loggedInAt
  setUserStatus(db, status)
  return %*{
    "changedResources": {
      "status": status,
      "notifications": getNotifications(db)
    }
  }

proc adventure_UpdateCharacterStatus(db: DbConn, jsonReq: JsonNode): JsonNode =
  var changedCharacters = newSeq[JsonNode]()

  for characterUpdate in jsonReq["characterUpdates"]:
    let characterId = characterUpdate["characterId"].getInt()
    let hp = characterUpdate["hp"].getInt()

    setCharacterHp(db, characterId, hp)

    let character = getCharacter(db, characterId)
    changedCharacters.add(character)

  return %*{
    "changedResources": {
      "characters": changedCharacters
    }
  }

proc costumeIdToCharacterId(costumeId: int): int =
  return (costumeId div 1000)*100 + 1

proc character_CostumeUpdate(db: DbConn, jsonReq: JsonNode): JsonNode =
  let costumeId = jsonReq["characterCostumeId"].getInt()
  let characterId = costumeIdToCharacterId(costumeId)
  var characters = newSeq[JsonNode]()

  let character = getCharacter(db, characterId)
  character["characterCostumeId"] = %*costumeId
  characters.add(character)

  db.exec(sql"UPDATE characters SET characterCostumeId = ? WHERE characterId = ?", costumeId, characterId)

  return %*{
    "changedResources": {
      "characters": characters
    }
  }

proc getFormations*(db: DbConn): seq[JsonNode] =
  let formationsRows = db.getAllRows(sql"""
    SELECT number, members, cards FROM formations
  """)

  for formationRow in formationsRows:
    let members = parseJson(formationRow[1])
    let cards = parseJson(formationRow[2])

    var formation = %*{
      "members": members,
      "cards": cards
    }

    let number = parseInt(formationRow[0])

    if number != 0:
      formation["number"] = %*number

    result.add(formation)

proc addChallengeProgress*(db: DbConn, challengeProgress: JsonNode) =
  let challengeProgressId = challengeProgress["challengeProgressId"].getInt()
  let clearedAt = challengeProgress.getOrDefault("clearedAt").getStr()
  let state = challengeProgress["state"].getInt()

  db.exec(sql"""
    INSERT INTO challengeProgresses (challengeProgressId, clearedAt, state)
    VALUES (?, ?, ?)
  """, challengeProgressId, clearedAt, state)

proc getChallengeProgresses*(db: DbConn): seq[JsonNode] =
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

proc addNineSequence*(db: DbConn, nineSequence: JsonNode) =
  let nineSequenceId = nineSequence["nineSequenceId"].getInt()
  let tmp = nineSequence.copy()
  tmp.delete("nineSequenceId")
  let content = $tmp
  db.exec(
    sql"INSERT INTO nineSequences (nineSequenceId, content) VALUES (?, ?)",
    nineSequenceId, content
  )

proc getNineSequences*(db: DbConn): seq[JsonNode] =
  let nineSequencesRows = db.getAllRows(sql"SELECT nineSequenceId, content FROM nineSequences")

  for nineSequenceRow in nineSequencesRows:
    let nineSequenceId = parseInt(nineSequenceRow[0])
    let content = parseJson(nineSequenceRow[1])

    content["nineSequenceId"] = %*nineSequenceId
    
    result.add(content)

proc getTips*(db: DbConn): seq[JsonNode] =
  let tipsRows = db.getAllRows(sql"""
    SELECT tipId, releasedAt
    FROM tips
  """)

  # Lux Phantasma first tip
  result.add(%*{
    "tipId": 3027,
    "releasedAt": "2025-09-10T02:17:06Z"
  })

  for tipRow in tipsRows:
    let tipId = parseInt(tipRow[0])
    let releasedAt = tipRow[1]

    result.add(%*{
      "tipId": tipId,
      "releasedAt": releasedAt
    })

proc getCharacterCostumes(db: DbConn): seq[JsonNode] =
  let characterCostumesRows = db.getAllRows(sql"""
    SELECT characterCostumeId, receivedAt
    FROM characterCostumes
  """)

  for characterCostumeRow in characterCostumesRows:
    let characterCostumeId = parseInt(characterCostumeRow[0])
    let receivedAt = characterCostumeRow[1]

    result.add(%*{
      "characterCostumeId": characterCostumeId,
      "receivedAt": receivedAt
    })

proc addTotalTask*(db: DbConn, totalTask: JsonNode) =
  let conditionId = totalTask["conditionId"].getInt()
  db.exec(sql"INSERT INTO totalTasks (conditionId) VALUES (?)", conditionId)

proc getTotalTasks*(db: DbConn): seq[JsonNode] =
  let totalTasksRows = db.getAllRows(sql"SELECT conditionId FROM totalTasks")
  
  for totalTaskRow in totalTasksRows:
    let conditionId = parseInt(totalTaskRow[0])

    result.add(%*{"conditionId": conditionId})

proc addTutorialState*(db: DbConn, tutorialState: JsonNode) =
  let tutorialStatusKey = tutorialState["tutorialStatusKey"].getInt()
  let enabledTmp = tutorialState.getOrDefault("enabled")
  let enabled = if enabledTmp != nil: (if enabledTmp.getBool(): "true" else: "false") else: ""

  db.exec(
    sql"INSERT INTO tutorialStates (tutorialStatusKey, enabled) VALUES (?, ?)",
    tutorialStatusKey, enabled
  )

proc getTutorialStates*(db: DbConn): seq[JsonNode] =
  let tutorialStatesRows = db.getAllRows(sql"SELECT tutorialStatusKey, enabled FROM tutorialStates")

  for tutorialStateRow in tutorialStatesRows:
    let tutorialStatusKey = parseInt(tutorialStateRow[0])
    let enabled = tutorialStateRow[1]

    let tutorialState = %*{"tutorialStatusKey": tutorialStatusKey}

    if enabled == "true" or enabled == "false":
      tutorialState["enabled"] = %*(if enabled == "true": true else: false)

    result.add(tutorialState)

proc getShopProducts(db: DbConn): seq[JsonNode] =
  let shopProductsRows = db.getAllRows(sql"SELECT val FROM shopProducts")

  for shopProductRow in shopProductsRows:
    result.add(parseJson(shopProductRow[0]))

proc addAdventureVariable*(db: DbConn, adventureVariable: JsonNode) =
  let adventureVariableId = adventureVariable["adventureVariableId"].getInt()
  let value = adventureVariable["value"].getInt()

  db.exec(
    sql"INSERT INTO adventureVariables (adventureVariableId, value) VALUES (?, ?)",
    adventureVariableId, value
  )

proc getAdventureVariables*(db: DbConn): seq[JsonNode] =
  let adventureVariablesRows = db.getAllRows(sql"SELECT adventureVariableId, value FROM adventureVariables")

  for row in adventureVariablesRows:
    let adventureVariableId = parseInt(row[0])
    let value = parseInt(row[1])

    result.add(%*{
      "adventureVariableId": adventureVariableId,
      "value": value
    })

proc addChallengeTask*(db: DbConn, challengeTask: JsonNode) =
  let challengeTaskId = challengeTask["challengeTaskId"].getInt()
  let clearedAt = challengeTask["clearedAt"].getStr()
  let tmpCount = challengeTask.getOrDefault("count")
  let count = if tmpCount != nil: $tmpCount.getInt() else: ""

  db.exec(
    sql"INSERT INTO challengeTasks (challengeTaskId, clearedAt, count) VALUES (?, ?, ?)",
    challengeTaskId, clearedAt, count
  )

proc getChallengeTasks*(db: DbConn): seq[JsonNode] =
  for row in db.getAllRows(sql"SELECT challengeTaskId, clearedAt, count FROM challengeTasks"):
    let challengeTaskId = parseInt(row[0])
    let clearedAt = row[1]
    
    let challengeTask = %*{"challengeTaskId": challengeTaskId, "clearedAt": clearedAt}

    if row[2] != "":
      let count = parseInt(row[2])
      challengeTask["count"] = %*count

    result.add(challengeTask)

proc getChallenges*(db: DbConn): seq[JsonNode] =
  let query = sql"SELECT challengeId, state, clearedAt, expiresAt FROM challenges"

  for row in db.getAllRows(query):
    let challengeId = parseInt(row[0])
    let state = parseInt(row[1])
    let clearedAt = row[2]
    let expiresAt = row[3]

    let challenge = %*{
      "challengeId": challengeId,
      "state": state
    }

    if clearedAt != "":
      challenge["clearedAt"] = %*clearedAt

    if expiresAt != "":
      challenge["expiresAt"] = %*expiresAt

    result.add(challenge)

proc getWarpPoints*(db: DbConn): seq[JsonNode] =
  for row in db.getAllRows(sql"SELECT warpPointId FROM warpPoints"):
    let warpPointId = parseInt(row[0])
    result.add(%*{
      "warpPointId": warpPointId
    })

proc getAreas*(db: DbConn): seq[JsonNode] =
  for row in db.getAllRows(sql"SELECT areaId FROM areas"):
    let areaId = parseInt(row[0])
    result.add(%*{
      "areaId": areaId
    })

proc getAreaGroups*(db: DbConn): seq[JsonNode] =
  for row in db.getAllRows(sql"SELECT areaGroupId FROM areaGroups"):
    let areaGroupId = parseInt(row[0])
    result.add(%*{
      "areaGroupId": areaGroupId
    })

proc getCities*(db: DbConn): seq[JsonNode] =
  for row in db.getAllRows(sql"SELECT cityId, isGearShopReleased, releasedAt FROM cities"):
    let cityId = parseInt(row[0])
    let isGearShopReleased = row[1] == "true"
    let releasedAt = row[2]
    result.add(%*{
      "cityId": cityId,
      "isGearShopReleased": isGearShopReleased,
      "releasedAt": releasedAt
    })

proc getWallet(db: DbConn): JsonNode =
  let freeGemsRow = db.getRow(sql"SELECT val FROM userData WHERE keyName='freeGems'")
  let freeGems = parseInt(freeGemsRow[0])
  let paidGemsRow = db.getRow(sql"SELECT val FROM userData WHERE keyName='paidGems'")
  let paidGems = parseInt(paidGemsRow[0])
  return %*{
    "free": freeGems,
    "paid": paidGems
  }

proc setWallet(db: DbConn, wallet: JsonNode) =
  let freeGems = wallet["free"].getInt()
  let paidGems = wallet["paid"].getInt()
  db.exec(sql"UPDATE userData SET val=? WHERE keyName='freeGems'", $freeGems)
  db.exec(sql"UPDATE userData SET val=? WHERE keyName='paidGems'", $paidGems)

proc user_LogIn*(db: DbConn): JsonNode =
  let formations = getFormations(db)
  let adventureVariables = getAdventureVariables(db)
  let challengeTasks = getChallengeTasks(db)
  let questStates = getQuestStates(db)
  let challenges = getChallenges(db)
  let warpPoints = getWarpPoints(db)
  let areas = getAreas(db)
  let areaGroups = getAreaGroups(db)
  let cities = getCities(db)
  let wallet = getWallet(db)
  let characterPieces = getCharacterPieces(db)

  return %*{
    "resources": {
      "challengeTasks": challengeTasks,
      "adventureVariables": adventureVariables,
      "wallet": wallet,
      "characters": getCharacters(db),
      "status": getUserStatus(db),
      "tensionCards": getTensionCards(db),
      "formations": formations,
      "characterMountingPowerCommon": {},
      "notifications": getNotifications(db),
      "challenges": challenges,
      "challengeProgresses": getChallengeProgresses(db),
      "areas": areas,
      "nineSequences": getNineSequences(db),
      "tips": getTips(db),
      "characterCostumes": getCharacterCostumes(db),
      "missions": [{"missionId": 105002, "count": 1, "clearedAt": "2025-09-10T02:22:53Z"}],
      "totalTasks": getTotalTasks(db),
      "profile": {"name": "Yo Kuronaka3", "profileBannerId": 2010011, "characterLikabilityScale": 500},
      "profileBanners": [{"profileBannerId": 2010011, "receivedAt": "2025-09-10T02:22:51Z"}],
      "tutorialStates": getTutorialStates(db),
      "questStates": questStates,
      "warpPoints": warpPoints,
      "areaGroups": areaGroups,
      "cities": cities,
      "characterPieces": characterPieces,
    },
    "masterData": {"shopProducts": getShopProducts(db)}
  }

proc updateFormation*(db: DbConn, formation: JsonNode) =
  let number = formation.getOrDefault("number").getInt()
  let members = $(formation["members"])
  let cards = $(formation["cards"])

  db.exec(sql"""
    UPDATE formations SET members = ?, cards = ? WHERE number = ?
  """, members, cards, number)

proc formation_Update(db: DbConn, jsonReq: JsonNode): JsonNode =
  updateFormation(db, jsonReq)

  return %*{
    "changedResources": {
      "formations": [
        jsonReq
      ]
    }
  }

proc updateNineSequences(db: DbConn, nineSequences: JsonNode) =
  for nineSequence in nineSequences:
    let nineSequenceId = nineSequence["nineSequenceId"].getInt()
    let seqCopy = nineSequence.copy()
    seqCopy.delete("nineSequenceId")
    let seqCopyStr = $seqCopy

    db.exec(sql"""
      INSERT INTO nineSequences (nineSequenceId, content) VALUES (?, ?)
      ON CONFLICT (nineSequenceId) DO UPDATE SET content = ?
    """, nineSequenceId, seqCopyStr, seqCopyStr)

proc updateAdventureVariables(db: DbConn, adventureVariables: JsonNode) =
  for adventureVariable in adventureVariables:
    let adventureVariableId = adventureVariable["adventureVariableId"].getInt()
    let value = adventureVariable["value"].getInt()

    db.exec(sql"""
      INSERT INTO adventureVariables (adventureVariableId, value) VALUES (?, ?)
      ON CONFLICT (adventureVariableId) DO UPDATE SET value = ?
    """, adventureVariableId, value, value)

proc updateChallengeProgresses(db: DbConn, challengeProgresses: JsonNode) =
  for challengeProgress in challengeProgresses:
    let challengeProgressId = challengeProgress["challengeProgressId"].getInt()
    let clearedAt = challengeProgress.getOrDefault("clearedAt")
    let state = challengeProgress["state"].getInt()

    let clearedAtStr = if clearedAt != nil: clearedAt.getStr() else: ""

    db.exec(sql"""
      INSERT INTO challengeProgresses (challengeProgressId, clearedAt, state)
      VALUES (?, ?, ?)
      ON CONFLICT (challengeProgressId) DO UPDATE SET clearedAt = ?, state = ?
    """, challengeProgressId, clearedAtStr, state, clearedAtStr, state)

proc updateChallengeTasks(db: DbConn, challengeTasks: JsonNode) =
  for challengeTask in challengeTasks:
    let challengeTaskId = challengeTask["challengeTaskId"].getInt()
    let clearedAt = challengeTask["clearedAt"].getStr()
    let count = challengeTask["count"].getInt()

    db.exec(sql"""
      INSERT INTO challengeTasks (challengeTaskId, clearedAt, count)
      VALUES (?, ?, ?)
      ON CONFLICT (challengeTaskId) DO UPDATE SET clearedAt = ?, count = ?
    """, challengeTaskId, clearedAt, count, clearedAt, count)

proc updateChallenges*(db: DbConn, challenges: seq[JsonNode]) =
  for challenge in challenges:
    let challengeId = challenge["challengeId"].getInt()
    let state = challenge["state"].getInt()
    let clearedAt = challenge.getOrDefault("clearedAt").getStr()
    let expiresAt = challenge.getOrDefault("expiresAt").getStr()
    db.exec(sql"""
      INSERT INTO challenges (challengeId, state, clearedAt, expiresAt)
      VALUES (?, ?, ?, ?)
      ON CONFLICT (challengeId) DO
      UPDATE SET state = excluded.state,
                 clearedAt = excluded.clearedAt,
                 expiresAt = excluded.expiresAt
    """, challengeId, state, clearedAt, expiresAt)

proc updateTutorialState(db: DbConn, tutorialStatusKey: int, enabled: bool) =
  db.exec(sql"""
    INSERT INTO tutorialStates (tutorialStatusKey, enabled) VALUES
    (?, ?)
    ON CONFLICT (tutorialStatusKey) DO UPDATE SET enabled = excluded.enabled
  """, tutorialStatusKey, $enabled)

proc addAreaGroup*(db: DbConn, areaGroupId: int) =
  db.exec(sql"""
    INSERT INTO areaGroups (areaGroupId) VALUES
    (?)
    ON CONFLICT (areaGroupId) DO NOTHING
  """, areaGroupId)

proc addCity*(db: DbConn, city: JsonNode) =
  let cityId = city["cityId"].getInt()
  let isGearShopReleased = city.getOrDefault("isGearShopReleased").getBool()
  let releasedAt = city["releasedAt"].getStr()
  db.exec(sql"""
    INSERT INTO cities (cityId, isGearShopReleased, releasedAt)
    VALUES (?, ?, ?)
    ON CONFLICT (cityId) DO UPDATE SET isGearShopReleased = excluded.isGearShopReleased
  """, cityId, isGearShopReleased, releasedAt)

proc updateResources(db: DbConn, changedResources: var JsonNode) =
  var handledKeys = initHashSet[string]()

  if changedResources.getOrDefault("status") != nil:
    handledKeys.incl("status")
    var status = getUserStatus(db)
    updateStatusFromStatusLocation(status, changedResources["status"])
    changedResources["status"] = status
    setUserStatus(db, status);

  let nineSequences = changedResources.getOrDefault("nineSequences")

  if nineSequences != nil:
    handledKeys.incl("nineSequences")
    updateNineSequences(db, nineSequences)

  let adventureVariables = changedResources.getOrDefault("adventureVariables")

  if adventureVariables != nil:
    handledKeys.incl("adventureVariables")
    updateAdventureVariables(db, adventureVariables)

  let challengeProgresses = changedResources.getOrDefault("challengeProgresses")

  if challengeProgresses != nil:
    handledKeys.incl("challengeProgresses")
    updateChallengeProgresses(db, challengeProgresses)

  let challengeTasks = changedResources.getOrDefault("challengeTasks")

  if challengeTasks != nil:
    handledKeys.incl("challengeTasks")
    updateChallengeTasks(db, challengeTasks)

  let challenges = changedResources.getOrDefault("challenges").getElems()
  updateChallenges(db, challenges)

  if challenges.len > 0:
    handledKeys.incl("challenges")

  let tutorialStates = changedResources.getOrDefault("tutorialStates").getElems()

  if tutorialStates.len > 0:
    handledKeys.incl("tutorialStates")

  for tutorialState in tutorialStates:
    let tutorialStatusKey = tutorialState["tutorialStatusKey"].getInt()
    let enabled = tutorialState.getOrDefault("enabled").getBool()
    updateTutorialState(db, tutorialStatusKey, enabled)

  let areaGroups = changedResources.getOrDefault("areaGroups").getElems()

  if areaGroups.len > 0:
    handledKeys.incl("areaGroups")

  for areaGroup in areaGroups:
    let areaGroupId = areaGroup["areaGroupId"].getInt()
    addAreaGroup(db, areaGroupId)

  let cities = changedResources.getOrDefault("cities").getElems()

  if cities.len > 0:
    handledKeys.incl("cities")

  for city in cities:
    addCity(db, city)

  for key, _ in changedResources.pairs():
    if not (key in handledKeys):
      echo("WARNING: " & key & " not handled in updateResources")

proc updateActionSequenceId(db: DbConn, areaId: int, actionSequenceId: int) =
  db.exec(
    sql"UPDATE areaActionSequenceIds SET actionSequenceId = ? WHERE areaId = ?",
    actionSequenceId, areaId
  )

proc getReadSequenceAreaAction(db: DbConn, sequenceRequestId: int): tuple[areaId: int, actionSequenceId: int] =
  let row = db.getRow(
    sql"SELECT areaId, actionSequenceId FROM readSequenceAreaAction WHERE sequenceRequestId = ?",
    sequenceRequestId
  )

  if row[0] == "":
    return (0, 0)

  return (parseInt(row[0]), parseInt(row[1]))

proc getReadSequenceAreaBgm(db: DbConn, seqReqId: int): tuple[areaId: int, id: int, eventName: string] =
  let row = db.getRow(
    sql"SELECT areaId, id, eventName FROM readSequenceAreaBgm WHERE sequenceRequestId = ?",
    seqReqId
  )

  if row[0] == "":
    return (0, 0, "")

  let areaId = parseInt(row[0])
  let id = parseInt(row[1])
  let eventName = row[2]

  return (areaId, id, eventName)

proc updateAreaBgm(db: DbConn, areaId: int, id: int, eventName: string) =
  db.exec(
    sql"UPDATE areaBgm SET id = ?, eventName = ? WHERE areaId = ?",
    id, eventName, areaId
  )

proc readSequenceHandleRow(db: DbConn, row: Row, areaKeyId: int): JsonNode =
  var areaObjects: JsonNode = nil

  if row[0] != "":
    areaObjects = parseJson(row[0])
    updateAreaObjects(db, areaObjects)

  var changedResources = parseJson(row[1]) 
  updateResources(db, changedResources)  

  result = %*{
    "changedResources": changedResources
  }

  if areaObjects != nil:
    result["areaObjects"] = areaObjects

proc adventure_ReadSequence(db: DbConn, jsonReq: JsonNode): JsonNode =
  let sequenceRequestIds = jsonReq.getOrDefault("sequenceRequestIds").getElems()
  let nineSequences = jsonReq.getOrDefault("nineSequences").getElems()
  let areaKeyId = jsonReq["areaKeyId"].getInt()

  if sequenceRequestIds.len > 0:
    let seqReqId = sequenceRequestIds[0].getInt()
    let row = db.getRow(sql"""
      SELECT areaObjects, changedResources FROM readSequence WHERE sequenceRequestId=?
    """, seqReqId);

    result = readSequenceHandleRow(db, row, areaKeyId)

    let readSequenceAreaAction = getReadSequenceAreaAction(db, seqReqId)

    if readSequenceAreaAction.areaId != 0:
      updateActionSequenceId(db, readSequenceAreaAction.areaId, readSequenceAreaAction.actionSequenceId)

    let readSequenceAreaBgm = getReadSequenceAreaBgm(db, seqReqId)

    if readSequenceAreaBgm.areaId != 0:
      updateAreaBgm(db, readSequenceAreaBgm.areaId, readSequenceAreaBgm.id, readSequenceAreaBgm.eventName)
  else:
    let nineSequenceId = nineSequences[0]["id"].getInt()
    let row = db.getRow(sql"""
      SELECT areaObjects, changedResources FROM readSequence WHERE nineSequenceId=?
    """, nineSequenceId);
    result = readSequenceHandleRow(db, row, areaKeyId)

proc getAreaItemRewards(db: DbConn, areaItemId: int): JsonNode =
  let row = db.getRow(sql"SELECT rewards FROM areaItemRewards WHERE areaItemId = ?", areaItemId);

  if row[0] == "":
    raise newException(SembaError, "Couldn't find rewards for areaItemId=" & $areaItemId)

  return parseJson(row[0])

proc adventure_AcquireAreaItem(db: DbConn, jsonReq: JsonNode): JsonNode =
  let areaItemId = jsonReq["areaItemId"].getInt()

  let rewards = getAreaItemRewards(db, areaItemId)

  let changedResources = %*{}

  for reward in rewards:
    doAssert reward["type"].getInt() == 5
    for content in reward["contents"]:
      if content["type"].getInt() == kaneContentType.int:
        # TODO: add kane to kane counter and update changedResources
        doAssert content["id"].getInt() == 1
      elif content["type"].getInt() == charExpContentType.int:
        # TODO: add exp to characters and update changedResources
        doAssert content["id"].getInt() == 1
      else:
        # TODO: add item to inventory and update changedResources
        doAssert content["type"].getInt() == itemContentType.int

  return %*{
    "areaItem": {
      "areaItemId": areaItemId,
      "acquired": true
    },
    "rewards": rewards,
    "changedResources": changedResources
  }

proc xb_Formation(db: DbConn, jsonReq: JsonNode): JsonNode =
  let xbId = jsonReq["xbId"].getInt()

  let row = db.getRow(sql"SELECT content FROM xbFormations WHERE xbId=?", xbId)

  if row[0] == "":
    raise newException(SembaError, "Couldn't find formation for xbId=" & $xbId)

  let res = parseJson(row[0])

  return res

proc getGameInfo(db: DbConn, xbId: int): JsonNode =
  let row = db.getRow(sql"SELECT content FROM xbGameInfos WHERE xbId=?", xbId)

  if row[0] == "":
    raise newException(SembaError, "Couldn't find gameInfo for xbId=" & $xbId)

  return parseJson(row[0])

proc updateGameInfo(db: DbConn, xbId: int, gameInfo: JsonNode) =
  let content = $gameInfo

  db.exec(sql"UPDATE xbGameInfos SET content=? WHERE xbId=?", content, xbId)

proc getStartGameInfo(db: DbConn, xbId: int): JsonNode =
  let row = db.getRow(sql"SELECT content FROM xbStartGameInfos WHERE xbId=?", xbId)

  if row[0] == "":
    raise newException(SembaError, "Couldn't find start gameInfo for xbId=" & $xbId)

  return parseJson(row[0])

proc getTensionData(db: DbConn, tensionFluctuationId: int): TensionData =
  let row = db.getRow(sql"""
    SELECT topTeamDelta, bottomTeamDelta, topTeamSkitIndex, bottomTeamSkitIndex FROM tensionData
    WHERE tensionFluctuationId=?
  """, tensionFluctuationId)

  if row[0] == "":
    raise newException(SembaError, "Couldn't find tensionData for tensionFluctuationId=" & $tensionFluctuationId)

  result.topTeamDelta = parseInt(row[0])
  result.bottomTeamDelta = parseInt(row[1])
  result.topTeamSkitIndex = parseInt(row[2])
  result.bottomTeamSkitIndex = parseInt(row[3])

proc updateCurrentXbPlayDataIdx(db: DbConn, xbId: int, idx: int) =
  db.exec(sql"""
    INSERT INTO currentXbPlayData (xbId, idx) VALUES (?, ?)
    ON CONFLICT (xbId) DO UPDATE SET idx = excluded.idx
  """, xbId, idx)

proc getCurrentXbPlayDataIdx(db: DbConn, xbId: int): int =
  let row = db.getRow(sql"SELECT idx FROM currentXbPlayData WHERE xbId=?", xbId)

  if row[0] == "":
    raise newException(SembaError, "Couldn't find currentXbPlayData idx for xbId=" & $xbId)

  let idx = parseInt(row[0])

  return idx

proc getXbPlayData(
  db: DbConn, xbId: int, idx: int,
  nextAtBatGameInfo: var JsonNode, changedResources: var JsonNode, currentAtBatGameInfo: var JsonNode
) =
  let row = db.getRow(sql"""
    SELECT idx, nextAtBatGameInfo, changedResources, currentAtBatGameInfo
    FROM xbPlayData WHERE xbId=? AND idx=?
  """, xbId, idx)

  if row[0] == "":
    raise newException(SembaError, "Couldn't find xbPlayData for idx=" & $idx & " and xbId=" & $xbId)

  nextAtBatGameInfo = if row[1] != "": parseJson(row[1]) else: nil
  changedResources = if row[2] != "": parseJson(row[2]) else: nil
  currentAtBatGameInfo = parseJson(row[3])

proc popCurrentXbPlayData(
  db: DbConn, xbId: int,
  nextAtBatGameInfo: var JsonNode, changedResources: var JsonNode, currentAtBatGameInfo: var JsonNode
) =
  let idx = getCurrentXbPlayDataIdx(db, xbId)

  getXbPlayData(db, xbId, idx, nextAtBatGameInfo, changedResources, currentAtBatGameInfo)

  updateCurrentXbPlayDataIdx(db, xbId, idx + 1)

proc setGlobalSkitIndex(db: DbConn, skitIndex: int) =
  db.exec(sql"""
    INSERT INTO userData (keyName, val) VALUES ('gSkitIndex', ?)
    ON CONFLICT (keyName) DO UPDATE SET val = excluded.val
  """, skitIndex)

proc getGlobalSkitIndex(db: DbConn): int =
  let row = db.getRow(sql"SELECT val FROM userData WHERE keyName='gSkitIndex'")
  if row[0] == "":
    raise newException(SembaError, "gSkitIndex not set")
  return parseInt(row[0])

proc popGlobalSkitIndex(db: DbConn): int =
  let skitIndex = getGlobalSkitIndex(db)
  setGlobalSkitIndex(db, skitIndex + 1)
  return skitIndex

proc xb_Start(db: DbConn, jsonReq: JsonNode): JsonNode =
  let xbId = jsonReq["xbId"].getInt()

  updateCurrentXbPlayDataIdx(db, xbId, 0)
  setGlobalSkitIndex(db, 0)

  let startGameInfo = getStartGameInfo(db, xbId)
  updateGameInfo(db, xbId, startGameInfo)

  db.exec(sql"""
    INSERT INTO xbGameInfos (xbId, content) VALUES (?, ?)
    ON CONFLICT (xbId) DO UPDATE SET content = excluded.content
  """, xbId, $startGameInfo)

  return %*{
    "nextAtBatGameInfo": startGameInfo
  }

proc calcNewTensionValue(tensionValue: float, delta: float): float = clamp(tensionValue + delta, 0.0, 3.0)
proc isTensionMax(tensionLv: int): bool = tensionLv == 3

proc calcTensionLv(lastTensionLv: int, tensionValue: float): int =
  let delta = tensionValue - lastTensionLv.float
  if delta > 0:
    if delta >= 1:
      result = lastTensionLv + 1
    else:
      result = lastTensionLv
  elif delta < 0:
    let deltaAbs = -delta
    if deltaAbs >= 1:
      result = lastTensionLv - 1
    else:
      result = lastTensionLv
  else:
    result = lastTensionLv

proc addDeltaToTeamTension(delta: float, team: JsonNode) =
  let previousTensionValue = protoJsonGetFloat(team, "tensionValue")
  let tensionValue = calcNewTensionValue(previousTensionValue, delta)
  protoJsonSetFloat(team, "tensionValue", tensionValue)

  let lastTensionLv = protoJsonGetInt(team, "tensionLv")
  let tensionLv = calcTensionLv(lastTensionLv, tensionValue)
  protoJsonSetInt(team, "tensionLv", tensionLv)

  let isTensionMax = isTensionMax(tensionLv)
  protoJsonSetBool(team, "isTensionMax", isTensionMax)

proc addDeltaToTensionInfo(delta: float, tensionInfo: JsonNode) =
  let previousTensionValue = protoJsonGetFloat(tensionInfo, "tensionValue")
  let tensionValue = calcNewTensionValue(previousTensionValue, delta)
  protoJsonSetFloat(tensionInfo, "tensionValue", tensionValue)

  let previousTensionLv = protoJsonGetInt(tensionInfo, "tensionLv")
  let tensionLv = calcTensionLv(previousTensionLv, tensionValue)
  protoJsonSetInt(tensionInfo, "tensionLv", tensionLv)

  protoJsonSetBool(tensionInfo, "isTensionMax", isTensionMax(tensionLv))

proc findTensionInfo(tensionInfos: seq[JsonNode], isPlayerTeam: bool): JsonNode =
  for tensionInfo in tensionInfos:
    let isPlayer = protoJsonGetBool(tensionInfo, "isPlayer")
    if isPlayer == isPlayerTeam:
      return tensionInfo
  return nil

proc updateTeamTension(delta: float, team: JsonNode, currentAtBatGameInfo: JsonNode, skitIndex: int): JsonNode =
  let isPlayerTeam = protoJsonGetBool(team, "isPlayerTeam")

  let previousTensionLv = protoJsonGetInt(team, "tensionLv")
  let previousTensionValue = protoJsonGetFloat(team, "tensionValue")

  addDeltaToTeamTension(delta, team)

  var predictedTensionInfos: JsonNode = currentAtBatGameInfo["predictedTensionInfos"]

  for tensionInfo in predictedTensionInfos.items():
    let isPlayer = protoJsonGetBool(tensionInfo, "isPlayer")
    if isPlayerTeam == isPlayer:
      addDeltaToTensionInfo(delta.float, tensionInfo)
      if tensionInfo["commandId"].getInt() == 1100044:
        addDeltaToTensionInfo(-0.55, tensionInfo)

  let logicEventInfos = currentAtBatGameInfo["currentAtBatEventInfo"]["logicEventInfos"]
  var tensionInfos = logicEventInfos[3].getOrDefault("tensionInfos").getElems()
  let match = findTensionInfo(tensionInfos, isPlayerTeam)
  let tensionInfo = if match != nil: match else: %*{}

  tensionInfo["skitIndex"] = %*skitIndex
  protoJsonSetFloat(tensionInfo, "previousTensionValue", previousTensionValue)
  protoJsonSetInt(tensionInfo, "previousTensionLv", previousTensionLv)
  protoJsonSetFloat(tensionInfo, "tensionValue", protoJsonGetFloat(team, "tensionValue"))
  protoJsonSetInt(tensionInfo, "tensionLv", protoJsonGetInt(team, "tensionLv"))
  protoJsonSetBool(tensionInfo, "isTensionMax", protoJsonGetBool(team, "isTensionMax"))
  protoJsonSetBool(tensionInfo, "isPlayer", isPlayerTeam)

  if match == nil:
    tensionInfos.add(tensionInfo)
    currentAtBatGameInfo["currentAtBatEventInfo"]["logicEventInfos"][3]["tensionInfos"] = %*tensionInfos

  return %*[tensionInfo]

proc updateTension(
  db: DbConn, tensionFluctuationId: int, currentAtBatGameInfo: JsonNode,
  playerTensionInfos: var JsonNode, enemyTensionInfos: var JsonNode
) =
  let tensionData = getTensionData(db, tensionFluctuationId)

  var topTeam = currentAtBatGameInfo["topTeam"]
  var bottomTeam = currentAtBatGameInfo["bottomTeam"]

  if tensionData.topTeamDelta != 0:
    let tensionInfos = updateTeamTension(
      tensionData.topTeamDelta.float, topTeam, currentAtBatGameInfo, tensionData.topTeamSkitIndex
    )
    let isPlayerTeam = topTeam.getOrDefault("isPlayerTeam").getBool()
    if isPlayerTeam:
      playerTensionInfos = tensionInfos
    else:
      enemyTensionInfos = tensionInfos

  if tensionData.bottomTeamDelta != 0:
    let tensionInfos = updateTeamTension(
      tensionData.bottomTeamDelta.float, bottomTeam, currentAtBatGameInfo, tensionData.bottomTeamSkitIndex
    )
    let isPlayerTeam = bottomTeam.getOrDefault("isPlayerTeam").getBool()
    if isPlayerTeam:
      playerTensionInfos = tensionInfos
    else:
      enemyTensionInfos = tensionInfos

proc xb_UpdateTension(db: DbConn, jsonReq: JsonNode): JsonNode =
  let xbId = jsonReq["xbId"].getInt()
  let tensionFluctuationIds = jsonReq["tensionFluctuationIds"]

  if tensionFluctuationIds.len != 1:
    raise newException(SembaError, "tensionFluctuationIds.len != 1")

  let tensionFluctuationId = tensionFluctuationIds[0].getInt()

  let gameInfo = getGameInfo(db, xbId)

  var playerTensionInfos: JsonNode = nil
  var enemyTensionInfos: JsonNode = nil

  updateTension(db, tensionFluctuationId, gameInfo, playerTensionInfos, enemyTensionInfos)
  
  updateGameInfo(db, xbId, gameInfo)

  result = %*{
    "currentAtBatGameInfo": gameInfo,
  }

  if playerTensionInfos != nil:
    result["playerTensionInfos"] = playerTensionInfos.copy()
    if tensionFluctuationId != 10001:
      result["playerTensionInfos"][0]["skitIndex"] = %*popGlobalSkitIndex(db)

  if enemyTensionInfos != nil:
    result["enemyTensionInfos"] = enemyTensionInfos.copy()
    if tensionFluctuationId != 10001:
      result["enemyTensionInfos"][0]["skitIndex"] = %*popGlobalSkitIndex(db)

proc battedBallPredictionIdToPosition(battedBallPredictionId: int): int =
  case battedBallPredictionId:
    of 1:
      return 7
    of 2:
      return 8
    of 3:
      return 9
    else:
      raise newException(SembaError, "Unknown battedBallPredictionId: " & $battedBallPredictionId)

proc isPlayerOffense(currentAtBatEventInfo: JsonNode): bool =
  return protoJsonGetBool(currentAtBatEventInfo["afterGameSituation"], "isPlayerOffense")

proc isIncorrectCommand(selectedCommand: JsonNode): bool =
  return selectedCommand.getOrDefault("correctType").getStr() == "incorrect_command"

proc handleCorrectCommand(
  currentAtBatEventInfo: JsonNode, afterGameSituation: JsonNode,
  fakeCurrentAtBatEventInfo: JsonNode, selectedCommand: JsonNode
) =
  let batterMemberId = afterGameSituation["batterMemberId"].getInt()

  var newCurrentBaseSituation = afterGameSituation["currentBaseSituation"].getElems()

  let newCurrentBaseSituation3 = newCurrentBaseSituation[2]
  newCurrentBaseSituation[2] = newCurrentBaseSituation[1]
  newCurrentBaseSituation[1] = newCurrentBaseSituation[0]
  newCurrentBaseSituation[0] = %*batterMemberId

  let runningInfoMemberIds = @[
    newCurrentBaseSituation[0],
    newCurrentBaseSituation[1],
    newCurrentBaseSituation[2],
    newCurrentBaseSituation3
  ]

  let time = 1.76481688

  var lastRunningInfoMemberId = 0

  var runningInfos = newSeq[JsonNode]()

  for i in 0 ..< runningInfoMemberIds.len:
    let memberId = runningInfoMemberIds[i].getInt()

    if memberId != 0:
      let endPosition = i.float + 0.123843156

      lastRunningInfoMemberId = memberId

      runningInfos.add(%*{
        "memberId": memberId,
        "startPosition": i,
        "endPosition": endPosition,
        "velocity": 0.340174,
        "time": time
      })
    else:
      runningInfos.add(%*{})

  let direction = battedBallPredictionIdToPosition(selectedCommand["battedBallPredictionId"].getInt())

  let battedBallInfo = %*{
    "afterGameSituation": afterGameSituation.copy(),
    "direction": direction,
    "fielderMemberId": 17, # always?
    "runningInfos": runningInfos,
    "time": time
  }

  currentAtBatEventInfo["battedBallInfo"] = battedBallInfo

  afterGameSituation["currentBaseSituation"] = %*newCurrentBaseSituation

  currentAtBatEventInfo["buffInfos"] = %*[{"timing": 80, "playerBuffMemberIds": [51]}]
  currentAtBatEventInfo["logicEventInfos"] = fakeCurrentAtBatEventInfo["logicEventInfos"]

  var defenseRunningInfos = newSeq[JsonNode]()

  var lastDefenseRunningPosition = 0

  for runningInfo in runningInfos:
    let memberId = runningInfo.getOrDefault("memberId").getInt()
    if memberId != 0:
      let startPosition = runningInfo["endPosition"].getFloat()
      let endPosition = ceil(startPosition)
      lastDefenseRunningPosition = endPosition.int
      defenseRunningInfos.add(%*{
        "memberId": memberId,
        "startPosition": startPosition,
        "endPosition": endPosition,
        "velocity": 0.340174,
        "time": 10.9274044
      })
    else:
      defenseRunningInfos.add(%*{})

  let fielderMemberIdTo = 14 # FIXME: get it from topTeam members

  var baseAdvanceInfos = newSeq[JsonNode]()

  for i in 0 ..< newCurrentBaseSituation.len:
    let memberId = newCurrentBaseSituation[i].getInt()
    if memberId != 0:
      baseAdvanceInfos.add(%*{
        "isPlayer": true,
        "memberId": memberId,
        "baseNum": i + 1,
      })

  let defenseBeforeGameSituation = battedBallInfo["afterGameSituation"].copy()
  let defenseAfterGameSituation = afterGameSituation.copy()

  defenseBeforeGameSituation["eventOrder"] = %*1
  defenseAfterGameSituation["eventOrder"] = %*1

  currentAtBatEventInfo["defenseInfos"] = %*[
    {
      "targetRunnerMemberId": lastRunningInfoMemberId,
      "defenseOwnBaseInfo": {},
      "throwingInfo": {
        "isThrown": true,
        "positionFrom": direction,
        "ballLevel": 1,
        "baseNumOfReceive": lastDefenseRunningPosition,
        "time": 0.0136560118,
        "fielderMemberIdFrom": 17, # FIXME: get it from topTeam members
        "fielderMemberIdTo": fielderMemberIdTo
      },
      "runningInfos": defenseRunningInfos,
      "boutInfo": {
        "boutOccurred": true,
        "baseNumOfBout": lastDefenseRunningPosition,
        "runnerMemberId": batterMemberId,
        "fielderMemberId": fielderMemberIdTo,
        "baseAdvanceInfos": baseAdvanceInfos,
      },
      "beforeGameSituation": defenseBeforeGameSituation,
      "afterGameSituation": defenseAfterGameSituation,
      "eventOrder": 1,
    }
  ]

proc getCommand(zoneAreaIndex: int, currentAtBatGameInfo: JsonNode): JsonNode =
  for zoneArea in currentAtBatGameInfo["bottomTeam"]["zoneAreas"]:
    if protoJsonGetInt(zoneArea, "index") == zoneAreaIndex:
      result = zoneArea["commands"][0]
      break

  if result == nil:
    raise newException(SembaError, "Couldn't get command for zoneArea: " & $zoneAreaIndex)

proc handleIncorrectCommand(
  currentAtBatEventInfo: JsonNode, afterGameSituation: JsonNode, fakeCurrentAtBatEventInfo: JsonNode
) =
  let battingInfo = currentAtBatEventInfo["battingInfo"]

  let currentOutCount = protoJsonGetInt(afterGameSituation, "currentOutCount") + 1
  protoJsonSetInt(afterGameSituation, "currentOutCount", currentOutCount)

  if currentOutCount == 3:
    protoJsonSetBool(afterGameSituation, "isChange", true)

  protoJsonSetBool(battingInfo, "isStrikeOut", true)

  currentAtBatEventInfo["logicEventInfos"] = fakeCurrentAtBatEventInfo["logicEventInfos"].copy()

  for eventInfo in currentAtBatEventInfo["logicEventInfos"]:
    protoJsonDeleteKey(eventInfo, "tensionInfos")

  currentAtBatEventInfo["battedBallInfo"] = %*{}

proc createCurrentAtBatGameInfo(
  zoneAreaIndex: int, lastCurrentAtBatGameInfo: JsonNode, fakeCurrentAtBatGameInfo: JsonNode
): JsonNode =
  let selectedCommand = getCommand(zoneAreaIndex, lastCurrentAtBatGameInfo)

  let lastCurrentAtBatEventInfo = lastCurrentAtBatGameInfo["currentAtBatEventInfo"]

  # zero is batting...
  if not isPlayerOffense(lastCurrentAtBatEventInfo):
    result = fakeCurrentAtBatGameInfo.copy()
    result["bottomTeam"]["selectedCommand"] = selectedCommand
    return result

  result = lastCurrentAtBatGameInfo.copy()
  result["bottomTeam"]["selectedCommand"] = selectedCommand
  result["bottomTeam"]["inningScores"] = fakeCurrentAtBatGameInfo["bottomTeam"]["inningScores"]

  let fakeCurrentAtBatEventInfo = fakeCurrentAtBatGameInfo["currentAtBatEventInfo"]
  let fakeAfterGameSituation = fakeCurrentAtBatEventInfo["afterGameSituation"]
  let isGameSet = protoJsonGetBool(fakeAfterGameSituation, "isGameSet")

  let currentAtBatEventInfo = result["currentAtBatEventInfo"]
  let afterGameSituation = currentAtBatEventInfo["afterGameSituation"]
  protoJsonSetBool(afterGameSituation, "isGameSet", isGameSet)

  let battingInfo = currentAtBatEventInfo["battingInfo"]
  protoJsonSetBool(battingInfo, "isStrikeOut", false)

  protoJsonDeleteKey(result, "predictedTensionInfos")

  if isIncorrectCommand(selectedCommand):
    handleIncorrectCommand(currentAtBatEventInfo, afterGameSituation, fakeCurrentAtBatEventInfo)
  else:
    handleCorrectCommand(currentAtBatEventInfo, afterGameSituation,
                         fakeCurrentAtBatEventInfo, selectedCommand)

proc createNextAtBatGameInfo(currentAtBatGameInfo: JsonNode, fakeNextAtBatGameInfo: JsonNode): JsonNode =
  # zero is batting...
  if not isPlayerOffense(currentAtBatGameInfo["currentAtBatEventInfo"]):
    return fakeNextAtBatGameInfo.copy()

  result = currentAtBatGameInfo.copy()

  let fakeBottomTeam = fakeNextAtBatGameInfo["bottomTeam"]
  let bottomTeam = result["bottomTeam"]
  protoJsonDeleteKey(bottomTeam, "selectedCommand")

  bottomTeam["zoneAreas"] = fakeBottomTeam["zoneAreas"].copy()
  bottomTeam["currentBattingOrder"] = fakeBottomTeam["currentBattingOrder"]

  let currentAtBatEventInfo = result["currentAtBatEventInfo"]
  let afterGameSituation = currentAtBatEventInfo["afterGameSituation"]

  let fakeCurrentAtBatEventInfo = fakeNextAtBatGameInfo["currentAtBatEventInfo"]
  let fakeAfterGameSituation = fakeCurrentAtBatEventInfo["afterGameSituation"]

  afterGameSituation["batterMemberId"] = fakeAfterGameSituation["batterMemberId"]
  afterGameSituation["pitcherMemberId"] = fakeAfterGameSituation["pitcherMemberId"]

  protoJsonSetInt(
    currentAtBatEventInfo, "inning", protoJsonGetInt(fakeCurrentAtBatEventInfo, "inning")
  )
  protoJsonSetBool(
    currentAtBatEventInfo, "isChange", protoJsonGetBool(fakeCurrentAtBatEventInfo, "isChange")
  )
  protoJsonSetBool(
    currentAtBatEventInfo, "isFirstAtBatInGame",
    protoJsonGetBool(fakeCurrentAtBatEventInfo, "isFirstAtBatInGame")
  )
  protoJsonSetBool(
    currentAtBatEventInfo, "isFirstAtBatInHalfInning",
    protoJsonGetBool(fakeCurrentAtBatEventInfo, "isFirstAtBatInHalfInning")
  )
  protoJsonSetBool(
    currentAtBatEventInfo, "isTop", protoJsonGetBool(fakeCurrentAtBatEventInfo, "isTop")
  )

  let clientStatus = result["clientStatus"]

  currentAtBatEventInfo["battedBallInfo"] = %*{}

  let battingInfo = currentAtBatEventInfo["battingInfo"]

  let beforeGameSituation = currentAtBatEventInfo["beforeGameSituation"]
  let fakeBeforeGameSituation = fakeCurrentAtBatEventInfo["beforeGameSituation"]

  if protoJsonGetBool(battingInfo, "isStrikeOut"):
    protoJsonDeleteKey(battingInfo, "isStrikeOut")
    clientStatus["previousAtBatIsOut"] = %*true
    protoJsonSetInt(
      beforeGameSituation, "currentOutCount",
      protoJsonGetInt(beforeGameSituation, "currentOutCount") + 1
    )
  else:
    var currentBaseSituation = beforeGameSituation["currentBaseSituation"].getElems()
    currentBaseSituation[2] = currentBaseSituation[1]
    currentBaseSituation[1] = currentBaseSituation[0]
    currentBaseSituation[0] = beforeGameSituation["batterMemberId"]
    beforeGameSituation["currentBaseSituation"] = %*currentBaseSituation 

  beforeGameSituation["batterMemberId"] = fakeBeforeGameSituation["batterMemberId"]
  beforeGameSituation["pitcherMemberId"] = fakeBeforeGameSituation["pitcherMemberId"]

  protoJsonSetInt(
    beforeGameSituation, "inning", protoJsonGetInt(fakeBeforeGameSituation, "inning")
  )
  protoJsonSetBool(
    beforeGameSituation, "isChange", protoJsonGetBool(fakeBeforeGameSituation, "isChange")
  )
  protoJsonSetBool(
    beforeGameSituation, "isFirstAtBatInGame",
    protoJsonGetBool(fakeBeforeGameSituation, "isFirstAtBatInGame")
  )
  protoJsonSetBool(
    beforeGameSituation, "isFirstAtBatInHalfInning",
    protoJsonGetBool(fakeBeforeGameSituation, "isFirstAtBatInHalfInning")
  )
  protoJsonSetBool(
    beforeGameSituation, "isTop", protoJsonGetBool(fakeBeforeGameSituation, "isTop")
  )

  protoJsonDeleteKey(currentAtBatEventInfo, "defenseInfos")
  protoJsonDeleteKey(currentAtBatEventInfo, "buffInfos")
  
  currentAtBatEventInfo["logicEventInfos"] = fakeCurrentAtBatEventInfo["logicEventInfos"]
  result["index"] = fakeNextAtBatGameInfo["index"]
  result["predictedTensionInfos"] = fakeNextAtBatGameInfo["predictedTensionInfos"]

  let topTeam = result["topTeam"]
  let fakeTopTeam = fakeNextAtBatGameInfo["topTeam"]

  topTeam["members"] = fakeTopTeam["members"]
  topTeam["selectedCommand"] = fakeTopTeam["selectedCommand"]
  topTeam["skillOrbInfos"] = fakeTopTeam["skillOrbInfos"]

  result["xbStoryInfo"] = fakeNextAtBatGameInfo["xbStoryInfo"]

proc xb_Play(db: DbConn, jsonReq: JsonNode): JsonNode =
  let xbId = jsonReq["xbId"].getInt()
  let zoneAreaIndex = jsonReq["zoneAreaIndex"].getInt()

  var fakeNextAtBatGameInfo: JsonNode = nil
  var changedResources: JsonNode = nil
  var fakeCurrentAtBatGameInfo: JsonNode = nil
  popCurrentXbPlayData(db, xbId, fakeNextAtBatGameInfo, changedResources, fakeCurrentAtBatGameInfo)

  let lastCurrentAtBatGameInfo = getGameInfo(db, xbId)
  
  let currentAtBatGameInfo = createCurrentAtBatGameInfo(zoneAreaIndex, lastCurrentAtBatGameInfo, fakeCurrentAtBatGameInfo)
  
  var nextAtBatGameInfo: JsonNode = nil

  if fakeNextAtBatGameInfo != nil:
    nextAtBatGameInfo = createNextAtBatGameInfo(currentAtBatGameInfo, fakeNextAtBatGameInfo)
    updateGameInfo(db, xbId, nextAtBatGameInfo)

  result = %*{
    "currentAtBatGameInfo": currentAtBatGameInfo,
  }

  if nextAtBatGameInfo != nil:
    result["nextAtBatGameInfo"] = nextAtBatGameInfo

  if changedResources != nil:
    updateResources(db, changedResources)
    result["changedResources"] = changedResources

  if protoJsonGetBool(currentAtBatGameInfo["currentAtBatEventInfo"]["afterGameSituation"], "isGameSet"):
    result["result"] = %*"xb_result_lost" # xbId == 10001

proc user_Notification(db: DbConn): JsonNode =
  let notifications = getNotifications(db)
  return %*{
    "changedResources": {
      "notifications": notifications
    }
  }

#[
Set the characters hp to max in the database and return the characters with
changed hp.
]#
proc healCharacters(db: DbConn): seq[JsonNode] =
  let characters = getCharacters(db)

  for character in characters:
    let characterId = character["characterId"].getInt()
    let hp = character["hp"].getInt()
    let maxHp = character["maxHp"].getInt()
    if hp != maxHp:
      setCharacterHp(db, characterId, maxHp)
      character["hp"] = %*maxHp
      result.add(character)

proc adventure_Hospital(db: DbConn): JsonNode =
  let status = getUserStatus(db)
  let changedCharacters = healCharacters(db)

  return %*{
    "changedResources": {
      "characters": changedCharacters,
      "status": status
    }
  }

proc getTutorialState(db: DbConn, tutorialStatusKey: int): bool =
  let row = db.getRow(sql"SELECT enabled FROM tutorialStates WHERE tutorialStatusKey=?", tutorialStatusKey)

  if row[0] == "":
    return false

  return row[0] == "true"

proc hasWarpPoint(db: DbConn, warpPointId: int): bool =
  let row = db.getRow(sql"SELECT warpPointId FROM warpPoints WHERE warpPointId=?", warpPointId)
  return row[0] != ""

proc addWarpPoint*(db: DbConn, warpPointId: int) =
  db.exec(sql"""
    INSERT INTO warpPoints (warpPointId) VALUES (?)
    ON CONFLICT (warpPointId) DO NOTHING
  """, warpPointId)

proc adventure_AccessWarpPoint(db: DbConn, jsonReq: JsonNode): JsonNode =
  let warpPointId = jsonReq["warpPointId"].getInt()

  var changedTutorialStates = newSeq[JsonNode]()
  var changedWarpPoints = newSeq[JsonNode]()
  let status = getUserStatus(db)

  if not getTutorialState(db, respiteUnitTutorialStatusKey):
    updateTutorialState(db, respiteUnitTutorialStatusKey, true)
    changedTutorialStates.add(%*{
      "tutorialStatusKey": respiteUnitTutorialStatusKey,
      "enabled": true
    })

  if not hasWarpPoint(db, warpPointId):
    addWarpPoint(db, warpPointId)
    changedWarpPoints.add(%*{
      "warpPointId": warpPointId
    })

  # TODO: update also missions (zero sensei?), areaObjects and guestCharacters

  return %*{
    "changedResources": {
      "warpPoints": changedWarpPoints,
      "tutorialStates": changedTutorialStates,
      "status": status
    }
  }

proc news_UserList(): JsonNode =
  result = %*{
    "news": [
      {
        "newsGroupId": 1000516,
        "priority": 1000584,
        "category": 1,
        "title": "[Updated 4/24] Instructions for Adjusting Graphic Settings",
        "startAt": "2025-04-24T08:00:00Z",
        "editedAt": "2025-04-18T03:00:00Z"
      },
      {
        "newsGroupId": 1002945,
        "priority": 1000270,
        "category": 4,
        "title": "Standard Synchro \"Embarking Companionship\" - Now Available!",
        "startAt": "2025-04-18T03:00:00Z",
        "editedAt": "2025-02-26T07:00:00Z"
      },
      {
        "newsGroupId": 1002955,
        "priority": 1003014,
        "category": 2,
        "title": "[Updated 4/25]  Regarding Currently Known Issues",
        "startAt": "2025-04-25T11:25:00Z",
        "editedAt": "2025-02-20T02:00:00Z"
      }
    ]
  }

proc characterIdToCostumeId(characterId: int): int = (characterId div 100)*1000 + 1

proc getGachaCharacterIds(db: DbConn): seq[int] =
  let rows = db.getAllRows(sql"SELECT characterId FROM gachaCharacterIds")
  for row in rows:
    result.add(parseInt(row[0]))

proc getGachaCharacters(db: DbConn): seq[JsonNode] =
  let characterIds = getGachaCharacterIds(db)

  for characterId in characterIds:
    let costumeId = characterIdToCostumeId(characterId)
    result.add(%*{
      "characterId": characterId,
      "characterCostumeId": costumeId,
      "exp": 4490000,
      "hp": 1662, # FIXME: correct hp
      "attack": 406, # FIXME: correct attack
      "defense": 282, # FIXME: correct defense
      "maxHp": 1662, # FIXME: corrent maxHp
      "receivedAt": getDateNow(),
      "characterOwnershipType": 1,
      "criticalRate": 5,
      "criticalDamageRate": 50,
      "movementSpeed": 6,
      "damageInflictedRate": 100,
      "tensionIncreaseRate": 100,
      "cpRecastRate": 100,
      "spGaugeIncreaseRate": 100,
      "attackSpeed": 100,
      "abnormalityParamSet": {
        "oily": {
          "burstResistance": 100,
          "burstResistanceLimit": 100
        },
        "pressure": {
          "burstResistance": 100,
          "burstResistanceLimit": 100
        },
        "scared": {
          "burstResistance": 100,
          "burstResistanceLimit": 100
        },
        "electric": {
          "burstResistance": 100,
          "burstResistanceLimit": 100
        },
        "unfortified": {
          "burstResistance": 100,
          "burstResistanceLimit": 100
        }
      },
      "actionPointMax": 1000,
      "actionPointRate": 3000,
      "actionPointConsumption": 160,
      "damageTakenRate": 1
    })

proc getGachaButtonStates(db: DbConn, gachaId: int): seq[JsonNode] =
  let rows = db.getAllRows(sql"""
    SELECT gachaButtonId, executionCount, lastExecutedAt FROM gachaButtonStates
    WHERE gachaId=?
  """, gachaId)

  for row in rows:
    let gachaButtonId = parseInt(row[0])
    let executionCount = parseInt(row[1])
    let lastExecutedAt = row[2]

    let gachaButtonState = %*{
      "gachaId": gachaId,
      "gachaButtonId": gachaButtonId,
      "executionCount": executionCount,
    }

    if lastExecutedAt != "":
      gachaButtonState["lastExecutedAt"] = %*lastExecutedAt

    result.add(gachaButtonState)

proc parseGachaRow(db: DbConn, row: Row): JsonNode =
  let gachaId = parseInt(row[0])
  let gachaCategoryId = parseInt(row[1])
  let guaranteedCount = parseInt(row[2])
  let isGuaranteedPickup = row[3] == "true"
  let executionCount = parseInt(row[4])
  let isSelectable = row[5] == "true"
  let gachaButtonStates = getGachaButtonStates(db, gachaId)

  return %*{
    "gachaId": gachaId,
    "gachaButtonStates": gachaButtonStates,
    "gachaCategoryState": {
      "gachaCategoryId": gachaCategoryId,
      "guaranteedCount": guaranteedCount,
      "isGuaranteedPickup": isGuaranteedPickup,
      "executionCount": executionCount,
      "isSelectable": isSelectable
    }
  }

proc getGachas(db: DbConn): seq[JsonNode] =
  let rows = db.getAllRows(sql"""
    SELECT gachaId, gachaCategoryId, guaranteedCount, isGuaranteedPickup, executionCount, isSelectable
    FROM gachas
  """)

  for row in rows:
    result.add(parseGachaRow(db, row))

proc getGachaRateSetIds(db: DbConn): seq[int] =
  let rows = db.getAllRows(sql"SELECT DISTINCT gachaRateSetId FROM gachaRates")
  for row in rows:
    result.add(parseInt(row[0]))

proc getGachaRateCards(db: DbConn, gachaRateId: int): seq[JsonNode] =
  let rows = db.getAllRows(sql"""
    SELECT cardType, cardId, isAttention, isSelectable, gachaCardId FROM gachaCards
    WHERE gachaRateId=?
  """, gachaRateId)

  for row in rows:
    let cardType = parseInt(row[0])
    let cardId = parseInt(row[1])
    let isAttention = row[2] == "true"
    let isSelectable = row[3] == "true"
    let gachaCardId = parseInt(row[4])
    result.add(%*{
      "cardType": cardType,
      "cardId": cardId,
      "isAttention": isAttention,
      "isSelectable": isSelectable,
      "gachaCardId": gachaCardId
    })

proc getGachaRateSetRows(db: DbConn, gachaRateSetId: int): seq[JsonNode] =
  let rows = db.getAllRows(sql"""
    SELECT gachaRateId, percentRate FROM gachaRates
    WHERE gachaRateSetId=?
  """, gachaRateSetId)

  for row in rows:
    let gachaRateId = parseInt(row[0])
    let percentRate = row[1]
    let cards = getGachaRateCards(db, gachaRateId)
    let percentRatePerCard = $(parseFloat(percentRate)/cards.len.float)
    result.add(%*{
      "gachaRateId": gachaRateId,
      "percentRate": percentRate,
      "percentRatePerCard": percentRatePerCard,
      "cards": cards
    })

proc getGachaRateSets(db: DbConn): seq[JsonNode] =
  for gachaRateSetId in getGachaRateSetIds(db):
    let rows = getGachaRateSetRows(db, gachaRateSetId)
    result.add(%*{
      "gachaRateSetId": gachaRateSetId,
      "rows": rows
    })

proc gacha_List(db: DbConn): JsonNode =
  let gachas = getGachas(db)
  let gachaCharacters = getGachaCharacters(db)
  let gachaNotification = getGachaNotification(db)
  let gachaRateSets = getGachaRateSets(db)

  return %*{
    "gachas": gachas,
    "gachaCharacters": gachaCharacters,
    "gachaRateSets": gachaRateSets,
    "changedResources": {
      "notifications": {
        "gacha": gachaNotification
      }
    }
  }

proc getGacha(db: DbConn, gachaId: int): JsonNode =
  let row = db.getRow(sql"""
    SELECT gachaId, gachaCategoryId, guaranteedCount, isGuaranteedPickup, executionCount, isSelectable
    FROM gachas
    WHERE gachaId=?
  """, gachaId)

  if row[0] == "":
    raise newException(SembaError, "Couldn't find gacha for gachaId=" & $gachaId)

  return parseGachaRow(db, row)

proc gachaButtonToPulls(gachaButtonId: int): int =
  case gachaButtonId.GachaButton:
    of gachaButtonSingle:
      result = 1
    of gachaButtonTen:
      result = 10

let enigmaticRemnentId = 105

proc popEntityId(db: DbConn): int =
  let row = db.getRow(sql"SELECT val FROM userData WHERE keyName='nextEntityId'")
  result = parseInt(row[0])
  db.exec(sql"UPDATE userData SET val=? WHERE keyName='nextEntityId'", $(result + 1))

proc getRewardFromCard(db: DbConn, card: JsonNode): JsonNode =
  let cardType = card["cardType"].getInt()
  let cardId = card["cardId"].getInt()

  if cardType == gachaCardCharacter.int:
    result = %*{
      "type": rewardCharacter.int,
      "id": cardId,
      "quantity": 1,
      "otherRewards": [
        # FIXME: check if character exists in db and don't give more pieces at max dupes
        {"type": rewardCharacterPiece.int, "id": cardId, "quantity": 1},
        # FIXME: check character rarity and give the other type of remnent
        {"type": rewardItem.int, "id": enigmaticRemnentId, "quantity": 20}
      ]
    }
  elif cardType == gachaCardTensionCard.int:
    let entityId = popEntityId(db)
    result = %*{
      "type": rewardTensionCard.int,
      "id": cardId,
      "quantity": 1,
      "entityId": entityId,
      # FIXME: check if tension card exists and set a correct value
      "isNew": true
    }
  else:
    raise newException(SembaError, "Invalid cardType=" & $cardType)

proc getGachaRateSetForPull(
  gachaCategoryState: JsonNode, pullIdx: int, pulls: int, isPromised: bool, gachaRateSets: seq[JsonNode]
): JsonNode =
  var gachaRateSetId: GachaRateSetId
  if gachaCategoryState.getOrDefault("isGuaranteedPickup").getBool():
    gachaRateSetId = guaranteedGachaRateSetId
  elif pullIdx == pulls - 1 and isPromised:
    gachaRateSetId = promisedGachaRateSetId
  else:
    gachaRateSetId = normalGachaRateSetId

  for gachaRateSet in gachaRateSets:
    if gachaRateSet["gachaRateSetId"].getInt() == gachaRateSetId.int:
      result = gachaRateSet

  if result == nil:
    raise newException(SembaError, "Couldn't find gachaRateSet for gachaRateSetId=" & $gachaRateSetId)

proc pickCard(gachaRateSet: JsonNode): JsonNode =
  let choice = rand(100.0)

  var base: float = 0.0

  for gachaRate in gachaRateSet["rows"]:
    let percentRatePerCard = parseFloat(gachaRate["percentRatePerCard"].getStr())
    for card in gachaRate["cards"]:
      result = card

      if (base <= choice) and (choice <= base + percentRatePerCard):
        return card

      base += percentRatePerCard

  echo("Warning: logic error in random card picking, returning last card")

proc getAbilityEfficacyIds(db: DbConn, tensionCardId: int): seq[int] =
  let row = db.getRow(sql"""
    SELECT mdTensionCard.tensionCardId, mdAbilityTensionCard.abilities
    FROM mdAbilityTensionCard
    INNER JOIN mdTensionCard
    ON mdAbilityTensionCard.abilityTensionCardId = mdTensionCard.abilityTensionCardId
    WHERE mdTensionCard.tensionCardId = ?
  """, tensionCardId)

  if row[0] == "":
    raise newException(SembaError, "Couldn't find abilities for tensionCardId=" & $tensionCardId)

  for abilityEfficacy in parseJson(row[1]):
    let abilityEfficacyId = abilityEfficacy["ability_efficacy_id"].getInt()
    result.add(abilityEfficacyId)

proc parseAbilityEfficacyRow(row: Row): JsonNode =
  let abilityEfficacyId = parseInt(row[0])
  let abilityEfficacyGroupId = parseInt(row[1])
  let coolTimeMillisecond = parseInt(row[2])
  let effectCoolTimeMillisecond = parseInt(row[3])
  let activeTimeMillisecond = parseInt(row[4])
  let efficacyType = parseInt(row[5])
  let probability = parseInt(row[6])
  let activateConditions = row[7]
  let deactivateConditions = row[8]
  let sustainConditions = row[9]
  let targetConditions = row[10]
  let fValues = parseJson(row[11])
  let values = parseJson(row[12])
  let uiViewPriority = parseInt(row[13])
  let effectValueSteps = parseJson(row[14])
  let targetType = parseInt(row[15])

  result = %*{
    "id": abilityEfficacyId,
    "coolTimeMillisecond": coolTimeMillisecond,
    "effectCoolTimeMillisecond": effectCoolTimeMillisecond,
    "activeTimeMillisecond": activeTimeMillisecond,
    "efficacyType": efficacyType,
    "probability": probability,
    "activateConditions": activateConditions,
    "deactivateConditions": deactivateConditions,
    "sustainConditions": sustainConditions,
    "targetConditions": targetConditions,
    "fValues": fValues,
    "values": values,
    "uiViewPriority": uiViewPriority,
    "effectValueSteps": effectValueSteps,
    "targetType": targetType,
  }

  if abilityEfficacyGroupId != 0:
    result["abilityEfficacyGroupId"] = %*abilityEfficacyGroupId

proc getAbilityEfficacies(db: DbConn, tensionCardId: int): seq[JsonNode] =
  var whereBody = ""

  for abilityEfficacyId in getAbilityEfficacyIds(db, tensionCardId):
    if whereBody == "":
      whereBody = "abilityEfficacyId=" & $abilityEfficacyId
    else:
      whereBody &= " OR abilityEfficacyId=" & $abilityEfficacyId

  if whereBody != "":
    let rows = db.getAllRows(sql("""
      SELECT abilityEfficacyId, abilityEfficacyGroupId, coolTimeMillisecond,
            effectCoolTimeMillisecond, activeTimeMillisecond, efficacyType, probability,
            activateConditions, deactivateConditions, sustainConditions, targetConditions,
            fValues, values_, uiViewPriority, effectValueSteps, targetType
      FROM mdAbilityEfficacy WHERE """ & whereBody)
    )

    for row in rows:
      let abilityEfficacy = parseAbilityEfficacyRow(row)
      result.add(abilityEfficacy)

proc getNewTensionCard(db: DbConn, entityId: int, tensionCardId: int): JsonNode =
  let receivedAt = getDateNow()
  let abilityEfficacies = getAbilityEfficacies(db, tensionCardId)

  result = %*{
    "abilityEfficacies": abilityEfficacies,
    "entityId": entityId,
    "isLocked": false,
    "maxLevel": 10,
    "receivedAt": receivedAt,
    "tensionCardId": tensionCardId,
    "trainingScoreLevelScore": 2,
  }

#[
Update the db from drawnCards, returns the changedResources
]#
proc updateDbFromDrawnCards(
  db: DbConn, drawnCards: seq[JsonNode], drawnRewards: var seq[JsonNode]
): JsonNode =
  var characterCount = initCountTable[int]()

  var tensionCards = newSeq[JsonNode]()

  for card in drawnCards:
    let reward = getRewardFromCard(db, card)
    drawnRewards.add(reward)

    let cardType = card["cardType"].getInt()
    let cardId = card["cardId"].getInt()

    if cardType == gachaCardCharacter.int:
      characterCount.inc(cardId)
    elif cardType == gachaCardTensionCard.int:
      let entityId = reward["entityId"].getInt()
      let tensionCard = getNewTensionCard(db, entityId, cardId)
      addTensionCard(db, tensionCard)
      tensionCards.add(tensionCard)
    else:
      raise newException(SembaError, "Invalid cardType=" & $cardType)

  # FIXME: should check if the character exists and add it to changedResources.characters if not
  var characterPieces = newSeq[JsonNode]()

  for characterId, count in characterCount.pairs():
    var quantity: int
    for i in 0 ..< count:
      quantity = addCharacterPiece(db, characterId)

    characterPieces.add(%*{
      "characterId": characterId,
      "quantity": quantity
    })

  result = %*{
    "characterPieces": characterPieces,
    "tensionCards": tensionCards,
  }

proc gacha_Execute(db: DbConn, jsonReq: JsonNode): JsonNode =
  randomize()

  let gachaId = jsonReq["gachaId"].getInt()
  let gachaButtonId = jsonReq["gachaButtonId"].getInt()
  let clientTimestamp = jsonReq["clientTimestamp"].getStr()

  let gacha = getGacha(db, gachaId)
  let gachaCategoryState = gacha["gachaCategoryState"]
  let pulls = gachaButtonToPulls(gachaButtonId)
  let isPromised = gachaButtonId == gachaButtonTen.int

  let gachaRateSets = getGachaRateSets(db)

  var drawnCards = newSeq[JsonNode]()
  var drawnRewards = newSeq[JsonNode]()

  for pullIdx in 0 ..< pulls:
    let gachaRateSet = getGachaRateSetForPull(gachaCategoryState, pullIdx, pulls, isPromised, gachaRateSets)

    let card = pickCard(gachaRateSet)
    drawnCards.add(card)

  let changedResources = updateDbFromDrawnCards(db, drawnCards, drawnRewards)

  return %*{
    "gacha": gacha,
    "drawnCards": drawnCards,
    "drawnRewards": drawnRewards,
    "changedResources": changedResources,
  }

proc character_LimitBreak(db: DbConn, jsonReq: JsonNode): JsonNode =
  let characterId = jsonReq["characterId"].getInt()
  let limitBreakCount = jsonReq["limitBreakCount"].getInt()

  let character = getCharacter(db, characterId)
  let limitBreak = character.getOrDefault("limitBreak").getInt() + limitBreakCount
  character["limitBreak"] = %*limitBreak
  db.exec(sql"""
    INSERT INTO characterLimitBreaks (characterId, limitBreak) VALUES (?, ?)
    ON CONFLICT (characterId) DO
    UPDATE SET limitBreak = excluded.limitBreak
  """, characterId, limitBreak)

  let characterPiece = getCharacterPiece(db, characterId)
  let quantity = max(0, characterPiece.getOrDefault("quantity").getInt() - 1)
  characterPiece["quantity"] = %*quantity
  updateCharacterPiece(db, characterPiece)

  result = %*{
    "changedResources": {
      "characters": [character],
      "characterPieces": [characterPiece],
    }
  }

proc tensionCard_LimitBreakEnhance(db: DbConn, jsonReq: JsonNode): JsonNode =
  let entityId = jsonReq["entityId"].getInt()
  let consumedEntityIds = jsonReq["consumedEntityIds"]

  let tensionCard = getTensionCard(db, entityId)
  let limitBreak = tensionCard.getOrDefault("limitBreak").getInt() + consumedEntityIds.len
  tensionCard["limitBreak"] = %*limitBreak
  updateTensionCardLimitBreak(db, entityId, limitBreak)

  db.exec(sql"BEGIN")
  for consumedEntityId in consumedEntityIds:
    db.exec(sql"DELETE FROM tensionCards WHERE entityId = ?", consumedEntityId.getInt())
    db.exec(sql"DELETE FROM tensionCardLimitBreaks WHERE entityId = ?", consumedEntityId.getInt())
  db.exec(sql"COMMIT")

  result = %*{
    "changedResources": {
      "tensionCards": [tensionCard],
    },
    "deletedResources": {
      "tensionCardEntityIds": consumedEntityIds,
    }
  }

proc formation_Switch(db: DbConn, jsonReq: JsonNode): JsonNode =
  let formationNumber = jsonReq["formationNumber"].getInt()
  let status = getUserStatus(db)
  status["formationNumber"] = %*formationNumber
  setUserStatus(db, status)
  result = %*{
    "changedResources": {
      "status": status,
    }
  }

proc getJsonResultStable*(
  uri: string, jsonReq: JsonNode,
  db: DbConn, lastBattleStartReq: var BattleStartRequest
): JsonNode =
  if uri == "/auth/steam_user":
    result = %*{"userId": "696969696969"}
  elif uri == "/auth/nonce":
    result = %*{"nonce": "6969696969696969"}
  elif uri == "/auth/sign_in":
    result = %*{"sessionToken": "69696969-6969-6969-6969-696969696969", "language": 2}
  elif uri == "/adventure/area_object":
    result = adventure_AreaObject(db, jsonReq)
  elif uri == "/tip/release":
    result = tip_Release(db, jsonReq)
  elif uri == "/adventure/move_to_area":
    result = adventure_MoveToArea(db, jsonReq)
  elif uri == "/battle/start":
    result = battle_Start(db, lastBattleStartReq, jsonReq)
  elif uri == "/battle/finish":
    result = battle_Finish(db, lastBattleStartReq, jsonReq)
  elif uri == "/user/cross_date":
    result = user_CrossDate(db, jsonReq)
  elif uri == "/adventure/update_character_status":
    result = adventure_UpdateCharacterStatus(db, jsonReq)
  elif uri == "/user/log_in":
    result = user_LogIn(db)
  elif uri == "/formation/update":
    result = formation_Update(db, jsonReq)
  elif uri == "/character/costume_update":
    result = character_CostumeUpdate(db, jsonReq)
  elif uri == "/adventure/read_sequence":
    result = adventure_ReadSequence(db, jsonReq)
  elif uri == "/adventure/acquire_area_item":
    result = adventure_AcquireAreaItem(db, jsonReq)
  elif uri == "/adventure/release_event_lift":
    result = adventure_ReleaseEventLift(jsonReq)
  elif uri == "/event/list_node":
    result = event_ListNode(db)
  elif uri == "/event/finish_node":
    result = event_FinishNode(db, jsonReq)
  elif uri == "/adventure/warp_area_locator":
    result = adventure_WarpAreaLocator(db, jsonReq)
  elif uri == "/xb/formation":
    result = xb_Formation(db, jsonReq)
  elif uri == "/xb/start":
    result = xb_Start(db, jsonReq)
  elif uri == "/xb/update_tension":
    result = xb_UpdateTension(db, jsonReq)
  elif uri == "/xb/play":
    result = xb_Play(db, jsonReq)
  elif uri == "/user/notification":
    result = user_Notification(db)
  elif uri == "/adventure/hospital":
    result = adventure_Hospital(db)
  elif uri == "/adventure/access_warp_point":
    result = adventure_AccessWarpPoint(db, jsonReq)
  elif uri == "/news/user_list":
    result = news_UserList()
  elif uri == "/news/list":
    result = news_UserList()
  elif uri == "/gacha/list":
    result = gacha_List(db)
  elif uri == "/gacha/execute":
    result = gacha_Execute(db, jsonReq)
  elif uri == "/character/limit_break":
    result = character_LimitBreak(db, jsonReq)
  elif uri == "/tension_card/limit_break_enhance":
    result = tensionCard_LimitBreakEnhance(db, jsonReq)
  elif uri == "/formation/switch":
    result = formation_Switch(db, jsonReq)
  else:
    result = nil