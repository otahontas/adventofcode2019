import math

recipes = open("inputs/d14.txt").read().splitlines()

def get_ore_count(fuel_needed):
    chems = {}
    for recipe in recipes:
        ings_str, output_str = recipe.split(" => ")
        output_amount, output = output_str.split(" ")
        ings = [
            (y, int(x))
            for x, y in list(
                map(
                    lambda x: tuple(x), [ing.split(" ") for ing in ings_str.split(", ")]
                )
            )
        ]
        chems[output] = {
            "amount": int(output_amount),
            "ings": ings,
            "needed": 0,
            "created": 0,
        }

    chems["FUEL"]["needed"] = fuel_needed
    chems["ORE"] = {"amount": 1, "ings": [], "needed": 0, "created": 0}

    while True:
        should_break = True
        for chem, d in chems.items():
            if d["created"] >= d["needed"]:
                continue

            should_break = False
            created = math.ceil((d["needed"] - d["created"]) / d["amount"])
            chems[chem]["created"] += created * d["amount"]

            for chem, amount in d["ings"]:
                chems[chem]["needed"] += amount * created
            break
        if should_break:
            return chems["ORE"]["created"]

def first():
    ans = get_ore_count(1)
    print(ans)
    return ans


def second(start):
    ores = 1000000000000

    a = ores // start
    b = 2 * a

    while b > a + 1:
        m = (a + b) // 2
        c = get_ore_count(m)
        if c <= ores:
            a = m
        else:
            b = m

    print(a)

ans = first()
second(ans)
