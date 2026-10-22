
class Solution:
    def minOperations(self, nums: list[int]) -> int:
        n = len(nums)
        zero = nums.index(0)

        increasing = True
        decreasing = True

        for i in range(1, n):
            prev = (zero + i - 1) % n
            curr = (zero + i) % n

            if nums[prev] > nums[curr]:
                increasing = False

        for i in range(1, n):
            prev = (zero - i + 1 + n) % n
            curr = (zero - i + n) % n

            if nums[prev] > nums[curr]:
                decreasing = False

        ans = float('inf')

        if increasing:
            ans = min(ans, zero)
            ans = min(ans, n - zero + 2)

        if decreasing:
            ans = min(ans, zero + 2)
            ans = min(ans, n - zero)

        return -1 if ans == float('inf') else ans
