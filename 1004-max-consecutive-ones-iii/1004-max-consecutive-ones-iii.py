class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        i = 0
        best = 0
        count = 0
        for j in range(len(nums)):
            if nums[j] == 0:
                count += 1
            while count > k:
                if nums[i] == 0:
                    count -= 1
                i += 1
            best = max(best, j - i + 1)
        return best
