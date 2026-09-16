class Solution:
    MOD = 10**9 + 7

    def numberOfSets(self, n: int, k: int) -> int:
        N = n + k - 1
        R = 2 * k

        ans = 1

        for i in range(1, R + 1):
            ans = ans * (N - R + i) % self.MOD
            ans = ans * pow(i, self.MOD - 2, self.MOD) % self.MOD

        return ans