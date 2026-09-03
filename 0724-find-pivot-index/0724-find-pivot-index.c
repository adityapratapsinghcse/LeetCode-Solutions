int pivotIndex(int* nums, int numsSize) {
        int total = 0;
        int n = numsSize;
        for(int i=0; i<n; i++){
            total+= nums[i];
        } 

        int left_sum = 0;
        int right_sum = 0;

        for(int i=0 ; i< n ; i++){
            right_sum = total - left_sum - nums[i];

            if(left_sum == right_sum){
                return i;
            }

            left_sum += nums[i];
        }
        return -1;
}