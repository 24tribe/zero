import std/json
import std/math
import std/sequtils
import std/strutils
import std/times

import db_connector/db_sqlite

type BattleStartRequest* = object
    val*: JsonNode

type SembaError = object of CatchableError

type AreaItemContentType = enum
    kaneContentType = 3,
    gearContentType = 6,
    itemContentType = 7,
    charExpContentType = 13

const minEventFloorNodeId = 113101
const maxEventFloorNodeId = 113128

type GameVersion* = enum
  gvNone, gvStable, gvDemo, gvBeta

proc getDateNow(): string = $(now().utc)

proc logFlowOffline(db: DbConn, uri: string, req: string, res: string) =
  db.exec(
    sql"INSERT INTO debugLogsOffline (receivedAt, uri, req, res) VALUES (?, ?, ?, ?)",
    getDateNow(), uri, req, res
  )

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

proc getQuestStates(db: DbConn): seq[JsonNode] =
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

proc getUserStatus(db: DbConn): JsonNode =
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
    var areaObjectId = parseInt(row[0])
    var areaPointId = parseInt(row[1])
    var areaObjectBehaviorId = parseInt(row[2])
    var action = parseJson(row[3])

    areaObjects.add(%*{
      "areaObjectId": areaObjectId,
      "areaPointId": areaPointId,
      "areaObjectBehaviorId": areaObjectBehaviorId,
      "action": action
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

proc addTip(db: DbConn, tip: JsonNode) =
  let tipId = tip["tipId"].getInt()
  let releasedAt = tip["releasedAt"].getStr()
  db.exec(sql"INSERT INTO tips (tipId, releasedAt) VALUES (?, ?)", tipId, releasedAt)

proc tip_Release(db: DbConn, jsonReq: JsonNode): JsonNode =
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
      WHERE t.tipId = ? AND areaObjects.areaId = t.areaId AND areaObjects.areaObjectId = t.areaObjectId
    """, tipId)

  return %*{
    "changedResources": {"tips": tips},
    "areaObjects": areaObjects
  }

proc getDistance(x1: float, y1: float, z1: float, x2: float, y2: float, z2: float): float =
  return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2) + pow(z2-z1, 2))

proc setUserStatus(db: DbConn, status: JsonNode) =
  db.exec(sql"UPDATE userData SET val = ? WHERE keyName = ?", $status, "status")

proc updatePos(db: DbConn, status: var JsonNode, fromAreaId: int, toAreaId: int) =
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

proc adventure_MoveToArea(db: DbConn, jsonReq: JsonNode): JsonNode =
  let areaId = jsonReq["areaId"].getInt()

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
      "status": status
    }
  }

  let actionSequenceId = getActionSequenceId(db, areaId)

  if actionSequenceId != 0:
    result["areaBehavior"] = %*{"actionSequenceId": actionSequenceId}

const dbTensionCardsFields = """
  tensionCardId, receivedAt, maxLevel, abilityEfficacies,
  trainingScoreLevelScore, entityId, isLocked
"""

proc parseTensionCardRow(tensionCardRow: Row): JsonNode =
  let tensionCardId = parseInt(tensionCardRow[0])
  let receivedAt = tensionCardRow[1]
  let maxLevel = parseInt(tensionCardRow[2])
  let abilityEfficacies = parseJson(tensionCardRow[3])
  let trainingScoreLevelScore = parseInt(tensionCardRow[4])
  let entityId = parseInt(tensionCardRow[5])
  let isLocked = if parseInt(tensionCardRow[6]) == 1: true else: false

  return %*{
    "tensionCardId": tensionCardId,
    "receivedAt": receivedAt,
    "maxLevel": maxLevel,
    "abilityEfficacies": abilityEfficacies,
    "trainingScoreLevelScore": trainingScoreLevelScore,
    "entityId": entityId,
    "isLocked": isLocked
  }

proc getTensionCards(db: DbConn): seq[JsonNode] =
  let tensionCardsRows = db.getAllRows(sql("SELECT " & dbTensionCardsFields & " FROM tensionCards"))

  for tensionCardRow in tensionCardsRows:
    result.add(parseTensionCardRow(tensionCardRow))

proc getEquippedTensionCards(db: DbConn): seq[JsonNode] =
  # FIXME: should return current formation tension cards

  let tensionCardsRows = db.getAllRows(sql(
    "SELECT " & dbTensionCardsFields & " FROM tensionCards LIMIT 5"
  ))

  for tensionCardRow in tensionCardsRows:
    result.add(parseTensionCardRow(tensionCardRow))

const dbCharacterFields = """
  characterId, exp, hp, attack, defense, maxHp, receivedAt, characterOwnershipType,
  criticalRate, criticalDamageRate, movementSpeed, damageInflictedRate, tensionIncreaseRate,
  cpRecastRate, spGaugeIncreaseRate, attackSpeed, characterCostumeId, abnormalityParamSet,
  trainingScoreLevelScore, trainingScoreRankScore, actionPointMax,
  actionPointRate, actionPointConsumption, damageTakenRate
"""

proc parseCharacterRow(characterRow: Row): JsonNode =
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
    "damageTakenRate": damageTakenRate
  }

proc getBattleParameters(db: DbConn, battleEntryIds: JsonNode): seq[JsonNode] =
  # FIXME: fix n+1
  for battleEntryId in battleEntryIds:
    let id = battleEntryId.getInt()
    let battleParameterRow = db.getRow(sql"""
      SELECT enemies FROM battleParameters WHERE id = ?
    """, id)

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
    let characterRow = db.getRow(sql(
      "SELECT " & dbCharacterFields & " FROM characters WHERE characterId = ?"
    ), lineCharacterId.getInt())

    characters.add(parseCharacterRow(characterRow))

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

proc getCharacters(db: DbConn): seq[JsonNode] =
  let charactersRows = db.getAllRows(sql("SELECT " & dbCharacterFields & " FROM characters"))

  for characterRow in charactersRows:   
    result.add(parseCharacterRow(characterRow))

proc removeAreaObject(db: DbConn, areaKeyId: int, triggerId: int) =
  db.exec(sql"DELETE FROM areaObjects WHERE areaId=? AND areaObjectBehaviorId=?", areaKeyId, triggerId);

proc removeAreaEnemy(db: DbConn, areaKeyId: int, triggerId: int) =
  db.exec(sql"DELETE FROM areaEnemies WHERE areaId=? AND areaPointId=?", areaKeyId, triggerId);

proc getBattleFinishAreaObjects(db: DbConn, battleEntryId: int): JsonNode =
  let row = db.getRow(
    sql"SELECT areaObjects FROM battleFinishAreaObjects WHERE battleEntryId = ?", battleEntryId
  )

  return if row[0] != "": parseJson(row[0]) else: nil

proc updateAreaObjects(db: DbConn, areaId: int, areaObjects: JsonNode) =
  for areaObject in areaObjects:
    let areaObjectId = areaObject["areaObjectId"].getInt()
    let areaPointId = areaObject["areaPointId"].getInt()
    let areaObjectBehaviorId = areaObject["areaObjectBehaviorId"].getInt()
    let action = $(areaObject["action"])

    db.exec(sql"""
      INSERT INTO areaObjects (areaId, areaObjectId, areaPointId, areaObjectBehaviorId, action)
      VALUES (?, ?, ?, ?, ?)
      ON CONFLICT (areaObjectId) DO
      UPDATE SET areaPointId = excluded.areaPointId,
                 areaObjectBehaviorId = excluded.areaObjectBehaviorId,
                 action = excluded.action
    """, areaId, areaObjectId, areaPointId, areaObjectBehaviorId, action)

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
    updateAreaObjects(db, status["currentAreaKeyId"].getInt(), areaObjects)

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

proc user_CrossDate(db: DbConn, jsonReq: JsonNode): JsonNode =
  # FIXME: move status loggedInAt update to user_LogIn
  let status = getUserStatus(db)
  let loggedInAt = getDateNow()
  status["loggedInAt"] = %*loggedInAt
  setUserStatus(db, status)
  return %*{
    "changedResources": {
      "status": status,
      "notifications": getNotifications()
    }
  }

proc adventure_UpdateCharacterStatus(db: DbConn, jsonReq: JsonNode): JsonNode =
  var changedCharacters = newSeq[JsonNode]()

  for characterUpdate in jsonReq["characterUpdates"]:
    let characterId = characterUpdate["characterId"].getInt()
    let hp = characterUpdate["hp"].getInt()

    setCharacterHp(db, characterId, hp)

    let characterRow = db.getRow(sql(
      "SELECT " & dbCharacterFields & " FROM characters WHERE characterId = ?"
    ), characterId)

    changedCharacters.add(parseCharacterRow(characterRow))

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

  let characterRow = db.getRow(sql("SELECT " & dbCharacterFields & " FROM characters WHERE characterId = ?"), characterId)
  let character = parseCharacterRow(characterRow)
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

proc getChallengeProgresses(db: DbConn): seq[JsonNode] =
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

proc getNineSequences(db: DbConn): seq[JsonNode] =
  let nineSequencesRows = db.getAllRows(sql"SELECT nineSequenceId, content FROM nineSequences")

  for nineSequenceRow in nineSequencesRows:
    let nineSequenceId = parseInt(nineSequenceRow[0])
    let content = parseJson(nineSequenceRow[1])

    content["nineSequenceId"] = %*nineSequenceId
    
    result.add(content)

proc getTips(db: DbConn): seq[JsonNode] =
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

proc getTotalTasks(db: DbConn): seq[JsonNode] =
  let totalTasksRows = db.getAllRows(sql"SELECT conditionId FROM totalTasks")
  
  for totalTaskRow in totalTasksRows:
    let conditionId = parseInt(totalTaskRow[0])

    result.add(%*{"conditionId": conditionId})

proc getTutorialStates(db: DbConn): seq[JsonNode] =
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

proc getAdventureVariables(db: DbConn): seq[JsonNode] =
  let adventureVariablesRows = db.getAllRows(sql"SELECT adventureVariableId, value FROM adventureVariables")

  for row in adventureVariablesRows:
    let adventureVariableId = parseInt(row[0])
    let value = parseInt(row[1])

    result.add(%*{
      "adventureVariableId": adventureVariableId,
      "value": value
    })

proc getChallengeTasks(db: DbConn): seq[JsonNode] =
  for row in db.getAllRows(sql"SELECT challengeTaskId, clearedAt, count FROM challengeTasks"):
    let challengeTaskId = parseInt(row[0])
    let clearedAt = row[1]
    
    let challengeTask = %*{"challengeTaskId": challengeTaskId, "clearedAt": clearedAt}

    if row[2] != "":
      let count = parseInt(row[2])
      challengeTask["count"] = %*count

    result.add(challengeTask)

proc user_LogIn(db: DbConn): JsonNode =
  let formations = getFormations(db)
  let adventureVariables = getAdventureVariables(db)
  let challengeTasks = getChallengeTasks(db)
  let questStates = getQuestStates(db)

  return %*{
    "resources": {
      "challengeTasks": challengeTasks,
      "adventureVariables": adventureVariables,
      "wallet": {},
      "characters": getCharacters(db),
      "status": getUserStatus(db),
      "tensionCards": getTensionCards(db),
      "formations": formations,
      "characterMountingPowerCommon": {},
      "notifications": getNotifications(),
      "challenges": [{"challengeId": 100, "state": 8}],
      "challengeProgresses": getChallengeProgresses(db),
      "areas": [{"areaId": 300401}, {"areaId": 300402}],
      "nineSequences": getNineSequences(db),
      "tips": getTips(db),
      "characterCostumes": getCharacterCostumes(db),
      "missions": [{"missionId": 105002, "count": 1, "clearedAt": "2025-09-10T02:22:53Z"}],
      "totalTasks": getTotalTasks(db),
      "profile": {"name": "Yo Kuronaka3", "profileBannerId": 2010011, "characterLikabilityScale": 500},
      "profileBanners": [{"profileBannerId": 2010011, "receivedAt": "2025-09-10T02:22:51Z"}],
      "tutorialStates": getTutorialStates(db),
      "questStates": questStates,
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

proc updateResources(db: DbConn, changedResources: var JsonNode) =
  var status = getUserStatus(db)
  updateStatusFromStatusLocation(status, changedResources["status"])
  changedResources["status"] = status
  setUserStatus(db, status);

  let nineSequences = changedResources.getOrDefault("nineSequences")

  if nineSequences != nil:
    updateNineSequences(db, nineSequences)

  let adventureVariables = changedResources.getOrDefault("adventureVariables")

  if adventureVariables != nil:
    updateAdventureVariables(db, adventureVariables)

  let challengeProgresses = changedResources.getOrDefault("challengeProgresses")

  if challengeProgresses != nil:
    updateChallengeProgresses(db, challengeProgresses)

  let challengeTasks = changedResources.getOrDefault("challengeTasks")

  if challengeTasks != nil:
    updateChallengeTasks(db, challengeTasks)

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

proc adventure_ReadSequence(db: DbConn, jsonReq: JsonNode): JsonNode =
  let seqReqId = jsonReq["sequenceRequestIds"][0].getInt()

  let row = db.getRow(sql"""
    SELECT areaObjects, changedResources FROM readSequence WHERE sequenceRequestId=?
  """, seqReqId);

  var areaObjects: JsonNode = nil

  if row[0] != "":
    areaObjects = parseJson(row[0])
    updateAreaObjects(db, jsonReq["areaKeyId"].getInt(), areaObjects)

  var changedResources = parseJson(row[1]) 
  updateResources(db, changedResources)  

  result = %*{
    "changedResources": changedResources
  }

  if areaObjects != nil:
    result["areaObjects"] = areaObjects

  let readSequenceAreaAction = getReadSequenceAreaAction(db, seqReqId)

  if readSequenceAreaAction.areaId != 0 and readSequenceAreaAction.actionSequenceId != 0:
    updateActionSequenceId(db, readSequenceAreaAction.areaId, readSequenceAreaAction.actionSequenceId)

  let readSequenceAreaBgm = getReadSequenceAreaBgm(db, seqReqId)

  if readSequenceAreaBgm.areaId != 0:
    updateAreaBgm(db, readSequenceAreaBgm.areaId, readSequenceAreaBgm.id, readSequenceAreaBgm.eventName)

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

proc statusToDemo(status: var JsonNode) =
  status["currentAreaId"] = %*300203

  #[ let x = status["currentPositionCoordinates"]["x"].getFloat()
  let y = status["currentPositionCoordinates"]["y"].getFloat()
  let z = status["currentPositionCoordinates"]["z"].getFloat() ]#
  let x = -28.0
  let y = 29.0
  let z = 0.0
  status["currentPosition"] = %*($x & "," & $y & "," & $z)

  status.delete("currentAreaType")
  status.delete("currentAreaKeyId")
  status.delete("currentPositionCoordinates")

proc characterToDemo(character: var JsonNode) =
  character["spGauge"] = %*100
  character["abilityEfficacies"] = %*[]
  character["attacks"] = %*[]
  character["limitedAbilityEfficacyIds"] = %*[]
  character["likability"] = %*100

  character.delete("actionPointMax")
  character.delete("actionPointRate")
  character.delete("actionPointConsumption")
  character.delete("damageTakenRate")

proc charactersToDemo(characters: var JsonNode) =
  var newCharacters = newSeq[JsonNode]()
  for character in characters.mitems():
    if character["characterId"].getInt() <= 101501:
      characterToDemo(character)
      newCharacters.add(character)

  characters = %*newCharacters

proc challengeProgressesToDemo(challengeProgresses: var JsonNode) =
  var newChallengeProgresses = newSeq[JsonNode]()
  for challengeProgress in challengeProgresses.mitems():
    if challengeProgress["challengeProgressId"].getInt() < 1000112:
      challengeProgress.delete("state")
      newChallengeProgresses.add(challengeProgress)

  challengeProgresses = %*newChallengeProgresses

proc getBaseCostumes(characters: JsonNode): seq[JsonNode] =
  for character in characters:
    let costumeId = ((character["characterId"].getInt() div 10) * 100) + 1
    result.add(%*{
      "characterCostumeId": costumeId,
      "receivedAt": "2025-04-24T03:49:59Z"
    })

proc notificationsToDemo(notifications: var JsonNode) =
  notifications.delete("itemRequest")

proc demo_battle_Start(db: DbConn, jsonReq: JsonNode): JsonNode =
  var characterSeq = newSeq[JsonNode]()

  # FIXME: fix this n+1 problem
  for lineCharacterId in jsonReq["lineCharacterIds"]:
    let characterRow = db.getRow(sql(
      "SELECT " & dbCharacterFields & " FROM characters WHERE characterId = ?"
    ), lineCharacterId.getInt())

    characterSeq.add(parseCharacterRow(characterRow))

  var characters = %*characterSeq

  charactersToDemo(characters)

  var status = getUserStatus(db)
  statusToDemo(status)

  let advantageType = jsonReq.getOrDefault("advantageType")

  let battleParameters = %*[
    {
      "bgmId": 4,
      "cameraSettingsAsset": "CameraSettings",
      "waves": [
      ],
      "enemies": [
        {
          "id": 250108,
          "name": "24 Kanon Ikura",
          "title": "",
          "description": "An autonomous drone that is modified...",
          "isBoss": false,
          "attack": 6000,
          "defense": 1000,
          "hp": 2400,
          "guardDurability": 0,
          "movementSpeed": 7,
          "supportPowerRate": 0,
          "costumeId": "",
          "characterActionId": 250103,
          "characterActionResourceId": 0,
          "abilityPassiveIds": [20001],
          "battleVfxId": 0,
          "pushWeightType": 0,
          "tensionValue": 100,
          "dropExp": 100,
          "characterWeaponCostumeIds": [],
          "abnormalityParamSet": {
            "electric": {
              "attackRate": 0,
              "burstResistance": 20,
              "burstResistanceIncreaseValue": 10,
              "burstResistanceLimit": 50,
              "defenseRate": 0
            },
            "oily": {
              "attackRate": 0,
              "burstResistance": 20,
              "burstResistanceIncreaseValue": 10,
              "burstResistanceLimit": 50,
              "defenseRate": 0
            },
            "pressure": {
              "attackRate": 0,
              "burstResistance": 20,
              "burstResistanceIncreaseValue": 10,
              "burstResistanceLimit": 50,
              "defenseRate": 0
            },
            "scared": {
              "attackRate": 0,
              "burstResistance": 20,
              "burstResistanceIncreaseValue": 10,
              "burstResistanceLimit": 50,
              "defenseRate": 0
            },
            "unfortified": {
              "attackRate": 0,
              "burstResistance": 20,
              "burstResistanceIncreaseValue": 10,
              "burstResistanceLimit": 50,
              "defenseRate": 0
            }
          },
          "isSkipEncounterAnimation": true,
          "hpStackCount": 0
          
        },
      ],
      "fieldName": "Field/env030_03",
      "id": 1000001,
      "mapRot": 230,
      "posX": 0,
      "posY": 0,
      "posZ": -9,
      "rot": 0,
      "waveConditions": []
    }
  ]

  result = %*{
    "formation": {
      "number": 1,
      "members": {"character1Id": 100101, "character1OwnershipType": 1},
      "cards": {
      },
    },
    "characters": characters,
    "tensionCards": [],
    "changedResources": {
      "status": status
    },
    "battleParameters": battleParameters,
    "battleTriggers": jsonReq["battleTriggers"]
  }

  if advantageType != nil:
    result["advantageType"] = advantageType

proc demo_adventure_MoveToArea(db: DbConn, jsonReq: JsonNode): JsonNode =
  var status = getUserStatus(db)

  statusToDemo(status)

  return %*{
    "changedResources": {
      "status": status,
    },
    "areaBgm": {
      "id": 201,
      "eventName": "bgm_adv_02_basic",
    }
  }

proc demo_adventure_AreaObject(): JsonNode =
  let areaObject = %*{
    "areaPointId": 300203001,
    "areaObjectId": 130104,
    "action": {
      "type": 5,
      "areaEnemyId": 130104,
      "battleEntryId": 1000001,
    }
  }

  return %*{
    "areaObjects": [areaObject],
    "bloodStains": [],
  }

proc demo_adventure_Variable(jsonReq: JsonNode): JsonNode =
  var adventureVariables = newSeq[JsonNode]()

  for adventureVariableId in jsonReq["adventureVariableIds"]:
    adventureVariables.add(%*{
      "adventureVariableId": adventureVariableId.getInt(),
      "value": 1,
    })

  return %*{
    "adventureVariables": adventureVariables
  }

proc demo_user_CrossDate(db: DbConn, jsonReq: JsonNode): JsonNode =
  let res = user_CrossDate(db, jsonReq)

  var status = res["changedResources"]["status"]
  statusToDemo(status)

  var notifications = res["changedResources"]["notifications"]
  notificationsToDemo(notifications)

  return %*{
    "changedResources": {
      "status": status,
      "notifications": notifications,
    }
  }

proc demo_user_LogIn(db: DbConn): JsonNode =
  let res = user_LogIn(db)

  var status = res["resources"]["status"]
  statusToDemo(status)

  var characters = res["resources"]["characters"]
  charactersToDemo(characters)

  var notifications = res["resources"]["notifications"]
  notificationsToDemo(notifications)

  var challengeProgresses = res["resources"]["challengeProgresses"]
  challengeProgressesToDemo(challengeProgresses)

  let characterCostumes = getBaseCostumes(characters)

  return %*{
    "resources": {
      "challengeTasks": res["resources"]["challengeTasks"],
      "wallet": {},
      "characters": characters,
      "status": status,
      "tensionCards": [],
      "formations": res["resources"]["formations"],
      "notifications": notifications,
      "challenges": [{"challengeId": 100, "state": 8}],
      "challengeProgresses": challengeProgresses,
      "areas": [],
      "nineSequences": [],
      "tips": [],
      "characterCostumes": characterCostumes,
      "missions": [],
      "totalTasks": [],
      "profile": {"name": "Yo Kuronaka3"},
      "tutorialStatus": {"status": []},
    },
    "masterData": {"shopProducts": [], "shopProductLimitedDiscounts": []}
  }

proc getJsonResultStable(
  uri: string, jsonReq: JsonNode,
  db: DbConn, lastBattleStartReq: var BattleStartRequest
): JsonNode =
  if uri == "echo":
    let dataUpper = jsonReq["data"].getStr().toUpperAscii()
    result = %*{"data": dataUpper}
  elif uri == "/auth/steam_user":
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
  else:
    result = nil

proc getJsonResultDemo(uri: string, jsonReq: JsonNode, db: DbConn): JsonNode =
  if uri == "/auth/sign_up":
    result = %*{"userId": "696969696969"}
  elif uri == "/user/log_in":
    result = demo_user_LogIn(db)
  elif uri == "/user/cross_date":
    result = demo_user_CrossDate(db, jsonReq)
  elif uri == "/news/list":
    result = %*{"news": []}
  elif uri == "/adventure/move_to_area":
    result = demo_adventure_MoveToArea(db, jsonReq)
  elif uri == "/adventure/area_object":
    result = demo_adventure_AreaObject()
  elif uri == "/adventure/variable":
    result = demo_adventure_Variable(jsonReq)
  elif uri == "/battle/start":
    result = demo_battle_Start(db, jsonReq)
  elif uri == "/tip/release":
    result = tip_Release(db, jsonReq)
  else: 
    result = nil

proc sembaCallImpl*(
    uri: string, request: string, version: GameVersion,
    db: DbConn, lastBattleStartReq: var BattleStartRequest
): string =
  let jsonReq = if request != "": parseJson(request) else: nil
  var jsonRes: JsonNode

  if version == gvDemo:
    jsonRes = getJsonResultDemo(uri, jsonReq, db)
  else:
    jsonRes = getJsonResultStable(uri, jsonReq, db, lastBattleStartReq)

  result = if jsonRes != nil: $jsonRes else: ""

  logFlowOffline(db, uri, request, result)