def solve(s: str) -> int:
    N = len(s)
    count = 1
    res = 1
    for i in range(1, N):  # 0 -> N-1
        if s[i - 1] == s[i]:  # prev element is the same
            count += 1
            res = max(res, count)
        else:  # prev element is different
            count = 1
    return res


input_string = input()
print(solve(input_string))
