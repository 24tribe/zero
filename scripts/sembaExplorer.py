import json
import sqlite3
import tempfile
import subprocess
import asyncio

from aiohttp import web
import aiohttp

from dumpSembaLogs import get_debug_logs

jq_path = r"D:/Programas/w64devkit/bin/jq.exe"

def call_jq(json_data, query):
    try:
        return subprocess.check_output(
            [jq_path, query], input=json_data, encoding="utf-8", stderr=subprocess.STDOUT
        )
    except subprocess.CalledProcessError as ex:
        return ex.output

async def index(req):
    return web.FileResponse("www/index.html")

ctx = {
    "jqReqs": asyncio.Queue()
}

async def process_queue(ws):
    req = None
    while True:
        try:
            try:
                req = await asyncio.wait_for(ctx["jqReqs"].get(), timeout=0.5)
            except TimeoutError:
                if req != None:
                    res = call_jq(ctx["jsonData"], req)
                    req = None
                    await ws.send_str(res)
        except Exception as ex:
            await ws.send_str(repr(ex))

async def process_messages(ws):
    async for msg in ws:
        if msg.type == aiohttp.WSMsgType.TEXT:
            try:
                data = json.loads(msg.data)
                if data["action"] == "changeDbPath":
                    ctx["jsonData"] = json.dumps(get_debug_logs(data["value"]))
                    await ws.send_str(f'onlineLogs read correctly')
                elif data["action"] == "query":
                    ctx["jqReqs"].put_nowait(data["value"])
            except Exception as ex:
                await ws.send_str(repr(ex))
        elif msg.type == aiohttp.WSMsgType.ERROR:
            print('ws connection closed with exception %s' %
                  ws.exception())

async def websocket_handler(request):

    ws = web.WebSocketResponse()
    await ws.prepare(request)

    await asyncio.gather(process_queue(ws), process_messages(ws))    

    print('websocket connection closed')

    return ws

def main():
    app = web.Application()
    app.add_routes([
        web.get("/", index),
        web.get("/ws", websocket_handler)
    ])

    web.run_app(app, host="127.0.0.1")

if __name__ == "__main__":
    main()