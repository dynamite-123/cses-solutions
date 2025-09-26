def solve(n: int):
    if n == 1:
        print(1)
        return
    if n < 4:
        print("NO SOLUTION")
        return

    nums = [i for i in range(1, n + 1)]
    ods = []
    evens = []
    for num in nums:
        if num % 2:
            ods.append(num)
        else:
            evens.append(num)
    res = evens + ods

    for i in res:
        print(i, end=" ")


num = int(input())
solve(num)
