
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<long long> dp(n, 0);

        // One initial way to start
        dp[0] = 1;

        for (int i = 0; i < m; i++) {

            long long left = 0;

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {

                    // Mirror: exchange directions
                    swap(left, dp[j]);

                } 
                else {

                    // Empty cell: combine both directions
                    long long ways = (left + dp[j]) % MOD;

                    left = ways;
                    dp[j] = ways;
                }
            }
        }

        return (int)(dp[n - 1]);
    }
};
