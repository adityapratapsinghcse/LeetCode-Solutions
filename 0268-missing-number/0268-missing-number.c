int missingNumber(int* nums, int numsSize) {
    int n = numsSize;
    int num=0;
    int freq[n+1];

        for(int i=0 ; i<= n ; i++){
            freq[i] =0;
        }
        for(int i=0 ; i<n ;i++){
            freq[nums[i]]++; 
        }
        for(int i=0 ; i<=n ; i++){
            if(freq[i] == 0){
                num = i;
                return i;
            }
        }
        return -1;
}