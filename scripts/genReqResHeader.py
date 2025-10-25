from argparse import ArgumentParser
import re

from listUnhookedFuncs import read_hooks

def getStructNames(name):
    return set((
        f"{name}_Fields",
        f"{name}_VTable",
        f"{name}_c",
        f"{name}_o"
    ))

def getReqFullName(name):
    return f"Neon_Model_Api_Rpc_{name}"

def getResFullName(name):
    return f"Cysharp_Threading_Tasks_UniTask_{name}_"

def get_structs(il2cpp_h):
    return re.finditer(r"struct (?:__declspec\(align\(8\)\) )?([^\s]+) {[^}]+};", il2cpp_h)

def main():
    parser = ArgumentParser()
    parser.add_argument("il2cpp_h")
    parser.add_argument("req_hooks_csv")
    args = parser.parse_args()

    with open(args.il2cpp_h, "r", encoding="utf-8") as f:
        il2cpp_h = f.read()

    req_hooks = read_hooks(args.req_hooks_csv)

    struct_names = set()

    for name in req_hooks:
        req, res = req_hooks[name]
        fullReq = getReqFullName(req)
        struct_names |= getStructNames(fullReq)

        fullRes = getResFullName(res)
        struct_names |= getStructNames(fullRes)

    for s in get_structs(il2cpp_h):
        if s.group(1) in struct_names:
            code = s.group(0).replace("__declspec(align(8)) ", "")
            print(f"typedef {code.strip()[:-1]} {s.group(1)};\n")



if __name__ == "__main__":
    main()