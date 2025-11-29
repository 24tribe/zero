MelonLoader mod for Tribe Nine Open Beta

Build instructions
------------------

- Install the x64 version of the [net6.0 sdk](https://dotnet.microsoft.com/en-us/download/dotnet/6.0#runtime-desktop-6.0.19)
- Install [MelonLoader 0.7.1](https://github.com/LavaGang/MelonLoader/releases/tag/v0.7.1) into the game
- Open the game and wait to the end of the assemblies dump and close it
- Open the .csproj and set the value of the TribeNineRoot property to the game's directory path,
  for example:

```
<PropertyGroup>
    <TargetFramework>net6.0</TargetFramework>
    <ImplicitUsings>enable</ImplicitUsings>
    <Nullable>enable</Nullable>
    <TribeNineRoot>D:\TRIBE NINE Closed Beta</TribeNineRoot>
</PropertyGroup>
```

- Run `dotnet build` inside the zeromod directory

Install instructions
--------------------
- Install the x64 version of the [net6.0 runtime](https://dotnet.microsoft.com/en-us/download/dotnet/6.0#runtime-desktop-6.0.19) (don't need this if you have the sdk)
- Copy bin\Debug\net6.0\zeromod.dll to the game Mods directory