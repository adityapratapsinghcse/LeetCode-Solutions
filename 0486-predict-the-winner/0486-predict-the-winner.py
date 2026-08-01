class Solution:
    def predictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        # dp[i][j] = best score difference (current player - other player)
        # achievable using nums[i..j]
        dp = [[0] * n for _ in range(n)]
        
        # base case: single element subarrays
        for i in range(n):
            dp[i][i] = nums[i]
        
        # fill by increasing subarray length
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                dp[i][j] = max(
                    nums[i] - dp[i + 1][j],
                    nums[j] - dp[i][j - 1]
                )
        
        return dp[0][n - 1] >= 0