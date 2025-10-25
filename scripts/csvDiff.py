from argparse import ArgumentParser

from listUnhookedFuncs import read_hooks

def main():
    parser = ArgumentParser()
    parser.add_argument("first_csv")
    parser.add_argument("second_csv")
    parser.add_argument("out_csv")
    args = parser.parse_args()

    first = read_hooks(args.first_csv)
    second = read_hooks(args.second_csv)

    res = {}

    first_s = set(first)
    second_s = set(second)

    diff_s = first_s.symmetric_difference(second_s)
    diff = {k: (first[k] if k in first else second[k]) for k in diff_s}

    with open(args.out_csv, "w", encoding="utf-8") as f:
        for k in diff:
            print(f"{k},{diff[k][0]},{diff[k][1]}", file=f)

if __name__ == "__main__":
    main()