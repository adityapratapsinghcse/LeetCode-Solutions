int longestOnes(int* nums, int numsSize, int k) {
    int i = 0;
    int best = 0;
    int count = 0;

    for (int j = 0; j < numsSize; j++) {
        if (nums[j] == 0) {
            count++;
        }
        while (count > k) {
            if (nums[i] == 0) {
                count--;
            }
            i++;
        }
        if (best < (j - i + 1)) {
            best = j - i + 1;
        }
    }
    return best;
}
