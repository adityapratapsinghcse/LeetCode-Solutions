class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i=0 ,j=0;
        long long count=0 , sum=0;

        while(j<nums.size()){
            sum += nums[j];
            long long score = sum * (j-i+1);
            while(score >=k && i<= j){
                sum-=nums[i];
                i++;
                score = sum * (j-i+1);
            }
            count += (j-i+1);
            j++;
        }
        return count;
    }
};