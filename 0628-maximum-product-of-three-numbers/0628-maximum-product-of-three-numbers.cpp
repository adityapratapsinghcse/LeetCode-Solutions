class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        // product max (positive): CASES
        //  +*+*+ a
        //  +*-*- b
        int a = nums[size - 1] * nums[size - 2] * nums[size - 3];
        int b = nums[0] * nums[1] * nums[size - 1];
        // if (nums[0]<0 && nums[1]<0){
        if (b > a) {
            return b;
        }
        return a;
    }
};