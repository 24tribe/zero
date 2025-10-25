from argparse import ArgumentParser
import json
import re
import sys

from genIl2CppPtrs import getFuncVar, getFuncPtrType
from listUnhookedFuncs import read_hooks

def main():
    parser = ArgumentParser()
    parser.add_argument("script_json")
    parser.add_argument("req_hooks_csv")
    parser.add_argument("out_h")

    args = parser.parse_args()

    req_hooks = read_hooks(args.req_hooks_csv)

    with open(args.script_json, "r", encoding="utf-8") as f:
        script = json.load(f)

    api_funcs_with_req_and_res = filter(
        lambda x: req_hooks[x][0] != "None" and req_hooks[x][1] != "None", req_hooks
    )

    api_funcs_with_req_and_res = map(lambda x: f"Neon.Model.Api.ApiService$${x}", api_funcs_with_req_and_res)

    api_funcs_with_req_and_res = set(api_funcs_with_req_and_res)
     
    autohook_h = createAutohookH(api_funcs_with_req_and_res, script)

    with open(args.out_h, "w", encoding="utf-8") as f:
        f.write(autohook_h)

def createAutohookH(req_hooks, script):
    hookNames = []

    list_data = []

    code = [
        "#ifdef AUTOHOOK_TN_IMPL"
    ]

    for script_method in script["ScriptMethod"]:
        if script_method["Name"] in req_hooks:
            req_hooks.remove(script_method["Name"])

            reqs = re.findall(r"Neon_Model_Api_Rpc_(.+Request)_o", script_method["Signature"])
            assert len(reqs) == 1
            req = reqs[0]

            var = getFuncVar(script_method["Name"])
            funcPtrType = getFuncPtrType(var)
            hookName = f"Hook_{var}"

            hookNames.append(hookName)

            fpVar = f"fp{var}"
            detourName = f"Detour_{var}"
            responses = re.findall(r"Cysharp_Threading_Tasks_UniTask_(.+Response)__o", script_method["Signature"])
            assert len(responses) == 1
            res = responses[0]

            newSignature = re.sub(var, detourName, script_method["Signature"])
            newSignature = re.sub(";$", " {", newSignature)

            args = re.findall(r"([a-zA-Z_]+)[,)]", newSignature)

            lastReq = f"last{req}"

            path = re.findall(r"[A-Z][a-z]+", req)
            path = f"/{path[0]}/{"_".join(path[1:-1])}".lower()

            list_data.append(f"""{{"Neon.Model.Api.Rpc.{res}", (Il2CppObject **)&{lastReq}, "{path}"}}, """)

            code.append(f"{funcPtrType} {fpVar} = NULL;")
            code.append(f"Neon_Model_Api_Rpc_{req}_o *{lastReq} = NULL;")
            code.append(f"""
{newSignature}
    {lastReq} = data;
    return {fpVar}({", ".join(args)});
}}
""")

            code.append(f"""
void {hookName}(void) {{
    if (MH_CreateHook(
        (void *)(uintptr_t){var},
        (LPVOID)(uintptr_t)&{detourName},
        (LPVOID *)&{fpVar}
    ) != MH_OK) {{
        printf("Failed to create {var} hook\\n");
        return;
    }}

    if (MH_EnableHook((void *)(uintptr_t){var}, /* changePermissions = */ FALSE) != MH_OK) {{
        printf("Failed to enable {var} hook\\n");
        return;
    }}
}}
            """)

    if req_hooks != set():
        print(f"Couldn't find {req_hooks}")
        sys.exit(1)

    code.append("void AutoHookTN(void) {")
    for hookName in hookNames:
        code.append(f"    {hookName}();")

    code.append("}")

    code.append("#endif")

    code.append("#ifndef AUTOHOOK_TN_H_2025_30_02_00")
    code.append("#define AUTOHOOK_TN_H_2025_30_02_00")
    code.append("#define AUTOHOOK_TN_LIST_DATA \\")
    code.append(" \\\n".join(list_data))
    code.append("#endif")

    return "\n".join(code) 

if __name__ == "__main__":
    main()