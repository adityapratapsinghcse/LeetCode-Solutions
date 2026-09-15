class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)
        dp = [0] * (n + 1)
        
        for i in range(1, n + 1):
            # Base case: don't form a palindrome ending here
            dp[i] = dp[i - 1]
            
            # Check if we can form a palindrome of exactly length k
            if i >= k:
                sub = s[i - k : i]
                if sub == sub[::-1]:
                    dp[i] = max(dp[i], dp[i - k] + 1)
                    
            # Check if we can form a palindrome of exactly length k + 1
            if i >= k + 1:
                sub = s[i - k - 1 : i]
                if sub == sub[::-1]:
                    dp[i] = max(dp[i], dp[i - k - 1] + 1)
                    
        return dp[n]