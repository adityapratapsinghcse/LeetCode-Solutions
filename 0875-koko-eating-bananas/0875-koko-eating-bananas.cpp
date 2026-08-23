class Solution {

    bool is_possible(vector<int> &piles, int mid ,int h){
        int hour =0;

        for(int i=0 ;i < piles.size() ; i++){
            if(piles[i] % mid == 0){
                hour += (piles[i] / mid);
            }
            else{
                hour += (piles[i] / mid) +1;
            }

            if(hour > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int maxi = piles[0];
        for(int i=0; i< piles.size() ; i++){
            maxi = max(maxi, piles[i]);
        }
        int end= maxi;
        int ans=-1;

        while(start <= end){
            int mid = (start+end) /2;

            if(is_possible(piles,mid,h)){
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