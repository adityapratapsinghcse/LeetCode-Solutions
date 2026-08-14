class Solution {
public:
    int maximumLengthSubstring(string s) {
        int max_len = 0;
        int i =0;
        int j =0;

        unordered_map<char,int> count;

        while(j < s.length()){
            count[s[j]]++;

            while(count[s[j]] > 2){
                count[s[i]]--;
                i++;
            }

            max_len = max(max_len,(j-i+1));

            j++;
        }
        return max_len;
    }
};