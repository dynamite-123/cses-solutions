MOD = 10**9 + 7


def mod_pow(base, exp, mod):
    result = 1
    base = base % mod  # in case base >= mod

    while exp > 0:
        # If exp is odd, multiply result by base
        if exp % 2 == 1:
            result = (result * base) % mod
        # Square the base
        base = (base * base) % mod
        # Divide exp by 2
        exp //= 2
    return result


n = int(input().strip())
print(mod_pow(2, n, MOD))
