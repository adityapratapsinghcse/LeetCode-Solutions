class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        long long dp = 1;  // empty subsequence

        vector<long long> last(26, 0);

        for (char c : s) {
            int index = c - 'a';

            long long new_dp = (2 * dp - last[index] + MOD) % MOD;

            last[index] = dp;

            dp = new_dp;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};