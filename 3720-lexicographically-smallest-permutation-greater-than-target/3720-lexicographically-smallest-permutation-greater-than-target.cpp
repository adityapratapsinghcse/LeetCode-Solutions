class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";

        // Try to match target from left to right
        for (int i = 0; i < s.size(); i++) {

            int x = target[i] - 'a';

            // We can put the same character
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
                continue;
            }

            // Same character is unavailable.
            // Try the smallest character greater than target[i].
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    ans += char('a' + c);
                    freq[c]--;

                    // Remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }

            // No greater character at this position.
            // We need to backtrack.
            break;
        }

        /*
            We couldn't make the answer greater while moving forward.
            Now backtrack through the already matched prefix.
        */

        // Recreate frequency array
        fill(freq.begin(), freq.end(), 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        ans = "";

        // Build the longest prefix equal to target
        int i = 0;

        for (; i < s.size(); i++) {

            int x = target[i] - 'a';

            if (freq[x] == 0)
                break;

            ans += target[i];
            freq[x]--;
        }

        // Backtrack
        for (int pos = ans.size() - 1; pos >= 0; pos--) {

            int current = ans[pos] - 'a';

            // Return the character used at this position
            freq[current]++;

            // Find smallest character greater than current
            for (int c = current + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string result = ans.substr(0, pos);

                    result += char('a' + c);
                    freq[c]--;

                    // Put all remaining characters in sorted order
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            result += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
    }
};