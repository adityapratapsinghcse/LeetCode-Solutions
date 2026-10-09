
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            }
            else {
                // Ensure we have two consecutive ')'
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    insertions++;
                }

                // Match the closing pair with '('
                if (open > 0) {
                    open--;
                }
                else {
                    insertions++;
                }
            }
        }

        // Every unmatched '(' needs two ')'
        insertions += open * 2;

        return insertions;
    }
};