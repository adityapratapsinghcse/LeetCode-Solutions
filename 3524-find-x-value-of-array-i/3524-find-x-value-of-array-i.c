/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* resultArray(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;
    
    long long* result = (long long*)calloc(k, sizeof(long long));
    long long* dp = (long long*)calloc(k, sizeof(long long));
    long long* new_dp = (long long*)calloc(k, sizeof(long long));

    for (int i = 0; i < numsSize; ++i) {
        memset(new_dp, 0, k * sizeof(long long));
        int num_mod = nums[i] % k;

        // Subarray of length 1 containing only nums[i]
        new_dp[num_mod] += 1;

        // Extend previous subarrays ending at index i - 1
        for (int r = 0; r < k; ++r) {
            if (dp[r] > 0) {
                int new_r = (int)((1LL * r * num_mod) % k);
                new_dp[new_r] += dp[r];
            }
        }

        // Accumulate counts into the global result and update dp
        for (int r = 0; r < k; ++r) {
            result[r] += new_dp[r];
            dp[r] = new_dp[r];
        }
    }

    free(dp);
    free(new_dp);

    return result;
}