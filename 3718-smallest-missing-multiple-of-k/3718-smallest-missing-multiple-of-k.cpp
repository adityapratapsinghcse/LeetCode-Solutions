class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(),nums.end());

        int mutltiple = k;

        while(set.count(mutltiple)){
            mutltiple += k;
        }
        return mutltiple;
    }
};