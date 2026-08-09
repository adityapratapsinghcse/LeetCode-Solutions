class Solution {
public:
    int n;
    vector<int> suffix;
    int dp[101][101];

    int solve(int i, int M, vector<int>& piles) {
        // If all remaining piles can be taken
        if (i + 2 * M >= n) {
            return suffix[i];
        }

        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        int ans = 0;

        // Try taking X piles
        for (int X = 1; X <= 2 * M; X++) {
            int nextM = max(M, X);

            // Total remaining - opponent's best score
            int current = suffix[i] - solve(i + X, nextM, piles);

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();

        // suffix[i] = total stones from i to n-1
        suffix.resize(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 1, piles);
    }
};