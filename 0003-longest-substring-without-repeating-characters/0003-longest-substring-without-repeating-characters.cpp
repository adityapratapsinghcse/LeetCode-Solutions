class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int best = 0;

        unordered_map<int,char> freq;

        for(int j=0; j<s.length(); j++){
            freq[s[j]]++;

            while(freq[s[j]] != 1){
                freq[s[i]]--;
                i++;
            }
            best= max(best , j-i+1);
        } 
        return best;
    }
};