int digitCount(int num){
    int sum = 0;
    while(num > 0){
        int digit = num % 10;
        sum += digit;
        num = num / 10;
    }
    return sum;
}

int smallestIndex(int* nums, int numsSize) {
    for(int i = 0 ; i< numsSize ; i++){
        if( i == digitCount(nums[i])){
            return i;
        }
    }
    return -1;   
}