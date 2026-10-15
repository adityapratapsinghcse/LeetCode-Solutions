int sumCounts(int* nums, int numsSize) {
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        int* distinct = (int*)malloc(numsSize * sizeof(int));
        int count = 0;

        for (int j = i; j < numsSize; j++) {
            int found = 0;

            for (int k = 0; k < count; k++) {
                if (distinct[k] == nums[j]) {
                    found = 1;
                    break;
                }
            }

            if (!found) {
                distinct[count++] = nums[j];
            }

            ans += count * count;
        }

        free(distinct);
    }

    return ans;
}