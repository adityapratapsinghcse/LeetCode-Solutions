/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
        int n = numsSize;
        *returnSize = numsSize;

        int total_sum = 0;
        
        for(int i=0 ; i < n ; i++){
            total_sum += nums[i];
        }
        
        int* answer = (int*)malloc(numsSize * sizeof(int));
        
        int leftsum=0;
        
        for(int i =0 ;i <n ; i++){
            int rightsum = total_sum - leftsum - nums[i];
            answer[i] = abs(leftsum - rightsum);
            leftsum += nums[i];
        }
        return answer;
}