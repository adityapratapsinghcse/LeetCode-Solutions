#include <stdio.h>

int minOperations(int* nums, int numsSize, int x) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }

    int target = total - x;

    // Edge cases
    if (target < 0) {
        return -1;
    }
    if (target == 0) {
        return numsSize;
    }

    int left = 0;
    int sum = 0;
    int maxLen = -1;

    for (int right = 0; right < numsSize; right++) {
        sum += nums[right];

        // Shrink window if current sum exceeds target
        while (left <= right && sum > target) {
            sum -= nums[left];
            left++;
        }

        if (sum == target) {
            int currentLen = right - left + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        }
    }

    return (maxLen == -1) ? -1 : (numsSize - maxLen);
}