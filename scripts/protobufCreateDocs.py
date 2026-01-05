from argparse import ArgumentParser
from pathlib import Path

from protobufDump import parse_class

html_header = """
<!DOCTYPE html>
<head>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Roboto:ital,wght@0,100..900;1,100..900&display=swap" rel="stylesheet">
    <style>
        body {
            font-family: "Roboto";
            background: #222222;
            color: #f8f8f8;
            margin: 40px auto;
            max-width: 650px;
        }

        code {
            border-radius: 3px;
            background: #333333;
            box-shadow: inset 0 0 1px 1px #eee;
            padding: 4px;
        }

        a {
            color: #f8f8f8;
            text-decoration: none;
        }
    </style>
</head>
<body>

<h1>Protobuf Objects</h1>
"""

html_footer = """
</body>
</html>
"""

def main():
    parser = ArgumentParser()
    parser.add_argument("neon_model_api_rpc_src_dir", type=Path)
    parser.add_argument("neon_model_api_model_src_dir", type=Path)
    parser.add_argument("out_html")
    args = parser.parse_args()

    rpc_classes = parse_classes(args.neon_model_api_rpc_src_dir)
    rpc_htmls = list(map(class_to_html, rpc_classes))

    model_classes = parse_classes(args.neon_model_api_model_src_dir)
    model_htmls = list(map(class_to_html, model_classes))

    html = (
        html_header
        + "\n<hr>\n".join(rpc_htmls)
        + "\n<hr>\n".join(model_htmls)
        + html_footer
    )

    with open(args.out_html, "w", encoding="utf-8") as f:
        f.write(html)

def class_to_html(class_):
    html = [f"""
<h3 id="{class_["class_name"]}"><a href="#{class_["class_name"]}">{class_["class_name"]}</a></h3>
"""]

    for field in class_["fields"]:
        is_optional = field["type"].endswith("?")
        if is_optional:
            type_ = field["type"][:-1]
        else:
            type_ = field["type"]

        trim_len = len("RepeatedField<")
        is_repeated_field = field["type"].startswith("RepeatedField<")
        if is_repeated_field:
            type_ = type_[trim_len:-1]

        type_html = f"""<a href="#{type_}">{type_}</a>"""

        if is_repeated_field:
            type_html = f"RepeatedField&lt;{type_html}&gt;"

        if is_optional:
            type_html = f"{type_html}?"

        html.append(f"""
<p><b>{field["field_name"]}: </b><code>{type_html}</code></p>
""")

    return "\n".join(html) + "\n"

def parse_classes(dir_):
    classes = []

    for path in dir_.glob("*.cs"):
        if "Reflection.cs" in str(path):
            continue

        with open(path, "r", encoding="utf-8") as f:
            content = f.read()

        if not "IMessage<" in content:
            continue

        try:
            classes.append(parse_class(content))
        except:
            print(f"{path}")
            raise

    return classes

if __name__ == "__main__":
    main()