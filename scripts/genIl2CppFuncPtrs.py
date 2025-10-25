from argparse import ArgumentParser
import json
import re
import sys

def main():
    parser = ArgumentParser()
    parser.add_argument("script_json")
    parser.add_argument("game_funcs_txt")
    parser.add_argument("output_c")
    args = parser.parse_args()

    with open(args.script_json, "r", encoding="utf-8") as f:
        script = json.load(f)

    with open(args.game_funcs_txt, "r", encoding="utf-8") as f:
        game_funcs = re.findall(r"([^\n]+)", f.read())

    signatures = []
    definitions = []
    inits = []

    for game_func in game_funcs:
        found = False
        for script_method in script["ScriptMethod"]:
            if script_method["Name"] == game_func:
                found = True
                signature, definition, init = genDefinitions(game_func, script_method)
                signatures.append(signature)
                definitions.append(definition)
                inits.append(init)
                break
        if not found:
            print(f"Couldn't find definitions for {gameFunc}")
            sys.exit(1)

    with open(args.output_c, "w", encoding="utf-8") as f:
        f.write("\n".join(signatures))
        f.write("\n")
        f.write("\n".join(definitions))
        f.write("\n")
        f.write("void InitGameFuncPtrs(void *GameAssembly) {\n  ")
        f.write("\n  ".join(inits))
        f.write("\n}\n")

    print("OK")

def genDefinitions(game_func, script_method):
    funcVar = re.sub(r"[^a-zA-Z]", "_", game_func)
    funcPtrType = f"{funcVar}_FuncPtr"

    signature = "typedef " + script_method["Signature"].replace(funcVar, f"(*{funcPtrType})")
    definition = f"{funcPtrType} {funcVar} = NULL;"
    init = f"{funcVar} = ({funcPtrType})((unsigned long long)GameAssembly + {script_method['Address']}ull);"
    return signature, definition, init

if __name__ == "__main__":
    main()