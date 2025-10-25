import std/json
import std/strutils
import system/ansi_c

import db_connector/db_sqlite

proc DupString(s: cstring): cstring =
  result = cast[cstring](c_malloc((s.len + 1).csize_t))
  copyMem(result, s, s.len + 1)

proc SembaCallUnsafe(uri: cstring, request: cstring): cstring {.exportc.} =
  let jsonReq = if request != "": parseJson($request) else: nil

  let db = open("mytest.db", "", "", "")
  db.close()

  if uri == "echo":
    let dataUpper = jsonReq["data"].getStr().toUpperAscii()
    let resJson = %*{"data": dataUpper}
    result = DupString($resJson)
  elif uri == "/auth/steam_user":
    let res = %*{"userId": "696969696969"}
    result = DupString($res)
  elif uri == "/auth/nonce":
    let res = %*{"nonce": "6969696969696969"}
    result = DupString($res)
  elif uri == "/auth/sign_in":
    let res = %*{"sessionToken": "69696969-6969-6969-6969-696969696969", "language": 2}
    result = DupString($res)
  else:
    result = nil

proc SembaCall(uri: cstring, request: cstring): cstring {.exportc.} =
  try:
    result = SembaCallUnsafe(uri, request)
  except:
    echo("Nim Exception: " & getCurrentExceptionMsg())
    result = nil