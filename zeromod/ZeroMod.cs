using MelonLoader;
using Il2CppBest.HTTP;
using HarmonyLib;

[assembly: MelonInfo(typeof(zeromod.ZeroMod), "ZeroMod", "0.1.0", "TNZ contributors")]
[assembly: MelonGame("Akatsuki Games Inc.", "tribenine")]

namespace zeromod;

public class ZeroMod : MelonMod
{
    private static MelonLogger.Instance? logger;

    [HarmonyPatch(typeof(HTTPRequest), ".ctor", new Type[] { typeof(Uri), typeof(HTTPMethods) })]
    private static class DetourHTTPRequestCtor
    {
        private static void Prefix(ref Uri uri, HTTPMethods method) {
            if (logger != null) {
                logger.Msg("DetourHTTPRequestCtor called!");
            }
            uri = new Uri("https://httpbin.org/status/500");
        }
    }

    public override void OnInitializeMelon()
    {
        logger = LoggerInstance;
    }
}