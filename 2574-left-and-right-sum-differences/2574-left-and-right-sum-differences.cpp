class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for(int num: nums){
            total_sum += num;
        }
        vector<int> answer(n);
        int leftsum=0;
        for(int i =0 ;i <n ; i++){
            int rightsum = total_sum - leftsum - nums[i];
            answer[i] = abs(leftsum - rightsum);
            leftsum += nums[i];
        }
        return answer;
    }
};