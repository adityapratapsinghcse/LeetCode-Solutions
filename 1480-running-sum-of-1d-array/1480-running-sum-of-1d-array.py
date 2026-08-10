class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        ans = []
        run_sum = 0
        for i in nums:
            run_sum += i
            ans.append(run_sum)
        return ans