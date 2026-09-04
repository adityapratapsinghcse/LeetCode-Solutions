class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> prefix_max(nums.size());
        vector<int> suffix_min(nums.size());

        prefix_max[0] = nums[0];
        for(int i=1 ; i< nums.size() ;i++){
            prefix_max[i] = max(prefix_max[i-1],nums[i]);
        }

        suffix_min[nums.size()-1] = nums[nums.size()-1];
        for(int i=nums.size()-2; i >=0 ;i--){
            suffix_min[i] = min(suffix_min[i+1],nums[i]);
        }

        for(int i=0 ; i< nums.size() ; i++){
            if((prefix_max[i] - suffix_min[i]) <= k){
                return i;
            }
        }
        return -1;
    }
};