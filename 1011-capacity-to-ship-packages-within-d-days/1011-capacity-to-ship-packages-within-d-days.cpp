class Solution {
    bool is_possible(vector<int> &weights , int mid , int days){
        int day=1;
        int ship_load =0;

        for(int i=0 ; i< weights.size() ;i++){
            if(weights[i]+ship_load <= mid){
                ship_load += weights[i];
            }
            else{
                day+=1;
                ship_load =weights[i];
            }

            if(day > days){
                return false;
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int total=0;
        int maxi = weights[0];

        for(int i =0 ; i< weights.size() ; i++){
            total += weights[i];
            maxi = max(maxi , weights[i]);
        }

        int start = maxi;
        int end = total;
        int ans =-1;

        while(start <= end){
            int mid= (start+end) /2;

            if(is_possible(weights,mid,days)){
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