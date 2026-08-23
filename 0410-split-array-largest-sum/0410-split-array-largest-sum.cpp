class Solution {
    bool is_possible(vector<int> nums, int mid ,int k){
        int sum =0; 
        int n=1;
        for(int i=0 ; i< nums.size() ; i++){
            if(nums[i] + sum <= mid){
                sum += nums[i];
            }else{
                sum = nums[i];
                n+=1;
            }

            if(n > k) return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int total=0;
        int maxi = nums[0];

        for(int i =0 ; i< nums.size() ; i++){
            total += nums[i];
            maxi = max(maxi , nums[i]);
        }

        int start = maxi;
        int end = total;
        int ans =-1;

        while(start <= end){
            int mid= (start+end) /2;

            if(is_possible(nums,mid,k)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};