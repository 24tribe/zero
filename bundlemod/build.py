from argparse import ArgumentParser
import os.path
import subprocess
import shutil

def main():
    parser = ArgumentParser()
    parser.add_argument("out_dll")
    parser.add_argument("project_path")
    args = parser.parse_args()

    out_dll = os.path.realpath(args.out_dll)
    os.chdir(args.project_path)
    subprocess.run(["dotnet", "publish"], check=True)
    shutil.copy("bin/Release/net9.0/win-x64/publish/bundlemod.dll", out_dll)

if __name__ == "__main__":
    main()