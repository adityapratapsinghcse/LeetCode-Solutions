class Solution {
private:
    bool is_possible(vector<int> &weights , int mid , int days){
        int day = 1;
        int ship_load = 0;

        for(int i=0 ; i < weights.size() ;){ //To visite and check each bag
            if(ship_load + weights[i] <= mid){
                ship_load += weights[i];
                i++;
            }
            else{
                day+=1;
                ship_load=0;
            }
            // KKhya humhne dewdline cross toh nahi ki
            if(day > days){
                return false;
            }
        }
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int ans; //Capacity of ship
        int start = *max_element(weights.begin(), weights.end());// Worst Case
        int total=0;
        for(int i=0 ; i< weights.size() ; i++){
            total += weights[i];
        }
        int end = total; // Best case

        while(start <= end){
            int mid = start + (end - start) / 2; //Assume ATMAX 'mid' capacity of ship

            if(is_possible(weights, mid , days)){
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