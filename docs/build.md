- Install [w64devkit-x64](https://github.com/skeeto/w64devkit/releases)
- Install git
- Install [Python](https://www.python.org/downloads/windows/)
- Install [Meson](https://mesonbuild.com/Getting-meson.html)
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

- Install it using install.py (be careful, it wipes the semba.db and the config.ini in the game directory, if you want to keep your config, add `--backup-config` to the arguments)

```
python install.py build D:/SteamLibrary/steamapps/common/TRIBENINE
```