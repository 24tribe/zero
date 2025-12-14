#[
FIXME: most functions in this file shouldn't depend on the stable version ones
]#

import std/json

import sembastable

import db_connector/db_sqlite

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

proc getJsonResultDemo*(uri: string, jsonReq: JsonNode, db: DbConn): JsonNode =
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