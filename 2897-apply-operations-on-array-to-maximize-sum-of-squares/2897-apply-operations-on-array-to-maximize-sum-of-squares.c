
#include <stdlib.h>

int maxSum(int* nums, int numsSize, int k) {
    const long long MOD = 1000000007LL;
    int bits[32] = {0};

    // Count set bits at each position
    for (int i = 0; i < numsSize; i++) {
        for (int b = 0; b < 32; b++) {
            if ((unsigned int)nums[i] & (1U << b)) {
                bits[b]++;
            }
        }
    }

    long long ans = 0;

    // Construct k maximum numbers
    for (int i = 0; i < k; i++) {
        long long num = 0;

        for (int b = 0; b < 32; b++) {
            if (bits[b] > 0) {
                num |= (1LL << b);
                bits[b]--;
            }
        }

        ans = (ans + num * num) % MOD;
    }

    return (int)ans;
}
