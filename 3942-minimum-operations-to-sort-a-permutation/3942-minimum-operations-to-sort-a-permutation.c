
#include <limits.h>

int minOperations(int* nums, int numsSize) {
    int n = numsSize;
    int zero = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zero = i;
            break;
        }
    }

    int increasing = 1;
    int decreasing = 1;

    for (int i = 1; i < n; i++) {
        int prev = (zero + i - 1) % n;
        int curr = (zero + i) % n;

        if (nums[prev] > nums[curr]) {
            increasing = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        int prev = (zero - i + 1 + n) % n;
        int curr = (zero - i + n) % n;

        if (nums[prev] > nums[curr]) {
            decreasing = 0;
        }
    }

    int ans = INT_MAX;

    if (increasing) {
        if (zero < ans)
            ans = zero;

        if (n - zero + 2 < ans)
            ans = n - zero + 2;
    }

    if (decreasing) {
        if (zero + 2 < ans)
            ans = zero + 2;

        if (n - zero < ans)
            ans = n - zero;
    }

    return ans == INT_MAX ? -1 : ans;
}
