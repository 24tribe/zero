import std/strutils
import std/json

import db_connector/db_sqlite

proc getJsonResultPrivateApi*(uri: string, jsonReq: JsonNode, db: DbConn): JsonNode =
  if uri == "/semba/echo":
    let dataUpper = jsonReq["data"].getStr().toUpperAscii()
    result = %*{"data": dataUpper}