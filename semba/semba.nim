import std/assertions
import std/json
import std/httpclient
import system/ansi_c

import db_connector/db_sqlite

import sembacore

type SembaContext = object
  db: DbConn
  remoteUrl: string
  lastBattleStartReq: BattleStartRequest

var ctx = SembaContext(db: nil, remoteUrl: "", lastBattleStartReq: BattleStartRequest(val : nil))

proc dupString(str: string): cstring =
  let s = str.cstring
  result = cast[cstring](c_malloc((s.len + 1).csize_t))
  copyMem(result, s, s.len + 1)

proc SembaInitOfflineDb*(path: cstring) {.exportc.} = 
  ctx.db = open($path, "", "", "")

proc SembaSetRemoteUrl(remUrl: cstring) {.exportc.} =
  ctx.remoteUrl = $remUrl

proc sembaCallRemote(uri: string, request: string, version: GameVersion, remoteUrl: string): string =
  var client = newHttpClient($version)
  try:
    let res = client.postContent(remoteUrl & uri, request)
    return res
  finally:
    client.close()

proc sembaCallUnsafe*(uri: string, request: string, version: GameVersion): string =
  if ctx.remoteUrl != "":
    return sembaCallRemote(uri, request, version, ctx.remoteUrl)

  return sembaCallImpl(uri, request, version, ctx.db, ctx.lastBattleStartReq)

proc SembaCallDemo(uri: cstring, request: cstring): cstring {.exportc.} =
  try:
    let res = sembaCallUnsafe($uri, $request, gvDemo)
    result = if res != "": dupString(res) else: nil
  except Exception:
    let e = getCurrentException()
    echo "[SembaCallDemo] Nim Exception: " & getCurrentExceptionMsg()
    echo e.getStackTrace()
    result = nil

proc SembaCall(uri: cstring, request: cstring): cstring {.exportc.} =
  try:
    let res = sembaCallUnsafe($uri, $request, gvStable)
    result = if res != "": dupString(res) else: nil
  except Exception:
    let e = getCurrentException()
    echo "[SembaCall] Nim Exception: " & getCurrentExceptionMsg()
    echo e.getStackTrace()
    result = nil

proc isPristineDb(db: DbConn): bool = db.getRow(sql"SELECT uri FROM debugLogsOffline")[0] == ""

proc loadSave(db: DbConn, path: string) =
  let saveStr = readFile(path)

  let save = parseJson(saveStr)

  if isPristineDb(db):
    for row in save["reqs"]:
      let uri = row[0].getStr()
      let req = row[1]
      let res = sembaCallUnsafe(uri, $req, gvStable) # FIXME: add version param to loadSave
      if res == "":
        echo "[loadSave][!] '" & uri & "' is not implemented"
  else:
    echo "[loadSave] db is not pristine, skipping savefile '" & path & "'"

proc SembaLoadSave(path: cstring) {.exportc.} =
  try:
    loadSave(ctx.db, $path)
  except Exception:
    let e = getCurrentException()
    echo "[SembaLoadSave] Nim Exception: " & getCurrentExceptionMsg()
    echo e.getStackTrace()