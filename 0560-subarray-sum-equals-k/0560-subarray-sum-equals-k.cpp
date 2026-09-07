class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;

        map[0]=1;

        int prefix_sum= 0;
        int count = 0;
        for(int i=0 ; i< nums.size() ; i++){
            prefix_sum += nums[i];
            int target = prefix_sum - k;
            if(map.find(target)!= map.end()){
                count+=map[target];
            }
            map[prefix_sum]++;
        }
        return count;
    }
};