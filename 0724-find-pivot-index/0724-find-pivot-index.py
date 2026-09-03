class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        total = 0
        n = len(nums)
        for i in range(len(nums)):
            total+= nums[i]

        left_sum = 0
        right_sum = 0

        for i in range(len(nums)):
            right_sum = total - left_sum - nums[i]
            if(left_sum == right_sum):
                return i
            left_sum += nums[i]
        return -1