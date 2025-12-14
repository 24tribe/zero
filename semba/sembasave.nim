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

  db.exec(sql"BEGIN")
  for formation in formations:
    updateFormation(db, formation)
  db.exec(sql"COMMIT")

  if version >= 3:
    let tips = jsonData["tips"]

    db.exec(sql"DELETE FROM tips")

    db.exec(sql"BEGIN")
    for tip in tips:
      addTip(db, tip)
    db.exec(sql"COMMIT")

    let areaObjects = jsonData["areaObjects"]

    db.exec(sql"DELETE FROM areaObjects")

    db.exec(sql"BEGIN")
    for areaObject in areaObjects:
      addAreaObject(db, areaObject)
    db.exec(sql"COMMIT")

    let areaEnemies = jsonData["areaEnemies"]

    db.exec(sql"DELETE FROM areaEnemies")

    db.exec(sql"BEGIN")
    for areaEnemy in areaEnemies:
      addAreaEnemy(db, areaEnemy)
    db.exec(sql"COMMIT")

  if version >= 4:
    let status = jsonData["status"]
    setUserStatus(db, status)

proc createSaveFile*(db: DbConn, saves_dir: string, name: string): string =
  const baseError = "Couldn't create save file"

  if db == nil:
      return baseError & ", db is not initialized"

  let formations = getFormations(db)
  let tips = getTips(db)
  let areaObjects = getAreaObjects(db)
  let areaEnemies = getAreaEnemies(db)
  let status = getUserStatus(db)

  var jsonData = %*{
    "version": 4,
    "formations": formations,
    "tips": tips,
    "areaObjects": areaObjects,
    "areaEnemies": areaEnemies,
    "status": status,
  }

  writeFile(saves_dir & "/" & name & ".save", $jsonData)