from typing import List

class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)

        # Extra 3 spaces to avoid index out of range
        dp = [0] * (n + 3)

        # Fill DP from back to front
        for i in range(n - 1, -1, -1):
            take = 0
            dp[i] = float('-inf')

            # Try taking 1, 2, or 3 stones
            for k in range(3):
                if i + k < n:
                    take += stoneValue[i + k]
                    dp[i] = max(dp[i], take - dp[i + k + 1])

        if dp[0] > 0:
            return "Alice"
        elif dp[0] < 0:
            return "Bob"
        else:
            return "Tie"