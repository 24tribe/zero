from argparse import ArgumentParser
import json

def main():
    parser = ArgumentParser()
    parser.add_argument("online_logs_json")
    parser.add_argument("out_sql")
    args = parser.parse_args()

    with open(args.online_logs_json, "r", encoding="utf-8") as f:
        online_logs = json.load(f)

    first = next(filter(lambda x: x["uri"] == "/gacha/list", online_logs))

    res = first["res"]
    print(res.keys())

    with open(args.out_sql, "w", encoding="utf-8") as f:
        write_gachas(res["gachas"], f)
        write_gacha_rate_sets(res["gachaRateSets"], f)


def write_gacha_rate_sets(gacha_rate_sets, f):
    gacha_rate_sql = []
    gacha_cards_sql = []

    for gacha_rate_set in gacha_rate_sets:
        gacha_rate_set_id = gacha_rate_set["gachaRateSetId"]
        for gacha_rate in gacha_rate_set["rows"]:
            gacha_rate_id = gacha_rate["gachaRateId"]
            percent_rate = gacha_rate["percentRate"]

            vals = f"({gacha_rate_id}, {gacha_rate_set_id}, '{percent_rate}')"
            gacha_rate_sql.append(vals)

            cards = gacha_rate["cards"]
            for card in cards:
                card_type = card["cardType"]
                card_id = card["cardId"]
                is_attention = json.dumps(card.get("isAttention", False))
                is_selectable = json.dumps(card.get("isSelectable", False))
                gacha_card_id = card["gachaCardId"]
                vals = f"({card_type}, {card_id}, '{is_attention}', '{is_selectable}', {gacha_card_id}, {gacha_rate_id})"
                gacha_cards_sql.append(vals)

    xprint = lambda *args: print(*args, file=f)
    xprint("INSERT INTO gachaRates (gachaRateId, gachaRateSetId, percentRate) VALUES")
    xprint("\n,".join(gacha_rate_sql))
    xprint(";\n")
    xprint("INSERT INTO gachaCards (cardType, cardId, isAttention, isSelectable, gachaCardId, gachaRateId) VALUES")
    xprint("\n,".join(gacha_cards_sql))
    xprint(";")

def write_gachas(gachas, f):
    xprint = lambda *args: print(*args, file=f)

    xprint("""
INSERT INTO gachas
(gachaId, gachaCategoryId, guaranteedCount, isGuaranteedPickup, executionCount, isSelectable)
VALUES
""")

    allGachaButtonStates = []

    first = True
    for gacha in gachas:
        gachaId = gacha["gachaId"]
        allGachaButtonStates += gacha["gachaButtonStates"]
        gachaCategoryState = gacha["gachaCategoryState"]
        gachaCategoryId = gachaCategoryState["gachaCategoryId"]
        guaranteedCount = gachaCategoryState.get("guaranteedCount", 0)
        isGuaranteedPickup = json.dumps(gachaCategoryState.get("isGuaranteedPickup", False))
        executionCount = gachaCategoryState.get("executionCount", 0)
        isSelectable = json.dumps(gachaCategoryState.get("isSelectable", False))

        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({gachaId}, {gachaCategoryId}, {guaranteedCount}, '{isGuaranteedPickup}', {executionCount}, '{isSelectable}')")

    xprint(";")
    xprint("")
    xprint("INSERT INTO gachaButtonStates (gachaId, gachaButtonId, executionCount, lastExecutedAt) VALUES")

    first = True
    for gachaButtonState in allGachaButtonStates:
        gachaId = gachaButtonState["gachaId"]
        gachaButtonId = gachaButtonState["gachaButtonId"]
        executionCount = gachaButtonState.get("executionCount", 0)
        lastExecutedAt = gachaButtonState.get("lastExecutedAt", "")

        if first:
            first = False
        else:
            f.write(",")

        xprint(f"({gachaId}, {gachaButtonId}, {executionCount}, '{lastExecutedAt}')")

    xprint(";")

def pp(data):
    print(json.dumps(data, indent=2))


if __name__ == "__main__":
    main()