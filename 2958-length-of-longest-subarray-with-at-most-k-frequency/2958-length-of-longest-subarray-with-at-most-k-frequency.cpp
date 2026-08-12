class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0 , j= 0;
        int max_size = 0;
        unordered_map<int,int> freq;
        while(j<nums.size()){
            freq[nums[j]] ++;

            while(freq[nums[j]] >k){
                freq[nums[i]] --;
                i++;
            }
            max_size = max(max_size,j-i+1);
            j++;
        }
        return max_size;
    }
};