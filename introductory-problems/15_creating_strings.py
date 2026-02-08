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


def solve(st):
    N = len(st)
    chars = list(st)

    perms = [[chars[0]]]
    for i in range(1, N):
        new_perms = []
        for c in perms:
            n = len(c)
            for _ in range(n + 1):
                cur = c.copy()
                cur.insert(_, chars[i])
                new_perms.append(cur)
        perms = new_perms.copy()

    vis = set()
    res = []
    for p in perms:
        cur = "".join(p)
        if cur not in vis:
            res.append(cur)
            vis.add(cur)
    print(len(res))
    for c in sorted(res):
        print(c)


if __name__ == "__main__":
    instring = insr()
    solve(instring)
