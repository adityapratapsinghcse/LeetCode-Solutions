class Solution {
    int digitCount(int num){
        int sum = 0;
        while(num > 0){
            int digit = num % 10;
            sum += digit;
            num = num / 10;
        }
        return sum;
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0 ; i< nums.size() ; i++){
            if( i == digitCount(nums[i])){
                return i;
            }
        }
        return -1;
    }
};