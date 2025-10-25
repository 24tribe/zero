from argparse import ArgumentParser
import re

def read_hooks(path):
    with open(path, "r", encoding="utf-8") as f:
        csv = list(map(lambda x: x.split(","), re.findall(r"[^\n]+", f.read())))

    return {name: (req, res) for name, req, res in csv}

def main():
    parser = ArgumentParser()
    parser.add_argument("neon_api_csv")
    parser.add_argument("req_hooks_csv")

    args = parser.parse_args()

    neon_api = read_hooks(args.neon_api_csv)
    req_hooks = read_hooks(args.req_hooks_csv)

    for name in neon_api:
        if name not in req_hooks:
            print(name)

if __name__ == "__main__":
    main()