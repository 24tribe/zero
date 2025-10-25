from argparse import ArgumentParser
import json
import re
import sys
import itertools

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

    empty_req_res_hooks = filter(
        lambda x: req_hooks[x][0] == "None" and req_hooks[x][1] == "None", req_hooks
    )

    empty_req_res_hooks = map(lambda x: f"Neon.Model.Api.ApiService$${x}", empty_req_res_hooks)

    empty_req_res_hooks = set(empty_req_res_hooks)

    impl_code, list_data, hookNames = createAutohookH(api_funcs_with_req_and_res, script)

    api_funcs_with_res_only = filter(
        lambda x: req_hooks[x][0] == "None" and req_hooks[x][1] != "None", req_hooks
    )

    api_funcs_with_res_only = [(x, req_hooks[x][1]) for x in api_funcs_with_res_only]

    for name, res in api_funcs_with_res_only:
        path = nameToPath(name)
        list_data.append(f"""{{"Neon.Model.Api.Rpc.{res}", NULL, "{path}"}}, """)

    code = [
        "#ifdef AUTOHOOK_TN_IMPL"
    ] 

    for c in impl_code:
        code.append(c)

    impl_code, moreHookNames = createAutohookHEmptyReqRes(empty_req_res_hooks, script)

    for c in impl_code:
        code.append(c)

    code.append("void AutoHookTN(void) {")
    for hookName in itertools.chain(hookNames, moreHookNames):
        code.append(f"    {hookName}();")

    code.append("}")

    code.append("#endif")

    code.append("#ifndef AUTOHOOK_TN_H_2025_30_02_00")
    code.append("#define AUTOHOOK_TN_H_2025_30_02_00")

    code.append("#define AUTOHOOK_TN_LIST_DATA \\")
    code.append(" \\\n".join(list_data))

    code.append("#endif")

    with open(args.out_h, "w", encoding="utf-8") as f:
        f.write("\n".join(code))

def nameToPath(methodName):
    path = re.findall(r"[A-Z][a-z]+", methodName)
    return f"/{path[0]}/{"_".join(path[1:])}".lower()

def reqNameToPath(req):
    path = re.findall(r"[A-Z][a-z]+", req)
    return f"/{path[0]}/{"_".join(path[1:-1])}".lower()

def getHookName(var):
    return f"Hook_{var}"

def getFpVar(var):
    return f"fp{var}"

def getDetourName(var):
    return f"Detour_{var}"

def getNewSignature(var, detourName, sig):
    newSignature = re.sub(var, detourName, sig)
    newSignature = re.sub(";$", " {", newSignature)
    return newSignature

def getArgs(newSignature):
    return re.findall(r"([a-zA-Z_]+)[,)]", newSignature)

def appendCreateHookFunction(impl_code, hookName, var, detourName, fpVar):
    impl_code.append(f"""
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

def appendDetourFunction(impl_code, funcPtrType, fpVar, req, lastReq, newSignature, args):
    impl_code.append(f"""
{funcPtrType} {fpVar} = NULL;
Neon_Model_Api_Rpc_{req}_o *{lastReq} = NULL;
{newSignature}
    {lastReq} = data;
    return {fpVar}({", ".join(args)});
}}
""")

def appendDetourFunctionEmptyReqRes(impl_code, newSignature, fpVar, args, path, funcPtrType):
    impl_code.append(f"""
{funcPtrType} {fpVar} = NULL;

{newSignature}
    RunNimMainOnce();

    const char *path = "{path}";

    if (ZERO_CONFIG.offlineMode) {{
        SembaCall(path, "");

        return (Cysharp_Threading_Tasks_UniTask_o){{
            .fields = {{.source = NULL, .token = 0}}
        }};
    }} else {{
        SembaLogFlow(path, "", "");
        return {fpVar}({", ".join(args)});
    }}
}}
""")

def createAutohookHEmptyReqRes(empty_req_res_hooks, script):
    hookNames = []

    impl_code = []

    for script_method in script["ScriptMethod"]:
        if script_method["Name"] in empty_req_res_hooks:
            empty_req_res_hooks.remove(script_method["Name"])

            var = getFuncVar(script_method["Name"])
            funcPtrType = getFuncPtrType(var)
            hookName = getHookName(var)

            hookNames.append(hookName)
            fpVar = getFpVar(var)
            detourName = getDetourName(var)

            newSignature = getNewSignature(var, detourName, script_method["Signature"])
            args = getArgs(newSignature)

            match = re.search(r"Neon\.Model\.Api\.ApiService\$\$([^\n]+)", script_method["Name"])
            assert match
            name = match.group(1)
            path = nameToPath(name)

            appendDetourFunctionEmptyReqRes(impl_code, newSignature, fpVar, args, path, funcPtrType)
            appendCreateHookFunction(impl_code, hookName, var, detourName, fpVar)
    
    return impl_code, hookNames

def createAutohookH(req_hooks, script):
    hookNames = []

    list_data = []

    impl_code = []

    for script_method in script["ScriptMethod"]:
        if script_method["Name"] in req_hooks:
            req_hooks.remove(script_method["Name"])

            reqs = re.findall(r"Neon_Model_Api_Rpc_(.+Request)_o", script_method["Signature"])
            assert len(reqs) == 1
            req = reqs[0]

            var = getFuncVar(script_method["Name"])
            funcPtrType = getFuncPtrType(var)
            hookName = getHookName(var)

            hookNames.append(hookName)

            fpVar = getFpVar(var)
            detourName = getDetourName(var)

            responses = re.findall(r"Cysharp_Threading_Tasks_UniTask_(.+Response)__o", script_method["Signature"])
            assert len(responses) == 1
            res = responses[0]

            newSignature = getNewSignature(var, detourName, script_method["Signature"])

            args = getArgs(newSignature)

            lastReq = f"last{req}"

            path = reqNameToPath(req)

            list_data.append(f"""{{"Neon.Model.Api.Rpc.{res}", (Il2CppObject **)&{lastReq}, "{path}"}}, """)

            appendDetourFunction(impl_code, funcPtrType, fpVar, req, lastReq, newSignature, args)

            appendCreateHookFunction(impl_code, hookName, var, detourName, fpVar)

    if req_hooks != set():
        print(f"Couldn't find {req_hooks}")
        sys.exit(1)

    return impl_code, list_data, hookNames

if __name__ == "__main__":
    main()