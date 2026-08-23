class Solution {
    bool is_possible(vector<int> &bloomDay , int mid , int m , int k){
        int bouque = 0;
        int total = 0;

        for(int i=0; i< bloomDay.size() ; i++){
            if(bloomDay[i] <= mid){
                bouque+=1;
            }
            else{
                bouque = 0;
            }

            if(bouque == k){
                bouque = 0;
                total +=1;
            }

            if(total >= m){
                return true;
            }
        }
        return false;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        if((long long)m*k > bloomDay.size()){
            return -1;
        }

        int mini = bloomDay[0];
        int maxi = bloomDay[0];

        for(int i=0 ; i< bloomDay.size() ; i++){
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }   
        int ans = -1;
        int start = mini;
        int end = maxi;
        
        while(start <= end){
            int mid = (start+end) /2;

            if(is_possible(bloomDay , mid, m ,k)){
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