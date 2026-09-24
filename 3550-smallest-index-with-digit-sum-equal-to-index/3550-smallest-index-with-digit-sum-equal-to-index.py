class Solution:
    def digitCount(self,num):
        total = 0
        while(num > 0):
            digit = num % 10
            total += digit
            num = num // 10
        return total

    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if( i == self.digitCount(nums[i])):
                return i
        return -1