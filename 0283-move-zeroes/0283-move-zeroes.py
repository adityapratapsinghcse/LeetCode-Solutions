class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slow = 0
        for fast in range(len(nums)):
            if(nums[fast] != 0):
                temp = nums[fast]
                nums[fast] = nums[slow]
                nums[slow] = temp
                slow+=1