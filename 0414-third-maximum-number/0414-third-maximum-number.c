int thirdMax(int* nums, int numsSize) {
    long long max1 = LLONG_MIN;
    long long max2 = LLONG_MIN;
    long long max3 = LLONG_MIN;

    for(int x=0; x< numsSize; x++){

            if(nums[x] == max1 || nums[x] == max2 || nums[x] == max3){
                continue;
            }

            if(nums[x] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[x];
            }
            else if(nums[x] > max2){
                max3 = max2;
                max2 = nums[x];
            }
            else if(nums[x] > max3){
                max3 = nums[x];
            }
        }
        if(max3 == LLONG_MIN){
            return max1;
        }
        return max3;
}