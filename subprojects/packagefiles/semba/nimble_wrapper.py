from argparse import ArgumentParser
import subprocess
import sys
import os
import os.path
import re
from pathlib import Path
from typing import Optional

OUTPUT_REGEX = re.compile(r"\s*-o:([^:]+)")

def main():
    nimble_args = sys.argv[1:]

    input_path = None

    for i, arg in enumerate(nimble_args):
        output = get_output_path(arg)
        if output is not None:
            nimble_args[i] = f"-o:{os.path.realpath(output)}"
        elif arg != "c" and not arg.startswith("-"):
            nimble_args[i] = os.path.realpath(arg)
            input_path = Path(arg).resolve()

    assert input_path

    nimble_dir = find_nimble_dir(input_path)

    assert nimble_dir

    os.chdir(nimble_dir)

    output = subprocess.check_output(['nimble'] + nimble_args).decode("utf-8")

    print(output)

    if "Success: Execution finished" in output:
        sys.exit(0)
    elif "Error:  Execution failed with exit code" in output:
        sys.exit(1)
    else:
        assert False


def get_output_path(arg) -> Optional[str]:
    match = OUTPUT_REGEX.search(arg)
    if match:
        return match.group(1)
    else:
        return None


def find_nimble_dir(path: Path) -> Optional[Path]:
    while path.parent != path:
        possible_nimble = list(path.parent.glob("*.nimble"))
        if len(possible_nimble) > 0:
            return path.parent
        path = path.parent


if __name__ == "__main__":
    main()