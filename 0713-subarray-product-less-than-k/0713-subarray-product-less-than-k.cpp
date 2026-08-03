class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i = 0, j = 0, count = 0;
        long long product= 1;
        while(j<nums.size()){
            product *= nums[j];
            while(product >= k && i<= j){
                product /= nums[i];
                i++;
            }
            count += (j-i+1);
            j++;
        }
        return count;
    }
};