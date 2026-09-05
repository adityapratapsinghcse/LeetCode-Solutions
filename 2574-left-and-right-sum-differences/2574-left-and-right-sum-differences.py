class Solution:
    def leftRightDifference(self, nums: List[int]) -> List[int]:
        n = len(nums)
        total_sum = 0
        
        for num in nums:
            total_sum += num
            
        answer = [0] * len(nums)

        leftsum=0
        for i in range(len(nums)):
            rightsum = total_sum - leftsum - nums[i]
            answer[i] = abs(leftsum - rightsum)
            leftsum += nums[i]
        return answer