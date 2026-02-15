import std/httpclient
import std/options
import system/ansi_c

import db_connector/db_sqlite

import sembacore

type SembaContext = object
  db: DbConn
  remoteUrl: string
  lastBattleInfo: Option[BattleInfo]

var ctx = SembaContext(db: nil, remoteUrl: "", lastBattleInfo: none(BattleInfo))

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

  return sembaCallImpl(uri, request, version, ctx.db, ctx.lastBattleInfo)

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