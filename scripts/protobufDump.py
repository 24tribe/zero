from argparse import ArgumentParser
import re
import sys

def main():
    parser = ArgumentParser()
    parser.add_argument("cs_file")
    args = parser.parse_args()

    with open(args.cs_file, "r", encoding="utf-8") as f:
        code = f.read()

    class_ = parse_class(code)

    print(f"{class_["class_name"]}\n")

    for field in class_["fields"]:
        print(f"[ProtoMember({field["proto_field_num"]})]")
        print(f"{field["field_name"]}: {field["type"]}\n")

def parse_class(code):
    match = re.search(r"public sealed class ([^\s]+)", code)
    assert match
    class_name = match.group(1)

    fields = []

    for fieldName, protoFieldNum in re.findall(r"([^\s]+)FieldNumber = (\d+)", code):
        fieldNamePublic = fieldName
        fieldName = fieldName[:1].lower() + fieldName[1:]

        typeFmt = r"(?:[^\s]+ )*([^\s]+)"

        match = re.search(r"private " + typeFmt + f" {fieldName}_;", code)
        if not match:
            match = re.search(r"public " + typeFmt + f" {fieldNamePublic}\n", code)
            if not match:
                raise RuntimeError(f"couldn't find {fieldName} type!")

        type_ = match.group(1)

        fields.append({
            "proto_field_num": protoFieldNum,
            "field_name": fieldName,
            "type": type_
        })

    return {
        "class_name": class_name,
        "fields": fields
    }


if __name__ == "__main__":
    main()