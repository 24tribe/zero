from argparse import ArgumentParser
import re
import sys

def main():
    parser = ArgumentParser()
    parser.add_argument("cs_file")
    args = parser.parse_args()

    with open(args.cs_file, "r", encoding="utf-8") as f:
        code = f.read()

    match = re.search(r"public sealed class ([^\s]+)", code)
    assert match
    class_name = match.group(1)

    print(f"{class_name}\n")

    for fieldName, protoFieldNum in re.findall(r"([^\s]+)FieldNumber = (\d+)", code):
        fieldName = fieldName[:1].lower() + fieldName[1:]
        print(f"[ProtoMember({protoFieldNum})]")

        match = re.search(r"private (?:[^\s]+ )*([^\s]+) " + f"{fieldName}_;", code)
        assert match
        type_ = match.group(1)

        print(f"{fieldName}: {type_}\n")


if __name__ == "__main__":
    main()