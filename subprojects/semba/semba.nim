import std/json
import std/strutils
import system/ansi_c

proc DupString(s: cstring): cstring =
  result = cast[cstring](c_malloc((s.len + 1).csize_t))
  copyMem(result, s, s.len + 1)

proc SembaCall(uri: cstring, request: cstring): cstring {.exportc.} =
  let jsonReq = parseJson($request) 

  if uri == "echo":
    let dataUpper = jsonReq["data"].getStr().toUpperAscii()
    let resJson = %*{"data": dataUpper}
    result = DupString($resJson)
  else:
    result = nil