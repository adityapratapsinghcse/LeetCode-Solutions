class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        result = [0] * k
        dp = [0] * k
        
        for num in nums:
            new_dp = [0] * k
            num_mod = num % k
            
            # Start a new subarray containing only `num`
            new_dp[num_mod] += 1
            
            # Extend all subarrays ending at the previous position
            for r in range(k):
                if dp[r] > 0:
                    new_r = (r * num_mod) % k
                    new_dp[new_r] += dp[r]
            
            # Accumulate current counts into the total answer
            for r in range(k):
                result[r] += new_dp[r]
                
            dp = new_dp
            
        return result