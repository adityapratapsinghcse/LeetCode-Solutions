class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        left_sum = nums[0]
        right_sum = 0
        total = 0
        
        count = 0
        n = len(nums)

        for i in range(n):
            total += nums[i]

        for i in range(n-1):
            right_sum = total - left_sum
            if(left_sum >= right_sum):
                count+=1
            left_sum += nums[i+1]
        return count