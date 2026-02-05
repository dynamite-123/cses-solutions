def solve(s):
    N = len(s)
    freq = {}
    for c in s:
        if c not in freq:
            freq[c] = 1
        else:
            freq[c] += 1
    flag = False
    odd = None
    res = [None] * N
    i, j = 0, N - 1
    for k, v in freq.items():
        if v % 2:
            odd = k
            if not flag:
                flag = True
            else:
                print("NO SOLUTION")
                return
        else:
            c = v // 2
            for _ in range(c):
                res[i] = k
                res[j] = k
                i += 1
                j -= 1
    while i <= j and odd != None:
        res[i] = res[j] = odd
        i += 1
        j -= 1
    pal = "".join(res)
    print(pal)
    return


si = input()
solve(si)
