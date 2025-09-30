def solve(n):
    dp = {}

    def fives(n):
        # print(n)
        if n in dp:
            return dp[n]
        if n < 5:
            dp[n] = 0
            return 0
        if n % 5 != 0:
            dp[n] = 0
            return 0
        else:
            dp[n] = 1 + fives(n // 5)
            return dp[n]

    res = 0
    for i in range(1, n + 1):
        res += fives(i)
    return res


n = int(input())
print(solve(n))
