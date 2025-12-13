import std/json

import db_connector/db_sqlite

import sembacore

proc loadSaveFile*(db: DbConn, path: string): string =
  const baseError = "Couldn't load save file"

  if db == nil:
    return baseError & ", db is not initialized"

  let content = readFile(path)
  let jsonData = parseJson(content)

  let version = jsonData["version"].getInt()

  if version != 2:
    return baseError & ", invalid version: should be " & $version

  let formations = jsonData["formations"]

  for formation in formations:
    updateFormation(db, formation)

proc createSaveFile*(db: DbConn, path: string): string =
  const baseError = "Couldn't create save file"

  if db == nil:
      return baseError & ", db is not initialized"

  let formations = getFormations(db)

  var jsonData = %*{
    "version": 2,
    "formations": formations,
  }

  writeFile(path, $jsonData)