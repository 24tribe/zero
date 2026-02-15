import std/asynchttpserver
import std/asyncdispatch
import std/cmdline
import std/parseutils
import std/strutils
import std/options

import db_connector/db_sqlite

import sembacore

proc main {.async.} =
  let cmdParams = commandLineParams()
  if cmdParams.len != 2:
    echo("Usage: sembaserver port semba_db")
    return

  let portStr = paramStr(1)
  var port: int

  let dbPath = paramStr(2)
  echo("Using dbPath = ", dbPath)

  if parseInt(portStr, port) != portStr.len:
    echo("Failed to parse port '", portStr, "'")
    return

  var db = open(dbPath, "", "", "")
  var lastBattleInfo = none(BattleInfo)

  var server = newAsyncHttpServer()

  proc cb(req: Request) {.async, gcsafe.} =
    let path = req.url.path
    let body = req.body
    let headers = newHttpHeaders({"Content-type": "text/plain; charset=utf-8"})
    echo("uri: ", path)
    echo("req: ", body)
    try:
      let version = parseEnum[GameVersion](req.headers["user-agent"])
      let res = sembaCallImpl(path, body, version, db, lastBattleInfo)
      await req.respond(Http200, res, headers)
    except Exception:
      let e = getCurrentException()
      echo "[SembaServer cb] Nim Exception: " & getCurrentExceptionMsg()
      echo e.getStackTrace()
      await req.respond(Http500, "", headers)

  server.listen(Port(port), "127.0.0.1")

  echo "listening in 127.0.0.1:" & $port.uint16 & "/"
  while true:
    if server.shouldAcceptRequest():
      await server.acceptRequest(cb)
    else:
      # too many concurrent connections, `maxFDs` exceeded
      # wait 500ms for FDs to be closed
      await sleepAsync(500)

waitFor main()