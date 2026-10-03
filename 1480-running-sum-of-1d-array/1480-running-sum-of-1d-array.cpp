class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        vector<int> result;
        for(int i=0 ; i<n ; i++){
            sum += nums[i];
            result.push_back(sum);
        }
        return result;
    }
};