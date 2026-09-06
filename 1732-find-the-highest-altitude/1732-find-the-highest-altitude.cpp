class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int highest = 0;

        vector<int> answer(n+1 , 0);

        for(int i = 1 ; i< n+1  ;i++){
            answer[i] = answer[i-1] + gain[i-1];
            highest = max(highest, answer[i]);    
        }
        return highest;
    }
};