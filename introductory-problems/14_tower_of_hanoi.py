import sys
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from heapq import heapify, heappop, heappush
from math import ceil, floor, gcd, lcm, sqrt

input = sys.stdin.readline


def inp():
    return int(input())


def inlt():
    return list(map(int, input().split()))


def insr():
    return list(input().strip())


def invr():
    return map(int, input().split())


def ins():
    return input().strip()


def solve(n):
    res = []

    def toh(x, s, d, t):
        if x == 0:
            return 0

        toh(x - 1, s, t, d)
        res.append([s, d])
        toh(x - 1, t, d, s)

    toh(n, 1, 3, 2)

    return res


if __name__ == "__main__":
    innum = inp()
    ans = solve(innum)
    print(len(ans))

    for x, y in ans:
        print(f"{x} {y}")
