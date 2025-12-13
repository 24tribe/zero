import std/json

import db_connector/db_sqlite

import sembacore

proc loadSaveFile*(db: DbConn, saves_dir: string, name: string): string =
  const baseError = "Couldn't load save file"

  if db == nil:
    return baseError & ", db is not initialized"

  let content = readFile(saves_dir & "/" & name & ".save")
  let jsonData = parseJson(content)

  let version = jsonData["version"].getInt()

  if version < 2:
    return baseError & ", invalid version: should be >= 2"

  let formations = jsonData["formations"]

  for formation in formations:
    updateFormation(db, formation)

  if version >= 3:
    let tips = jsonData["tips"]

    db.exec(sql"DELETE FROM tips")

    for tip in tips:
      addTip(db, tip)

    let areaObjects = jsonData["areaObjects"]

    db.exec(sql"DELETE FROM areaObjects")

    for areaObject in areaObjects:
      addAreaObject(db, areaObject)

    let areaEnemies = jsonData["areaEnemies"]

    db.exec(sql"DELETE FROM areaEnemies")

    for areaEnemy in areaEnemies:
      addAreaEnemy(db, areaEnemy)

proc createSaveFile*(db: DbConn, saves_dir: string, name: string): string =
  const baseError = "Couldn't create save file"

  if db == nil:
      return baseError & ", db is not initialized"

  let formations = getFormations(db)
  let tips = getTips(db)
  let areaObjects = getAreaObjects(db)
  let areaEnemies = getAreaEnemies(db)

  var jsonData = %*{
    "version": 3,
    "formations": formations,
    "tips": tips,
    "areaObjects": areaObjects,
    "areaEnemies": areaEnemies,
  }

  writeFile(saves_dir & "/" & name & ".save", $jsonData)