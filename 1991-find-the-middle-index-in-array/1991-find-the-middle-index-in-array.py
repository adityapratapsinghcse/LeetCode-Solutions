class Solution:
    def findMiddleIndex(self, nums: List[int]) -> int:
        prefix_sum = [0] * len(nums)
        suffix_sum = [0] * len(nums)
        n = len(nums)
        prefix_sum[0] = nums[0]
        for i in range(1,n):
            prefix_sum[i] = prefix_sum[i - 1] + nums[i]

        suffix_sum[n - 1] = nums[n - 1]
        for i in range(n-2,-1,-1):
            suffix_sum[i] = suffix_sum[i + 1] + nums[i]

        for i in range(len(nums)):
            if (prefix_sum[i] == suffix_sum[i]) :
                return i
        return -1