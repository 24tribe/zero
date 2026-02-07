from argparse import ArgumentParser
import json

def main():
    parser = ArgumentParser()
    parser.add_argument("dungeon_data_json")
    parser.add_argument("out_sql")
    args = parser.parse_args()

    with open(args.dungeon_data_json, "r", encoding="utf-8") as f:
        dungeon_data = json.load(f)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        write_dungeon_data_sql(dungeon_data, f)


def write_dungeon_data_sql(dungeon_data, f):
    xprint = lambda *args: print(*args, file=f)

    first = True

    xprint("INSERT INTO dungeonData (id, name, blocks, angle) VALUES")

    for dungeon_part in dungeon_data:
        id_ = dungeon_part["id"]
        name = dungeon_part["name"]
        blocks = json.dumps(dungeon_part["blocks"])
        angle = dungeon_part["angle"]

        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({id_}, '{name}', '{blocks}', {angle})")

    xprint(";")


if __name__ == "__main__":
    main()