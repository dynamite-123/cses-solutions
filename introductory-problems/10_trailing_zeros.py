def solve(n):
    res = 0
    div = 5
    while div <= n:
        res += n // div
        div = div*5
    return res


n = int(input())
print(solve(n))
