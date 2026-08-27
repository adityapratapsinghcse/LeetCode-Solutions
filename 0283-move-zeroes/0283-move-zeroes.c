void moveZeroes(int* nums, int numsSize) {
    int slow = 0;
    for (int fast = 0; fast < numsSize; fast++) {
        if (nums[fast] != 0) {
            int temp = nums[slow];
            nums[slow] = nums[fast];
            nums[fast] = temp;
            slow++;
        }
    }
}