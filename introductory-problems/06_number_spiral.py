import sys
from bisect import bisect_left, bisect_right
from collections import Counter, defaultdict, deque
from heapq import heapify, heappop, heappush

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


def solve(x, y):
    res = None
    start = None
    dif = None
    if x > y:
        dif = x - y
        if x % 2 == 0:
            start = x**2 + 1
            res = start - y
        else:
            x -= 1
            start = x**2
            res = start + y
    elif x <= y:
        dif = x
        if y % 2 == 0:
            y -= 1
            start = y**2
            res = start + x
        else:
            start = y**2 + 1
            res = start - x
    return res


if __name__ == "__main__":
    t = inp()
    for _ in range(t):
        i, j = inlt()
        print(solve(i, j))
