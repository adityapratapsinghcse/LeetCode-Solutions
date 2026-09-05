class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> seen;

        seen[0] = 1;

        int running_sum = 0;
        int count = 0;

        for(int i =0 ; i< nums.size() ; i++){
            running_sum += nums[i];

            if(seen.count(running_sum - k)){
                count += seen[running_sum - k];
            }
            seen[running_sum]++;
        }
        return count;
    }
};