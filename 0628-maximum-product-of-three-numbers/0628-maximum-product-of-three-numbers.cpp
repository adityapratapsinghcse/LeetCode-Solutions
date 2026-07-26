class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int Way1 = nums[n-1] * nums[n-2] * nums[n-3];
        int Way2 = nums[0] * nums[1] * nums[n-1];

        return max(Way1,Way2);
    }
};