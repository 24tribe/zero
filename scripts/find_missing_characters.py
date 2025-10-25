from argparse import ArgumentParser
import sqlite3

def main():
    parser = ArgumentParser()
    parser.add_argument("semba_db")
    args = parser.parse_args()

    con = sqlite3.connect(args.semba_db)

    cur = con.cursor()

    res = cur.execute("SELECT characterId FROM characters")

    character_ids = rows_to_int_list(res.fetchall())

    print("character_ids: ", character_ids)

    res = cur.execute("SELECT characterCostumeId FROM characterCostumes")

    costume_ids = rows_to_int_list(res.fetchall())

    print("costume_ids: ", costume_ids)

    character_ids_from_costumes = set()

    for costume_id in costume_ids:
        character_ids_from_costumes.add(int(costume_id/1000) * 100 + 1)

    character_ids_from_costumes = list(character_ids_from_costumes)
    character_ids_from_costumes.sort()

    print("character_ids_from_costumes: ", character_ids_from_costumes)

    new_character_ids = list(set(character_ids_from_costumes) - set(character_ids))
    new_character_ids.sort()

    print("new_character_ids: ", new_character_ids)

    

def rows_to_int_list(rows):
    return list(map(lambda x: int(x[0]), rows))     

if __name__ == "__main__":
    main()