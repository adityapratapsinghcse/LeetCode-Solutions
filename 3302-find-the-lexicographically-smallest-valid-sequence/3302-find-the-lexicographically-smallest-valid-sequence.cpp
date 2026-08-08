class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        // suf[j] = largest starting index i such that word2[j:] 
        // embeds exactly as a subsequence in word1[i:]
        vector<int> suf(m + 1, -1);
        suf[m] = n;  // empty suffix: trivially satisfiable from anywhere

        int i = n - 1, j = m - 1;
        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                suf[j] = i;
                j--;
            }
            i--;
        }

        vector<int> result;
        result.reserve(m);
        bool usedMismatch = false;
        i = 0;

        for (int k = 0; k < m; k++) {
            if (i >= n) return {};

            if (word1[i] == word2[k]) {
                // exact match at the smallest available index — always take it
                result.push_back(i);
                i++;
            } else if (!usedMismatch && i + 1 <= suf[k + 1]) {
                // spend the one allowed mismatch here
                result.push_back(i);
                i++;
                usedMismatch = true;
            } else {
                // mismatch not usable (already spent, or rest wouldn't complete) 
                // -> must find an exact match going forward
                while (i < n && word1[i] != word2[k]) i++;
                if (i >= n) return {};
                result.push_back(i);
                i++;
            }
        }
        return result;
    }
};