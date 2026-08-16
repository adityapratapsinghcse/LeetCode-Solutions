/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
        int i = 0;
        int j = numbersSize - 1;
        int curr_sum = 0;
        int* ans = (int*)malloc(2* sizeof(int));

        while (i <= j) {
            curr_sum = numbers[i] + numbers[j];

            if (curr_sum == target) {
                break;
            }
            if (curr_sum < target) {
                i++;
            } else {
                j--;
            }
        }
        ans[0] = i+1;
        ans[1] = j+1;
        *returnSize = 2;
        return ans;
}