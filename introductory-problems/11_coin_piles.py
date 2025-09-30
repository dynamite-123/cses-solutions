def solve(a, b):
    if a > b:
        a, b = b, a
    if b > 2 * a:
        return False
    m1 = a % 3
    m2 = b % 3
    if m1 > m2:
        m1, m2 = m2, m1
    if m1 == 0 and m2 == 0:
        return True
    elif m1 == 1 and m2 == 2:
        return True


t = int(input())
for _ in range(t):
    x, y = list(map(int, input().split()))
    if solve(x, y):
        print("YES")
    else:
        print("NO")
