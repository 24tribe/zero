#[
This module is in charge of the save files.
Each version can save/load more tables from the db.
Old save files should work on new versions of the offline mode,
and if they don't, that's considered a bug.

version 2: formations
version 3: tips, areaObjects, areaEnemies
version 4: userStatus
version 5: (
  debugLogsOffline, areaBgm, characters, tensionCards,
  challengeProgresses, nineSequences, totalTasks, tutorialStates,
  adventureVariables, challengeTasks, areaActionSequenceIds, questStates
  clearedAchievements
)
version 6: has new areaObjects
version 7: challenges
version 8: warpPoints, areas, areaGroups, cities
version 9: characterPieces, userData
version 10: dungeons
version 11: magicOrbs, items, areaChangeLocks
]#

import std/json
import std/files
import std/paths

import db_connector/db_sqlite

import sembastable

proc resetAreaObjects*(db: DbConn) =
  db.exec(sql"DELETE FROM areaObjects")
  db.exec(sql"INSERT INTO areaObjects SELECT * FROM areaObjectsOriginal")
  db.exec(sql"DELETE FROM areaEnemies")
  db.exec(sql"INSERT INTO areaEnemies SELECT * FROM areaEnemiesOriginal")
  db.exec(sql"DELETE FROM areaBgm")
  db.exec(sql"INSERT INTO areaBgm SELECT * FROM areaBgmOriginal")


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


proc loadSaveFileVer3(db: DbConn, jsonData: JsonNode, dontDeleteAllAreaObjects: bool) =
  let tips = jsonData["tips"]

  db.exec(sql"DELETE FROM tips")

  for tip in tips:
    addTip(db, tip)

  let areaObjects = jsonData["areaObjects"]

  if not dontDeleteAllAreaObjects:
    db.exec(sql"DELETE FROM areaObjects")

  for areaObject in areaObjects:
    addAreaObject(db, areaObject)

  let areaEnemies = jsonData["areaEnemies"]

  if not dontDeleteAllAreaObjects:
    db.exec(sql"DELETE FROM areaEnemies")

  for areaEnemy in areaEnemies:
    addAreaEnemy(db, areaEnemy)


proc loadSaveFileVer5(db: DbConn, jsonData: JsonNode, dontDeleteAllAreaObjects: bool) =
  let offlineLogs = jsonData["offlineLogs"]

  db.exec(sql"DELETE FROM debugLogsOffline")

  for offlineLog in offlineLogs:
    addOfflineLog(db, offlineLog)

  let areaBgms = jsonData["areaBgms"]

  if not dontDeleteAllAreaObjects:
    db.exec(sql"DELETE FROM areaBgm")

  for areaBgm in areaBgms:
    addAreaBgm(db, areaBgm)

  let characters = jsonData["characters"]

  db.exec(sql"DELETE FROM characters")
  db.exec(sql"DELETE FROM characterLimitBreaks")

  for character in characters:
    addCharacter(db, character)

  let tensionCards = jsonData["tensionCards"]

  db.exec(sql"DELETE FROM tensionCards")
  db.exec(sql"DELETE FROM tensionCardLimitBreaks")

  for tensionCard in tensionCards:
    addTensionCard(db, tensionCard)

  let challengeProgresses = jsonData["challengeProgresses"]

  db.exec(sql"DELETE FROM challengeProgresses")

  for challengeProgress in challengeProgresses:
    addChallengeProgress(db, challengeProgress)

  let nineSequences = jsonData["nineSequences"]

  db.exec(sql"DELETE FROM nineSequences")

  for nineSequence in nineSequences:
    addNineSequence(db, nineSequence)

  let totalTasks = jsonData["totalTasks"]

  db.exec(sql"DELETE FROM totalTasks")

  for totalTask in totalTasks:
    addTotalTask(db, totalTask)

  let tutorialStates = jsonData["tutorialStates"]

  db.exec(sql"DELETE FROM tutorialStates")

  for tutorialState in tutorialStates:
    addTutorialState(db, tutorialState)

  let adventureVariables = jsonData["adventureVariables"]

  db.exec(sql"DELETE FROM adventureVariables")

  for adventureVariable in adventureVariables:
    addAdventureVariable(db, adventureVariable)

  let challengeTasks = jsonData["challengeTasks"]

  db.exec(sql"DELETE FROM challengeTasks")

  for challengeTask in challengeTasks:
    addChallengeTask(db, challengeTask)

  let areaActionSequenceIds = jsonData["areaActionSequenceIds"]

  db.exec(sql"DELETE FROM areaActionSequenceIds")
  db.exec(sql"INSERT INTO areaActionSequenceIds SELECT * FROM defaultAreaActionSequenceIds")

  for areaActionSequenceId in areaActionSequenceIds:
    addAreaActionSequenceId(db, areaActionSequenceId)

  let questStates = jsonData["questStates"]

  db.exec(sql"DELETE FROM questStates")

  for questState in questStates:
    addQuestState(db, questState)

  let clearedAchievements = jsonData["clearedAchievements"]

  db.exec(sql"DELETE FROM clearedAchievements")

  for clearedAchievement in clearedAchievements:
    addClearedAchievement(db, clearedAchievement)


proc loadSaveFileVer8(db: DbConn, jsonData: JsonNode) =
  db.exec(sql"DELETE FROM warpPoints")
  let warpPoints = jsonData["warpPoints"].getElems()
  for warpPoint in warpPoints:
    addWarpPoint(db, warpPoint["warpPointId"].getInt())

  db.exec(sql"DELETE FROM areas")
  let areas = jsonData["areas"].getElems()
  for area in areas:
    addArea(db, area["areaId"].getInt())

  db.exec(sql"DELETE FROM areaGroups")
  let areaGroups = jsonData["areaGroups"].getElems()
  for areaGroup in areaGroups:
    addAreaGroup(db, areaGroup["areaGroupId"].getInt())

  db.exec(sql"DELETE FROM cities")
  let cities = jsonData["cities"].getElems()
  for city in cities:
    addCity(db, city)


proc sanityChecks(db: DbConn) =
  # https://github.com/24tribe/zero/issues/24
  if (
    isChallengeProgressComplete(getChallengeProgress(db, 1010071)) and
    not isChallengeProgressComplete(getChallengeProgress(db, 1010081))
  ):
    updateActionSequenceId(db, 101311, 8010081)

  # https://github.com/24tribe/zero/issues/26
  if isChallengeProgressComplete(getChallengeProgress(db, 1010042)):
    updateAreaObjects(db, %*[
      {
        "areaObjectId": 700058, "areaPointId": 101312102, "areaObjectBehaviorId": 7010712,
        "action": {"type": 7, "id": 1}
      },
      {
        "areaObjectId": 700053, "areaPointId": 101311120, "areaObjectBehaviorId": 7010714,
        "action": {"type": 7, "id": 1}
      }
    ])

  # https://github.com/24tribe/zero/issues/28
  if isChallengeProgressComplete(getChallengeProgress(db, clearHealthyOutlawsChallengeProgressId)):
    updateAreaObjects(db, %*[
      {
        "areaObjectId": 700110, "areaPointId": 101001101, "areaObjectBehaviorId": 7010709,
        "action": {"type": 7, "id": 1}
      }
    ])


proc loadSaveFile*(db: DbConn, saves_dir: string, name: string): string =
  db.exec(sql"BEGIN")

  const baseError = "Couldn't load save file"

  if db == nil:
    return baseError & ", db is not initialized"

  let content = readFile(saves_dir & "/" & name & ".save")
  let jsonData = parseJson(content)

  let version = jsonData["version"].getInt()

  resetAreaObjects(db)

  if version < 2:
    return baseError & ", invalid version: should be >= 2"

  let formations = jsonData["formations"]

  for formation in formations:
    updateFormation(db, formation)

  # all saves until version 5 are stuck in the first three areas
  let dontDeleteAllAreaObjects = version <= 5

  if version >= 3:
    if dontDeleteAllAreaObjects:
      db.exec(sql"DELETE FROM areaObjects WHERE areaId=300402 or areaId=300401 or areaId=101381")
      db.exec(sql"DELETE FROM areaEnemies WHERE areaId=300402 or areaId=300401 or areaId=101381")
      db.exec(sql"DELETE FROM areaBgm WHERE areaId=300402 or areaId=300401 or areaId=300501 or areaId=101381 or areaId=130801")

    loadSaveFileVer3(db, jsonData, dontDeleteAllAreaObjects)

  if version >= 9:
    db.exec(sql"DELETE FROM characterPieces")
    let characterPieces = jsonData["characterPieces"]
    for characterPiece in characterPieces:
      updateCharacterPiece(db, characterPiece)

    db.exec(sql"DELETE FROM userData")
    db.exec(sql"INSERT INTO userData SELECT * FROM defaultUserData")
    let userData = jsonData["userData"]
    for row in userData:
      updateUserData(db, row["keyName"].getStr(), row["val"].getStr())

  if version >= 4:
    let status = jsonData["status"]
    setUserStatus(db, status)

  if version >= 5:
    loadSaveFileVer5(db, jsonData, dontDeleteAllAreaObjects)

  if version >= 7:
    let challenges = jsonData["challenges"].getElems()
    updateChallenges(db, challenges)

  if version >= 8:
    loadSaveFileVer8(db, jsonData)

  db.exec(sql"DELETE FROM dungeons")
  if version >= 10:
    let dungeons = jsonData["dungeons"]
    for dungeon in dungeons:
      addDungeon(db, dungeon)

  db.exec(sql"DELETE FROM magicOrbs")
  db.exec(sql"DELETE FROM items")
  db.exec(sql"DELETE FROM areaChangeLocks")

  if version >= 11:
    let magicOrbs = jsonData["magicOrbs"].getElems()
    updateMagicOrbs(db, magicOrbs)

    let areaChangeLocks = jsonData["areaChangeLocks"].getElems()
    updateAreaChangeLocks(db, areaChangeLocks)

    let items = jsonData["items"].getElems()
    updateItems(db, items)

  db.exec(sql"DELETE FROM missions")
  # load missions from savefile

  db.exec(sql"COMMIT")

  db.exec(sql"BEGIN")
  sanityChecks(db)
  db.exec(sql"COMMIT")


proc createSaveFile*(db: DbConn, saves_dir: string, name: string): string =
  const baseError = "Couldn't create save file"

  if db == nil:
      return baseError & ", db is not initialized"

  let formations = getFormations(db)
  let tips = getTips(db)
  let areaObjects = getAreaObjects(db)
  let areaEnemies = getAreaEnemies(db)
  let status = getUserStatus(db)
  let offlineLogs = getOfflineLogs(db)
  let areaBgms = getAreaBgms(db)
  let characters = getCharacters(db)
  let tensionCards = getTensionCards(db)
  let challengeProgresses = getChallengeProgresses(db)
  let nineSequences = getNineSequences(db)
  let totalTasks = getTotalTasks(db)
  let tutorialStates = getTutorialStates(db)
  let adventureVariables = getAdventureVariables(db)
  let challengeTasks = getChallengeTasks(db)
  let areaActionSequenceIds = getAreaActionSequenceIds(db)
  let questStates = getQuestStates(db)
  let clearedAchievements = getClearedAchievements(db)
  let challenges = getChallenges(db)
  let warpPoints = getWarpPoints(db)
  let areas = getAreas(db)
  let areaGroups = getAreaGroups(db)
  let cities = getCities(db)
  let characterPieces = getCharacterPieces(db)
  let userData = getUserData(db)
  let dungeons = getDungeons(db)
  let magicOrbs = getMagicOrbs(db)
  let areaChangeLocks = getAreaChangeLocks(db)
  let items = getItems(db)

  var jsonData = %*{
    "version": 11,
    "formations": formations,
    "tips": tips,
    "areaObjects": areaObjects,
    "areaEnemies": areaEnemies,
    "status": status,
    "offlineLogs": offlineLogs,
    "areaBgms": areaBgms,
    "characters": characters,
    "tensionCards": tensionCards,
    "challengeProgresses": challengeProgresses,
    "nineSequences": nineSequences,
    "totalTasks": totalTasks,
    "tutorialStates": tutorialStates,
    "adventureVariables": adventureVariables,
    "challengeTasks": challengeTasks,
    "areaActionSequenceIds": areaActionSequenceIds,
    "questStates": questStates,
    "clearedAchievements": clearedAchievements,
    "challenges": challenges,
    "warpPoints": warpPoints,
    "areas": areas,
    "areaGroups": areaGroups,
    "cities": cities,
    "characterPieces": characterPieces,
    "userData": userData,
    "dungeons": dungeons,
    "magicOrbs": magicOrbs,
    "areaChangeLocks": areaChangeLocks,
    "items": items,
  }

  writeFile(saves_dir & "/" & name & ".save", $jsonData)


proc deleteSaveFile*(saves_dir: string, name: string) =
  removeFile((saves_dir & "/" & name & ".save").Path)