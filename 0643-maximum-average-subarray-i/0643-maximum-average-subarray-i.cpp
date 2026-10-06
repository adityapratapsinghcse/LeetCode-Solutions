class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0 ;
        for(int i = 0 ; i< k; i++){
            sum += nums[i];
        }

        double best_avg =  sum / k;
    
        int i = 0 ; int j = k;

        while(j < nums.size()){
            sum -= nums[i];
            i++;
            
            sum += nums[j];
            j++;

            double avg = sum / k;
            best_avg = max(avg , best_avg);
        }

        return best_avg;

    }
};