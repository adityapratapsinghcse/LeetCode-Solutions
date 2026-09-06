class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int alt_sum=0;
        int n = gain.size();

        for(int i=0; i< n ; i++){
            alt_sum += gain[i];
            if(ans < alt_sum){
                ans = alt_sum;
            }
        }
        return ans;
    }
};