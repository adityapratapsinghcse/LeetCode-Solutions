/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
        int* answer = (int*)malloc(numsSize * sizeof(int));
        int* prefix_prod = (int*)malloc(numsSize * sizeof(int));
        int* suffix_prod = (int*)malloc(numsSize * sizeof(int));
        
        *returnSize = numsSize;

        prefix_prod[0] = 1;
        for(int i=1 ; i< numsSize ;i++){
            prefix_prod[i] = prefix_prod[i-1] * nums[i-1];
        }

        
        suffix_prod[numsSize-1] = 1;
        for(int i=numsSize-2; i >= 0  ;i--){
            suffix_prod[i] = suffix_prod[i+1] * nums[i+1];
        }

        for(int i=0 ; i< numsSize ; i++){
            answer[i] = prefix_prod[i] * suffix_prod[i];
        }

        free(prefix_prod);
        free(suffix_prod);
        return answer;
}