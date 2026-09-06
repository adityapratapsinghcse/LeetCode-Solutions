int waysToSplitArray(int* nums, int numsSize) {
    long long left_sum = nums[0];
    long long right_sum = 0;
    long long total = 0;

    int count = 0;
    int n = numsSize;

    for (int i = 0; i < n; i++) {
        total += nums[i];
    }

    for (int i = 0; i < n - 1; i++) {
        right_sum = total - left_sum;
        if (left_sum >= right_sum) {
            count += 1;
        }
        left_sum += nums[i + 1];
    }
    return count;
}