class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, best = 0;

        vector<int> freq(256,0);
        
        for(int right =0 ; right < s.length() ; right++){
            freq[s[right]]++;

            while(freq[s[right]] != 1){
                freq[s[left]]--;
                left++;
            }
            best = max(best,(right-left+1));
        }
        return best;
    }
};