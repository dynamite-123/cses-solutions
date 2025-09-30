def solve(n):
    if n == 1:
        return False
    s1, s2 = set(), set()
    for i in range(1, n + 1):
        s2.add(i)

    tar = (n * (n + 1)) // 4
    s = 0
    i, j = 1, n

    while s < tar:
        s += j
        s1.add(j)
        if s == tar:
            break
        j -= 1
        s += i
        s1.add(i)
        if s == tar:
            break
        i += 1
    if s == tar:
        s2 = s2 - s1
        return [s1, s2]
    else:
        return False


n = int(input())
res = solve(n)
if res != False:
    s1, s2 = res
    print("YES")
    # print(s1)
    # print(s2)
    print(len(s1))
    for i in s1:
        print(i, end=" ")
    print()
    print(len(s2))
    for i in s2:
        print(i, end=" ")
    print()
else:
    print("NO")
