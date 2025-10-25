from argparse import ArgumentParser
import json

from dumpSembaLogs import get_debug_logs

def main():
    parser = ArgumentParser()
    parser.add_argument("semba_db")
    parser.add_argument("out_har")
    args = parser.parse_args()
    debug_logs = get_debug_logs(args.semba_db)

    author = {"name": "semba", "version": "0.1"}

    entries = debug_logs_to_har_entries(debug_logs)

    har = {
        "log": {
            "version": "1.2",
            "creator": author,
            "browser": author,
            "pages": [],
            "entries": entries
        }
    }

    with open(args.out_har, "w", encoding="utf-8") as f:
        json.dump(har, f, indent=2)

def debug_logs_to_har_entries(debug_logs):
    har_entries = []

    for debug_log in debug_logs:
        body = json.dumps(debug_log["req"], indent=2)
        bodySize = len(body.encode("utf-8"))

        content = json.dumps(debug_log["res"], indent=2)
        contentSize = len(content.encode("utf-8"))

        response = {
            "status": 200,
            "statusText": "",
            "httpVersion": "HTTP/2.0",
            "headers": [],
            "cookies": [],
            "content": {
                "mimeType": "application/json",
                "size": contentSize,
                "text": content
            },
            "redirectURL": "",
            "headersSize": 0,
            "bodySize": -1
        }

        host = "game.tribenine-game.com"

        request = {
            "bodySize": bodySize,
            "method": "POST",
            "url": f"https://{host}" + debug_log["uri"],
            "httpVersion": "HTTP/2.0",
            "headers": [
                {
                    "name": "Host",
                    "value": host
                },
                {
                    "name": "User-Agent",
                    "value": "semba 0.1"
                },
                {
                    "name": "Content-Type",
                    "value": "application/json"
                },
                {
                    "name": "Content-Length",
                    "value": str(contentSize)
                },
                {
                    "name": "Origin",
                    "value": f"https://{host}"
                },
            ],
            "cookies": [],
            "queryString": [],
            "headersSize": -1,
            "postData": {
                "mimeType": "application/json",
                "params": [],
                "text": body
            }
        }

        entry = {
            "startedDateTime": debug_log["receivedAt"],
            "request": request,
            "response": response,
            "cache": {},
            "timings": {
                "blocked": 0,
                "dns": 0,
                "connect": 0,
                "ssl": 0,
                "send": 0,
                "wait": 228,
                "receive": 0
            },
            "time": 228,
            "_securityState": "secure",
            "serverIPAddress": "2606:4700:20::681a:7e0",
            "connection": "443",
        }

        har_entries.append(entry)

    return har_entries

if __name__ == "__main__":
    main()