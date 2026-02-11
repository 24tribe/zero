from argparse import ArgumentParser

SHIKOKU_X_ITEM_IDS = [
    50021,
    50022,
    50023,
]

STRANGE_X_ITEM_IDS = [
    50011,
    50012,
    50013,
]

X_SERVO_ITEM_IDS = [
    50051,
    50052,
    50053,
]

def get_enemy_rewards(enemy_ids, item_ids):
    result = []

    for enemy_id in enemy_ids:
        for item_id in item_ids:
            result.append((enemy_id, item_id))

    return result

def write_enemy_rewards_sql(enemy_rewards, f):
    xprint = lambda *args: print(*args, file=f)
    xprint("INSERT INTO enemyRewards VALUES")

    first = True
    for enemy_id, item_id in enemy_rewards:
        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({enemy_id}, {item_id})")

    xprint(";")

def main():
    parser = ArgumentParser()
    parser.add_argument("out_sql")
    args = parser.parse_args()

    shikoku_x_enemy_ids = [
        224303,
    ]

    strange_x_enemy_ids = [
        224105,
    ]

    x_servo_enemy_ids = [
        250106,
        250108,
    ]

    enemy_rewards = get_enemy_rewards(shikoku_x_enemy_ids, SHIKOKU_X_ITEM_IDS)
    enemy_rewards += get_enemy_rewards(strange_x_enemy_ids, STRANGE_X_ITEM_IDS)
    enemy_rewards += get_enemy_rewards(x_servo_enemy_ids, X_SERVO_ITEM_IDS)

    with open(args.out_sql, "w", encoding="utf-8") as f:
        write_enemy_rewards_sql(enemy_rewards, f)

if __name__ == "__main__":
    main()
