def solve(n):
    res = [""]
    tar = 2**n
    l = 1
    while True:
        if l == tar:
            return res
        res = res + res[::-1]
        l *= 2
        i, j = 0, l - 1
        while i < j:
            res[i] = "0" + res[i]
            res[j] = "1" + res[j]
            i += 1
            j -= 1
    return res


n = int(input())
arr = solve(n)
for s in arr:
    print(s)
