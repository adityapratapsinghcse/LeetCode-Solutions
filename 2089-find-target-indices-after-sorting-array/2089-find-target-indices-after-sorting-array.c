int* targetIndices(int* nums, int numsSize, int target,
                   int* returnSize) {
    int smaller = 0, equal = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < target)
            smaller++;
        else if (nums[i] == target)
            equal++;
    }

    *returnSize = equal;
    int* ans = malloc(equal * sizeof(int));

    for (int i = 0; i < equal; i++) {
        ans[i] = smaller + i;
    }

    return ans;
}