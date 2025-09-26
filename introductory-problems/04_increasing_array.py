def solve(nums: list) -> int:
    N = len(nums)
    res = 0
    for i in range(1, N):
        if nums[i] < nums[i - 1]:
            res += nums[i - 1] - nums[i]
            nums[i] = nums[i - 1]
    return res


n = int(input())
arr = list(map(int, input().split()))
print(solve(arr))
