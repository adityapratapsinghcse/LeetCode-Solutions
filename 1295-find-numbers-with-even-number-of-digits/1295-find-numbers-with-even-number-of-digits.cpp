class Solution {
    bool findDigit(int num){
        int count = 0;
        while(num > 0){
            int digit = num % 10;
            num = num / 10;
            count++;
        }
        if(count % 2 == 0){
            return true;
        }
        return false;
    }
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int i=0 ; i< nums.size() ; i++){
            int ans = findDigit(nums[i]);
            if(ans == true){
                count++;
            }
        }
        return count;
    }
};