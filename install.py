from argparse import ArgumentParser
from pathlib import Path
import subprocess
import shutil

def main():
    parser = ArgumentParser()
    parser.add_argument("build_dir", type=Path)
    parser.add_argument("install_out", type=Path)
    parser.add_argument("--backup-config", action="store_true")
    args = parser.parse_args()

    config = None
    config_path = args.install_out/"config.ini"

    if args.backup_config and config_path.exists():
        with open(config_path, "r", encoding="utf-8") as f:
            config = f.read()

    run("meson", "install", "-C", str(args.build_dir), "--destdir", str(args.install_out.resolve()))

    if config is not None:
        with open(config_path, "w", encoding="utf-8") as f:
            f.write(config)

    for name in ("lib", "bin", "include", "share"):
        path = args.install_out/name
        print(f"Removing {path} ...")
        shutil.rmtree(path)

    for path in args.install_out.glob("*.a"):
        print(f"Removing {path} ...")
        path.unlink()


def run(*args):
    print(args)
    return subprocess.run(args, check=True)


if __name__ == "__main__":
    main()