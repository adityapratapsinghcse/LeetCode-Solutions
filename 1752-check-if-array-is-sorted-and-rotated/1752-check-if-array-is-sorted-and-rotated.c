bool check(int* nums, int numsSize) {
        int count = 0;
        int n = numsSize;
        for(int i=0 ; i< n ; i++){
            if(nums[i] > nums[(i+1) % n]){
                count++;
            }
        }
        if(count <=1){
            return true;
        }
        return false;
}