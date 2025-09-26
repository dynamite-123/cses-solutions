def solve(n: int) -> list:
    res = []
    res.append(n)
    while n != 1:

        if n % 2 == 0:
            # even number
            n = n // 2
        else:
            n = n * 3 + 1
        res.append(n)

    return res


num = int(input())
arr = solve(num)

for n in arr:
    print(n, end=" ")
