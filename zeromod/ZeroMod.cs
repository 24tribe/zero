using MelonLoader;

[assembly: MelonInfo(typeof(zeromod.ZeroMod), "ZeroMod", "0.1.0", "TNZ contributors")]
[assembly: MelonGame("Akatsuki Games Inc.", "tribenine")]

namespace zeromod;

public class ZeroMod : MelonMod
{
    public override void OnInitializeMelon()
    {
        LoggerInstance.Msg("Hello World!");
    }
}