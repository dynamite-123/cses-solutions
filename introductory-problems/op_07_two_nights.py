import sys

input = sys.stdin.readline


def inp():
    return int(input())


# DP APPROACH
def solve(N):
    res = []
    dp = {}
    dir = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]

    def check(n, i, j):
        res = 0
        for di, dj in dir:
            ni, nj = i + di, j + dj
            if 0 <= ni < n - 1 and 0 <= nj < n - 1:
                res += 1
        return res

    def ways(n):  # number of ways where two knights attack each other
        if n == 1:
            dp[1] = 0
            return 0
        if n == 2:
            dp[2] = 0
            return 0
        cur = 0
        for i in range(n - 1):
            cur += check(n, n - 1, i)
            cur += check(n, i, n - 1)
        cur += check(n, n - 1, n - 1)
        dp[n] = dp[n - 1] + cur + 2
        return dp[n]

    for i in range(1, N + 1):
        attacks = ways(i)
        total = i * i * (i * i - 1) // 2
        res.append(total - attacks)

    return res


if __name__ == "__main__":
    k = inp()
    arr = solve(k)
    for _ in arr:
        print(_)
