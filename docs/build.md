- Install [w64devkit-x64](https://github.com/skeeto/w64devkit/releases)
- Install git
- Delete patch.exe from w64devkit/bin to avoid old version complains from Meson
- Install [Python](https://www.python.org/downloads/windows/)
- Install [Meson](https://mesonbuild.com/Getting-meson.html)
- Install [Ninja](https://ninja-build.org/)
- Install [Nim](https://nim-lang.org/install.html)
- Install [dotnet](https://dotnet.microsoft.com/en-us/download/dotnet)
- Make sure [git-lfs](https://git-lfs.com/) is installed
- Clone and change to the source dir. Then setup the build dir and compile the project with Meson
```
git clone https://github.com/gyubid/zero
cd zero
meson setup build -Dwarning_level=3
meson compile -C build -j4
```

- Run cmd.exe as Administrator and make a symbolic link from
  build/bundlemod/bundlemod.dll to build/bundlemod.dll
```
cd /D D:\tribenine\zero\build
mklink bundlemod.dll bundlemod\bundlemod.dll
```

- In the build/config.ini change the sembaDbPath and goldbergPath to:
```
sembaDbPath=subprojects/semba/semba.db
goldbergPath=subprojects/goldberg_steam/steam_api64.dll
```

- To run the game use the loader (use parentheses to run the command in a subshell and
  to not change the working directory)
```
cd D:/tribenine/zero
(cd build && ./loader "E:\SteamLibrary\steamapps\common\TRIBENINE\tribenine.exe" libzero.dll)
```

- To recompile, run meson compile again (be careful that any change to semba.sql wipes the db
and any change to config.ini.dist clears the config.ini):
```
meson compile -C build -j4
```