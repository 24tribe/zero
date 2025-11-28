- Install [w64devkit](https://github.com/skeeto/w64devkit)
- Install git
- Install python
- Install [Meson 1.7.0](https://github.com/mesonbuild/meson/releases/tag/1.7.0)
  (newer versions aren't compatible with w64devkit's busybox)
- Install [Ninja](https://ninja-build.org/)
- Install [Nim](https://nim-lang.org/install.html)
- Clone and change to the source dir. Then setup the build dir and compile the project with Meson
```
git clone https://github.com/gyubid/zero
cd zero
meson setup build -Dwarning_level=3
meson compile -C build
```