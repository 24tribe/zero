import std/strutils
import std/json

import db_connector/db_sqlite

import sembasave


proc semba_LoadSaveFile(jsonReq: JsonNode, db: DbConn): JsonNode =
  let saves_dir = jsonReq["saves_dir"].getStr()
  let name = jsonReq["name"].getStr()

  let err = loadSaveFile(db, saves_dir, name)

  return %*{
    "err": err
  }


proc semba_CreateSaveFile(jsonReq: JsonNode, db: DbConn): JsonNode =
  let saves_dir = jsonReq["saves_dir"].getStr()
  let name = jsonReq["name"].getStr()

  let err = createSaveFile(db, saves_dir, name)

  return %*{
    "err": err
  }


proc getJsonResultPrivateApi*(uri: string, jsonReq: JsonNode, db: DbConn): JsonNode =
  if uri == "/semba/echo":
    let dataUpper = jsonReq["data"].getStr().toUpperAscii()
    result = %*{"data": dataUpper}
  elif uri == "/semba/load_save_file":
    result = semba_LoadSaveFile(jsonReq, db)
  elif uri == "/semba/create_save_file":
    result = semba_CreateSaveFile(jsonReq, db)