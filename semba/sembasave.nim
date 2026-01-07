import std/json

import db_connector/db_sqlite

import sembacore

proc resetAreaObjects*(db: DbConn) =
  db.exec(sql"DELETE FROM areaObjects")
  db.exec(sql"INSERT INTO areaObjects SELECT * FROM areaObjectsOriginal")
  db.exec(sql"DELETE FROM areaEnemies")
  db.exec(sql"INSERT INTO areaEnemies SELECT * FROM areaEnemiesOriginal")
  db.exec(sql"DELETE FROM areaBgm")
  db.exec(sql"INSERT INTO areaBgm SELECT * FROM areaBgmOriginal")

# version 3: tips, areaObjects, areaEnemies
proc loadSaveFileVer3(db: DbConn, jsonData: JsonNode, dontDeleteAllAreaObjects: bool) =
  let tips = jsonData["tips"]

  db.exec(sql"DELETE FROM tips")

  db.exec(sql"BEGIN")
  for tip in tips:
    addTip(db, tip)
  db.exec(sql"COMMIT")

  let areaObjects = jsonData["areaObjects"]

  if not dontDeleteAllAreaObjects:
    db.exec(sql"DELETE FROM areaObjects")

  db.exec(sql"BEGIN")
  for areaObject in areaObjects:
    addAreaObject(db, areaObject)
  db.exec(sql"COMMIT")

  let areaEnemies = jsonData["areaEnemies"]

  if not dontDeleteAllAreaObjects:
    db.exec(sql"DELETE FROM areaEnemies")

  db.exec(sql"BEGIN")
  for areaEnemy in areaEnemies:
    addAreaEnemy(db, areaEnemy)
  db.exec(sql"COMMIT")

#[
version 5: (
  debugLogsOffline, areaBgm, characters, tensionCards,
  challengeProgresses, nineSequences, totalTasks, tutorialStates,
  adventureVariables, challengeTasks, areaActionSequenceIds, questStates
  clearedAchievements
)
]#
proc loadSaveFileVer5(db: DbConn, jsonData: JsonNode, dontDeleteAllAreaObjects: bool) =
  db.exec(sql"BEGIN")

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

  for character in characters:
    addCharacter(db, character)

  let tensionCards = jsonData["tensionCards"]

  db.exec(sql"DELETE FROM tensionCards")

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

  db.exec(sql"COMMIT")

#[
version 2: formations
version 4: userStatus
version 6: has new areaObjects
]#
proc loadSaveFile*(db: DbConn, saves_dir: string, name: string): string =
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

  db.exec(sql"BEGIN")
  for formation in formations:
    updateFormation(db, formation)
  db.exec(sql"COMMIT")

  # all saves until version 5 are stuck in the first three areas
  let dontDeleteAllAreaObjects = version <= 5

  if version >= 3:
    if dontDeleteAllAreaObjects:
      db.exec(sql"BEGIN")
      db.exec(sql"DELETE FROM areaObjects WHERE areaId=300402 or areaId=300401 or areaId=101381")
      db.exec(sql"DELETE FROM areaEnemies WHERE areaId=300402 or areaId=300401 or areaId=101381")
      db.exec(sql"DELETE FROM areaBgm WHERE areaId=300402 or areaId=300401 or areaId=101381")
      db.exec(sql"END")

    loadSaveFileVer3(db, jsonData, dontDeleteAllAreaObjects)

  if version >= 4:
    let status = jsonData["status"]
    setUserStatus(db, status)

  if version >= 5:
    loadSaveFileVer5(db, jsonData, dontDeleteAllAreaObjects)

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

  var jsonData = %*{
    "version": 6,
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
  }

  writeFile(saves_dir & "/" & name & ".save", $jsonData)