class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int alt_sum = 0;
        for(int i = 0; i < gain.size(); i++) {
            alt_sum += gain[i];

            if(ans < alt_sum) {
                ans = alt_sum;
            }
        }
        return ans;
    }
};