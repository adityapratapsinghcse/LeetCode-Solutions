class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        freq = [0] * (n + 1)

        for num in nums:
            freq[num] +=1
        
        for i in range(n+1):
            if(freq[i] == 0):
                return i