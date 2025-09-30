def solve(n):
    tot = n**2 * (n**2 - 1) // 2
    att = 4 * (n - 1) * (n - 2)
    return tot - att


N = int(input())
for i in range(1, N + 1):
    print(solve(i))
