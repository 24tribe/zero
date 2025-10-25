import std/json
import std/strutils
import std/strformat
import system/ansi_c

proc DupString(s: cstring): cstring =
  result = cast[cstring](c_malloc((s.len + 1).csize_t))
  copyMem(result, s, s.len + 1)

proc SembaCallUnsafe(uri: cstring, request: cstring): cstring {.exportc.} =
  let jsonReq = if request != "": parseJson($request) else: nil

  if uri == "echo":
    let dataUpper = jsonReq["data"].getStr().toUpperAscii()
    let resJson = %*{"data": dataUpper}
    result = DupString($resJson)
  elif uri == "/auth/steam_user":
    let res = %*{"userId": "690069006900"}
    result = DupString($res)
  else:
    result = nil

proc SembaCall(uri: cstring, request: cstring): cstring {.exportc.} =
  try:
    result = SembaCallUnsafe(uri, request)
  except:
    echo("Nim Exception: " & getCurrentExceptionMsg())
    result = nil