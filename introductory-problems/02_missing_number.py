def solve(n, numbers):
    # sum of n numbers:
    s = n * (n + 1) // 2

    for num in numbers:
        s -= num
    return s


N = int(input())
arr = list(map(int, input().split()))
print(solve(N, arr))
