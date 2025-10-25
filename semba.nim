import std/json
import std/strutils
import system/ansi_c
import std/math
import std/times

import db_connector/db_sqlite

type SembaError = object of CatchableError

var db = open("build/semba.db", "", "", "")

proc dupString(str: string): cstring =
  let s = str.cstring
  result = cast[cstring](c_malloc((s.len + 1).csize_t))
  copyMem(result, s, s.len + 1)

proc getDateNow(): string = $(now().utc)

# stdout seems to be unreliable when called by the hook so
# log to the db
proc logFlow(uri: string, req: string, res: string) =
  db.exec(
    sql"INSERT INTO debugLogs (receivedAt, uri, req, res) VALUES (?, ?, ?, ?)",
    getDateNow(), uri, req, res
  )

proc logFlowOffline(uri: string, req: string, res: string) =
  db.exec(
    sql"INSERT INTO debugLogsOffline (receivedAt, uri, req, res) VALUES (?, ?, ?, ?)",
    getDateNow(), uri, req, res
  )

proc SembaLogFlow(uri: cstring, req: cstring, res: cstring) {.exportc.} =
  logFlow($uri, $req, $res)
  
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

proc adventure_MoveToArea(jsonReq: JsonNode): JsonNode =
  let areaId = jsonReq["areaId"].getInt()

  let currentLocation = jsonReq["currentLocation"]

  var status = getUserStatus()

  let fromAreaId = currentLocation["areaKeyId"].getInt()

  if fromAreaId == areaId:
    updateStatusFromCurrentLocation(status, currentLocation)
  else:
    # FIXME: should update status["currentAreaType"] here
    updatePos(status, fromAreaId, areaId)
    status["currentAreaKeyId"] = %*areaId

  setUserStatus(status)

  let areaBgmRow = db.getRow(sql"SELECT id, eventName FROM areaBgm WHERE areaId = ?", areaId)

  if areaBgmRow[0] == "":
    raise newException(SembaError, "Couldn't find areaBgm for areaId=" & $areaId)

  let areaBgmId = parseInt(areaBgmRow[0])
  let eventName = areaBgmRow[1]

  return %*{
    "areaBgm": {"id": areaBgmId, "eventName": eventName},
    "changedResources": {
      "status": status
    }
  }

let dbTensionCardsFields = """
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

proc getTensionCards(): seq[JsonNode] =
  let tensionCardsRows = db.getAllRows(sql("SELECT " & dbTensionCardsFields & " FROM tensionCards"))

  for tensionCardRow in tensionCardsRows:
    result.add(parseTensionCardRow(tensionCardRow))

proc getEquippedTensionCards(): seq[JsonNode] =
  # FIXME: should return current formation tension cards

  let tensionCardsRows = db.getAllRows(sql(
    "SELECT " & dbTensionCardsFields & " FROM tensionCards LIMIT 5"
  ))

  for tensionCardRow in tensionCardsRows:
    result.add(parseTensionCardRow(tensionCardRow))

let dbCharacterFields = """
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

proc getBattleParameters(battleEntryIds: JsonNode): seq[JsonNode] =
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

var lastBattleStartReq: JsonNode = nil

proc battle_Start(jsonReq: JsonNode): JsonNode =
  lastBattleStartReq = jsonReq

  var characters = newSeq[JsonNode]()

  # FIXME: fix this n+1 problem
  for lineCharacterId in jsonReq["lineCharacterIds"]:
    let characterRow = db.getRow(sql(
      "SELECT " & dbCharacterFields & " FROM characters WHERE characterId = ?"
    ), lineCharacterId.getInt())

    characters.add(parseCharacterRow(characterRow))

  let status = getUserStatus()

  let currentLocation = jsonReq["currentLocation"]
  
  status["currentAreaKeyId"] = currentLocation["areaKeyId"]
  status["currentAreaType"] = currentLocation["areaType"]
  status["currentDirection"] = currentLocation["direction"]
  status["currentPositionCoordinates"] = currentLocation["positionCoordinates"]

  setUserStatus(status)

  let battleParameters = getBattleParameters(jsonReq["battleEntryIds"])

  let advantageType = jsonReq.getOrDefault("advantageType")

  result = %*{
    "characters": characters,
    "tensionCards": getEquippedTensionCards(),
    "changedResources": {
      "status": status
    },
    "battleParameters": battleParameters,
    "battleTriggers": jsonReq["battleTriggers"]
  }

  if advantageType != nil:
    result["advantageType"] = advantageType

proc setCharacterHp(characterId: int, hp: int) =
  db.exec(sql"UPDATE characters SET hp = ? WHERE characterId = ?", hp, characterId)

proc getCharacters(): seq[JsonNode] =
  let charactersRows = db.getAllRows(sql("SELECT " & dbCharacterFields & " FROM characters"))

  for characterRow in charactersRows:   
    result.add(parseCharacterRow(characterRow))

proc removeAreaObject(areaKeyId: int, triggerId: int) =
  db.exec(sql"DELETE FROM areaObjects WHERE areaId=? AND areaObjectBehaviorId=?", areaKeyId, triggerId);

proc removeAreaEnemy(areaKeyId: int, triggerId: int) =
  db.exec(sql"DELETE FROM areaEnemies WHERE areaId=? AND areaPointId=?", areaKeyId, triggerId);

proc getBattleFinishAreaObjects(battleEntryId: int): JsonNode =
  let row = db.getRow(
    sql"SELECT areaObjects FROM battleFinishAreaObjects WHERE battleEntryId = ?", battleEntryId
  )

  return if row[0] != "": parseJson(row[0]) else: nil

proc updateAreaObjects(areaId: int, areaObjects: JsonNode) =
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

proc battle_Finish(jsonReq: JsonNode): JsonNode =
  var characterExps = newSeq[JsonNode]()

  for characterUpdate in jsonReq["characterUpdates"]:
    let characterId = characterUpdate["characterId"].getInt()
    let hp = characterUpdate["hp"].getInt()

    setCharacterHp(characterId, hp)

    characterExps.add(%*{
      "characterId": characterId,
      # FIXME: calculate exp
      "exp": 154,
      "dropExp": 154
    })

  var areaObjects: JsonNode = nil

  if lastBattleStartReq != nil:
    let areaKeyId = lastBattleStartReq["currentLocation"]["areaKeyId"].getInt()

    for battleTrigger in lastBattleStartReq["battleTriggers"]:
      let triggerType = battleTrigger.getOrDefault("triggerType")
      var isAreaObject = triggerType != nil and triggerType.getStr() == "area_object"
      var isActionSequence = triggerType != nil and triggerType.getStr() == "action_sequence"

      if not isActionSequence:
        for triggerId in battleTrigger["triggerIds"]:
          if isAreaObject:
            removeAreaObject(areaKeyId, triggerId.getInt())
          else:
            removeAreaEnemy(areaKeyId, triggerId.getInt())
    
    areaObjects = getBattleFinishAreaObjects(lastBattleStartReq["battleEntryIds"][0].getInt())

    lastBattleStartReq = nil

  let status = getUserStatus()
   
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
      "characters": getCharacters()
    }
  }

  if areaObjects != nil:
    result["areaObjects"] = areaObjects
    updateAreaObjects(status["currentAreaKeyId"].getInt(), areaObjects)

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
  let loggedInAt = getDateNow()
  status["loggedInAt"] = %*loggedInAt
  setUserStatus(status)
  return %*{
    "changedResources": {
      "status": status,
      "notifications": getNotifications()
    }
  }

proc adventure_UpdateCharacterStatus(jsonReq: JsonNode): JsonNode =
  var changedCharacters = newSeq[JsonNode]()

  for characterUpdate in jsonReq["characterUpdates"]:
    let characterId = characterUpdate["characterId"].getInt()
    let hp = characterUpdate["hp"].getInt()

    setCharacterHp(characterId, hp)
    
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

proc character_CostumeUpdate(jsonReq: JsonNode): JsonNode =
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

proc getFormations(): seq[JsonNode] =
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

proc getNineSequences(): seq[JsonNode] =
  let nineSequencesRows = db.getAllRows(sql"SELECT nineSequenceId, content FROM nineSequences")

  for nineSequenceRow in nineSequencesRows:
    let nineSequenceId = parseInt(nineSequenceRow[0])
    let content = parseJson(nineSequenceRow[1])

    content["nineSequenceId"] = %*nineSequenceId
    
    result.add(content)

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

proc getCharacterCostumes(): seq[JsonNode] =
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

proc getTotalTasks(): seq[JsonNode] =
  let totalTasksRows = db.getAllRows(sql"SELECT conditionId FROM totalTasks")
  
  for totalTaskRow in totalTasksRows:
    let conditionId = parseInt(totalTaskRow[0])

    result.add(%*{"conditionId": conditionId})

proc getTutorialStates(): seq[JsonNode] =
  let tutorialStatesRows = db.getAllRows(sql"SELECT tutorialStatusKey, enabled FROM tutorialStates")

  for tutorialStateRow in tutorialStatesRows:
    let tutorialStatusKey = parseInt(tutorialStateRow[0])
    let enabled = tutorialStateRow[1]

    let tutorialState = %*{"tutorialStatusKey": tutorialStatusKey}

    if enabled == "true" or enabled == "false":
      tutorialState["enabled"] = %*(if enabled == "true": true else: false)

    result.add(tutorialState)

proc getShopProducts(): seq[JsonNode] =
  let shopProductsRows = db.getAllRows(sql"SELECT val FROM shopProducts")

  for shopProductRow in shopProductsRows:
    result.add(parseJson(shopProductRow[0]))

proc getAdventureVariables(): seq[JsonNode] =
  let adventureVariablesRows = db.getAllRows(sql"SELECT adventureVariableId, value FROM adventureVariables")

  for row in adventureVariablesRows:
    let adventureVariableId = parseInt(row[0])
    let value = parseInt(row[1])

    result.add(%*{
      "adventureVariableId": adventureVariableId,
      "value": value
    })

proc getChallengeTasks(): seq[JsonNode] =
  for row in db.getAllRows(sql"SELECT challengeTaskId, clearedAt, count FROM challengeTasks"):
    let challengeTaskId = parseInt(row[0])
    let clearedAt = row[1]
    
    let challengeTask = %*{"challengeTaskId": challengeTaskId, "clearedAt": clearedAt}

    if row[2] != "":
      let count = parseInt(row[2])
      challengeTask["count"] = %*count

    result.add(challengeTask)

proc user_LogIn(): JsonNode =
  let formations = getFormations()
  let adventureVariables = getAdventureVariables()
  let challengeTasks = getChallengeTasks()

  return %*{
    "resources": {
      "challengeTasks": challengeTasks,
      "adventureVariables": adventureVariables,
      "wallet": {},
      "characters": getCharacters(),
      "status": getUserStatus(),
      "tensionCards": getTensionCards(),
      "formations": formations,
      "characterMountingPowerCommon": {},
      "notifications": getNotifications(),
      "challenges": [{"challengeId": 100, "state": 8}],
      "challengeProgresses": getChallengeProgresses(),
      "areas": [{"areaId": 300401}, {"areaId": 300402}],
      "nineSequences": getNineSequences(),
      "tips": getTips(),
      "characterCostumes": getCharacterCostumes(),
      "missions": [{"missionId": 105002, "count": 1, "clearedAt": "2025-09-10T02:22:53Z"}],
      "totalTasks": getTotalTasks(),
      "profile": {"name": "Yo Kuronaka3", "profileBannerId": 2010011, "characterLikabilityScale": 500},
      "profileBanners": [{"profileBannerId": 2010011, "receivedAt": "2025-09-10T02:22:51Z"}],
      "tutorialStates": getTutorialStates(),

    },
    "masterData": {"shopProducts": getShopProducts()}
  }

proc formation_Update(jsonReq: JsonNode): JsonNode =
  let number = jsonReq["number"].getInt()

  db.exec(sql"""
    UPDATE formations SET members = ?, cards = ? WHERE number = ?
  """, $(jsonReq["members"]), $(jsonReq["cards"]), number)

  return %*{
    "changedResources": {
      "formations": [
        jsonReq
      ]
    }
  }

proc updateNineSequences(nineSequences: JsonNode) =
  for nineSequence in nineSequences:
    let nineSequenceId = nineSequence["nineSequenceId"].getInt()
    let seqCopy = nineSequence.copy()
    seqCopy.delete("nineSequenceId")
    let seqCopyStr = $seqCopy

    db.exec(sql"""
      INSERT INTO nineSequences (nineSequenceId, content) VALUES (?, ?)
      ON CONFLICT (nineSequenceId) DO UPDATE SET content = ?
    """, nineSequenceId, seqCopyStr, seqCopyStr)

proc updateAdventureVariables(adventureVariables: JsonNode) =
  for adventureVariable in adventureVariables:
    let adventureVariableId = adventureVariable["adventureVariableId"].getInt()
    let value = adventureVariable["value"].getInt()

    db.exec(sql"""
      INSERT INTO adventureVariables (adventureVariableId, value) VALUES (?, ?)
      ON CONFLICT (adventureVariableId) DO UPDATE SET value = ?
    """, adventureVariableId, value, value)

proc updateChallengeProgresses(challengeProgresses: JsonNode) =
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

proc updateChallengeTasks(challengeTasks: JsonNode) =
  for challengeTask in challengeTasks:
    let challengeTaskId = challengeTask["challengeTaskId"].getInt()
    let clearedAt = challengeTask["clearedAt"].getStr()
    let count = challengeTask["count"].getInt()

    db.exec(sql"""
      INSERT INTO challengeTasks (challengeTaskId, clearedAt, count)
      VALUES (?, ?, ?)
      ON CONFLICT (challengeTaskId) DO UPDATE SET clearedAt = ?, count = ?
    """, challengeTaskId, clearedAt, count, clearedAt, count)

proc updateResources(changedResources: var JsonNode) =
  var status = getUserStatus()
  updateStatusFromStatusLocation(status, changedResources["status"])
  changedResources["status"] = status
  setUserStatus(status);

  let nineSequences = changedResources.getOrDefault("nineSequences")

  if nineSequences != nil:
    updateNineSequences(nineSequences)

  let adventureVariables = changedResources.getOrDefault("adventureVariables")

  if adventureVariables != nil:
    updateAdventureVariables(adventureVariables)

  let challengeProgresses = changedResources.getOrDefault("challengeProgresses")

  if challengeProgresses != nil:
    updateChallengeProgresses(challengeProgresses)

  let challengeTasks = changedResources.getOrDefault("challengeTasks")

  if challengeTasks != nil:
    updateChallengeTasks(challengeTasks)

proc adventure_ReadSequence(jsonReq: JsonNode): JsonNode =
  let seqReqId = jsonReq["sequenceRequestIds"][0].getInt()

  let row = db.getRow(sql"""
    SELECT areaObjects, changedResources FROM readSequence WHERE sequenceRequestId=?
  """, seqReqId);

  let areaObjects = parseJson(row[0])
  var changedResources = parseJson(row[1])

  updateAreaObjects(jsonReq["areaKeyId"].getInt(), areaObjects)
  updateResources(changedResources)  

  return %*{
    "areaObjects": areaObjects,
    "changedResources": changedResources
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
  elif uri == "/formation/update":
    jsonRes = formation_Update(jsonReq)
  elif uri == "/character/costume_update":
    jsonRes = character_CostumeUpdate(jsonReq)
  elif uri == "/adventure/read_sequence":
    jsonRes = adventure_ReadSequence(jsonReq)
  else:
    jsonRes = nil

  result = if jsonRes != nil: dupString($jsonRes) else: nil

  logFlowOffline($uri, $request, if jsonRes != nil: $jsonRes else: "")

proc SembaCall(uri: cstring, request: cstring): cstring {.exportc.} =
  try:
    result = sembaCallUnsafe(uri, request)
  except:
    let e = getCurrentException()
    echo "Nim Exception: " & getCurrentExceptionMsg()
    echo e.getStackTrace()
    result = nil