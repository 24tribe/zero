import std/strutils
import std/json

import db_connector/db_sqlite

import sembasave
import extsqlite

const sembaSql = slurp("semba.sql")

type HairColor* = object
  charId*: int
  r*: float
  g*: float
  b*: float
  enabled*: bool

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


proc semba_ResetDb(db: DbConn) =
  loadSql(db, sembaSql)


proc semba_UpdateHairColor(db: DbConn, jsonReq: JsonNode): JsonNode =
  let req = to(jsonReq, HairColor)
  db.exec(sql"""
    INSERT INTO hairColors (charId, r, g, b, enabled)
    VALUES (?, ?, ?, ?, ?)
    ON CONFLICT (charId) DO
    UPDATE SET r = excluded.r, g = excluded.g, b = excluded.b, enabled = excluded.enabled
  """, req.charId, req.r, req.g, req.b, req.enabled)

  result = %*{
    "status": "ok"
  }


proc semba_GetHairColors(db: DbConn): seq[HairColor] =
  let rows = db.getAllRows(sql"SELECT charId, r, g, b, enabled FROM hairColors")

  for row in rows:
    result.add(HairColor(
      charId: parseInt(row[0]),
      r: parseFloat(row[1]),
      g: parseFloat(row[2]),
      b: parseFloat(row[3]),
      enabled: row[4] == "true"
    ))


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
  elif uri == "/semba/reset_db":
    semba_ResetDb(db)
  elif uri == "/semba/update_hair_color":
    result = semba_UpdateHairColor(db, jsonReq)
  elif uri == "/semba/get_hair_colors":
    result = %*semba_GetHairColors(db)