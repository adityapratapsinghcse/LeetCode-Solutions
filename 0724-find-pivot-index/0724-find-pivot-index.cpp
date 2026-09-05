class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix_sum(nums.size());
        vector<int> suffix_sum(nums.size());

        int n = nums.size();
        prefix_sum[0] = nums[0];
        for(int i=1 ; i< n ; i++){
            prefix_sum[i] = prefix_sum[i-1] + nums[i];
        }
        
        suffix_sum[n-1] = nums[n-1];
        for(int i=n-2 ; i >=0 ; i--){
            suffix_sum[i] = suffix_sum[i+1] + nums[i];
        }

        for(int i = 0; i< n ; i++){
            if(prefix_sum[i] == suffix_sum[i]){
                return i;
            }
        }
        return -1;
    }
};