int findNumbers(int* nums, int numsSize) {
    int ans=0;
    for(int i=0; i< numsSize ; i++){
        int count = 0;
        int num = nums[i];

        while(num > 0){
            int digit = num % 10;
            count++;
            num = num / 10;
        }
        if(count % 2 == 0){
            ans++;
        }
    }
    return ans;
}