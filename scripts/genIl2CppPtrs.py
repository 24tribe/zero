from argparse import ArgumentParser
import json
import re
import sys

def main():
    parser = ArgumentParser()
    parser.add_argument("script_json")
    parser.add_argument("game_funcs_txt")
    parser.add_argument("type_infos")
    parser.add_argument("output_c")

    args = parser.parse_args()

    with open(args.script_json, "r", encoding="utf-8") as f:
        script = json.load(f)

    with open(args.game_funcs_txt, "r", encoding="utf-8") as f:
        game_funcs = re.findall(r"([^\n]+)", f.read())

    signatures = []
    definitions = []
    inits = []
    decls = []

    for game_func in game_funcs:
        found = False
        for script_method in script["ScriptMethod"]:
            if script_method["Name"] == game_func:
                found = True
                signature, definition, init, decl = genDefinitions(game_func, script_method)
                signatures.append(signature)
                definitions.append(definition)
                inits.append(init)
                decls.append(decl)
                break
        if not found:
            print(f"Couldn't find definitions for {game_func}")
            sys.exit(1)

    with open(args.type_infos, "r", encoding="utf-8") as f:
        type_infos = re.findall(r"([^\n]+)", f.read())

    type_defs = []
    type_inits = []

    for type_info in type_infos:
        found = False
        for script_metadata in script["ScriptMetadata"]:
            if script_metadata["Name"] == type_info:
                found = True
                definition, init, decl = genTypeDefinitions(type_info, script_metadata)
                type_defs.append(definition)
                type_inits.append(init)
                decls.append(decl)
        if not found:
            print(f"Couldn't find type definitions for {type_info}")
            sys.exit(1)

    with open(args.output_c, "w", encoding="utf-8") as f:
        f.write("#ifndef FUNCPTRS_H_2025_09_23_04_08\n")
        f.write("#define FUNCPTRS_H_2025_09_23_04_08\n")
        f.write("#include <stddef.h>")
        f.write("\n#include \"il2cpp_lean.h\"\n")
        f.write("\n".join(signatures))
        f.write("\n")
        f.write("\n".join(decls))
        f.write(f"\nextern void InitGamePtrs(void *GameAssembly);\n")
        f.write("\n#endif\n")
        f.write("\n#ifdef FUNCPTRS_IMPL\n")
        f.write("\n".join(definitions))
        f.write("\n")
        f.write("\n".join(type_defs))
        f.write("\n")
        f.write(f"void InitGamePtrs(void *GameAssembly) {{\n  ")
        f.write("\n  ".join(inits))
        f.write("\n  ")
        f.write("\n  ".join(type_inits))
        f.write("\n}\n")
        f.write("#endif\n")

    print("OK")

def genTypeDefinitions(type_info, script_metadata):
    varname = re.sub(r"[^a-zA-Z]", "_", type_info)
    definition = f"Il2CppClass **{varname} = NULL;"
    init = f"{varname} = (Il2CppClass **)((unsigned long long)GameAssembly + {script_metadata["Address"]}ull);"
    decl = f"extern Il2CppClass **{varname};"
    return definition, init, decl

def getFuncVar(game_func):
    return re.sub(r"[^a-zA-Z]", "_", game_func)

def getFuncPtrType(funcVar):
    return f"{funcVar}_FuncPtr"

def genDefinitions(game_func, script_method):
    funcVar = getFuncVar(game_func)
    funcPtrType = getFuncPtrType(funcVar)

    signature = "typedef " + script_method["Signature"].replace(funcVar, f"(*{funcPtrType})")
    definition = f"{funcPtrType} {funcVar} = NULL;"
    init = f"{funcVar} = ({funcPtrType})((unsigned long long)GameAssembly + {script_method['Address']}ull);"
    decl = f"extern {funcPtrType} {funcVar};"
    return signature, definition, init, decl

if __name__ == "__main__":
    main()