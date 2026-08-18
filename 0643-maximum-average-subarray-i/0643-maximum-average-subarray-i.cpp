class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg_best = 0;
        double sum=0;
        for(int i=0 ; i< k ;i++){
            sum += nums[i];
        }
        avg_best = sum / k;

        for(int right = k ; right < nums.size() ; right++){
            sum += nums[right];
            sum -= nums[right - k];
            double curr_avg = sum / k;
            avg_best = max(curr_avg,avg_best);
        }
        return avg_best;
    }
};