"""
This script generates the sql needed to initialize the tipRelease table.
The tipRelease table is used to save the changed area objects that should be
returned by the server after a call to the "/tip/release" endpoint.
"""

from argparse import ArgumentParser
import json

def main():
    parser = ArgumentParser()
    parser.add_argument("online_logs_json")
    parser.add_argument("out_sql")
    args = parser.parse_args()

    with open(args.online_logs_json, "r", encoding="utf-8") as f:
        online_logs = json.load(f)

    tip_releases = filter(lambda x: x["uri"] == "/tip/release", online_logs)
    tip_releases = without_duplicates(tip_releases)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        write_tip_releases_sql(tip_releases, f)


def without_duplicates(tip_releases):
    tip_ids = set()
    result = []

    for tip_release in tip_releases:
        tip_id = tip_release["req"]["tipIds"][0]
        if tip_id not in tip_ids:
            result.append(tip_release)
            tip_ids.add(tip_id)

    return result


def write_tip_releases_sql(tip_releases, f):
    xprint = lambda *args: print(*args, file=f)
    xprint("""
INSERT INTO tipRelease (tipId, areaObjectId, newAreaPointId, newAreaObjectBehaviorId, newAction)
VALUES
""")

    first = True

    for tip_release in tip_releases:
        tip_id = tip_release["req"]["tipIds"][0]
        area_objects = tip_release["res"].get("areaObjects", [])

        for area_object in area_objects:
            if first:
                first = False
            else:
                f.write(", ")

            area_object_id = area_object["areaObjectId"]
            new_area_point_id = area_object["areaPointId"]
            new_area_object_behavior_id = area_object["areaObjectBehaviorId"]
            new_action = f"'{json.dumps(area_object["action"])}'"

            row = map(str, (
                tip_id, area_object_id, new_area_point_id, new_area_object_behavior_id, new_action
            ))

            parens_content = ", ".join(row)
            xprint(f"({parens_content})")

    xprint(";")


if __name__ == "__main__":
    main()