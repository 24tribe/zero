import std/strutils
import std/json

import db_connector/db_sqlite

import sembasave

type GachaRateId = enum
  NormalPullThreeStarCharRateId = 101,
  NormalPullThreeStarTCRateId = 102,
  NormalPullTwoStarCharRateId = 103,
  NormalPullTwoStarTCRateId = 104,
  NormalPullOneStarTCRateId = 105,

  GuaranteedPullThreeStarCharRateId = 106,
  GuaranteedPullThreeStarTCRateId = 107,

  PromisedPullThreeStarCharRateId = 108,
  PromisedPullThreeStarTCRateId = 109,
  PromisedPullTwoStarCharRateId = 110,
  PromisedPullTwoStarTCRateId = 111


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


proc semba_DeleteSaveFile(jsonReq: JsonNode) =
  let saves_dir = jsonReq["saves_dir"].getStr()
  let name = jsonReq["name"].getStr()

  deleteSaveFile(saves_dir, name)


proc semba_GetStdGachaRates(db: DbConn): JsonNode =
  let rateIds = [
    NormalPullThreeStarCharRateId,
    NormalPullThreeStarTCRateId,
    NormalPullTwoStarCharRateId,
    NormalPullTwoStarTCRateId,
    NormalPullOneStarTCRateId,
    GuaranteedPullThreeStarCharRateId,
    GuaranteedPullThreeStarTCRateId,
    PromisedPullThreeStarCharRateId,
    PromisedPullThreeStarTCRateId,
    PromisedPullTwoStarCharRateId,
    PromisedPullTwoStarTCRateId
  ]

  result = %*{}

  db.exec(sql"BEGIN")
  for rateId in rateIds:
    let row = db.getRow(sql"SELECT percentRate FROM gachaRates WHERE gachaRateId = ?", rateId.int)
    result[$rateId] = %*parseFloat(row[0])
  db.exec(sql"COMMIT")


proc semba_SetStdGachaRates(db: DbConn, jsonReq: JsonNode) =
  db.exec(sql"BEGIN")
  for key, val in jsonReq.pairs():
    let rateId = parseEnum[GachaRateId](key)
    let percentRate = val.getFloat()
    db.exec(
      sql"UPDATE gachaRates SET percentRate = ? WHERE gachaRateId = ?",
      $percentRate, rateId.int
    )
  db.exec(sql"COMMIT")


proc getJsonResultPrivateApi*(uri: string, jsonReq: JsonNode, db: DbConn): JsonNode =
  if uri == "/semba/echo":
    let dataUpper = jsonReq["data"].getStr().toUpperAscii()
    result = %*{"data": dataUpper}
  elif uri == "/semba/load_save_file":
    result = semba_LoadSaveFile(jsonReq, db)
  elif uri == "/semba/create_save_file":
    result = semba_CreateSaveFile(jsonReq, db)
  elif uri == "/semba/delete_save_file":
    semba_DeleteSaveFile(jsonReq)
  elif uri == "/semba/get_std_gacha_rates":
    result = semba_GetStdGachaRates(db)
  elif uri == "/semba/set_std_gacha_rates":
    semba_SetStdGachaRates(db, jsonReq)