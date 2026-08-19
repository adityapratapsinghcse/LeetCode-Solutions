class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_size =INT_MAX , sum=0 , left=0;

        for(int right = 0; right< nums.size() ; right++){
            sum += nums[right];
            while(sum >= target){
                min_size = min(min_size,right-left+1);
                sum -= nums[left];
                left++;
            }
        }
        if(min_size == INT_MAX) {return 0;}
        
        return min_size;
    }
};