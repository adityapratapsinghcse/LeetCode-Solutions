class Solution {
public:
    unordered_set<string> ans;

    void solve(string &s, int idx, string curr,
               int open, int close,
               int balance) {

        if (idx == s.size()) {
            if (open == 0 && close == 0 && balance == 0) {
                ans.insert(curr);
            }
            return;
        }

        char ch = s[idx];

        // Letters must always be kept
        if (ch != '(' && ch != ')') {
            solve(s, idx + 1, curr + ch,
                  open, close, balance);
            return;
        }

        // Option 1: Remove this parenthesis
        if (ch == '(' && open > 0) {
            solve(s, idx + 1, curr,
                  open - 1, close, balance);
        }

        if (ch == ')' && close > 0) {
            solve(s, idx + 1, curr,
                  open, close - 1, balance);
        }

        // Option 2: Keep this parenthesis
        if (ch == '(') {
            solve(s, idx + 1, curr + ch,
                  open, close, balance + 1);
        } 
        else if (balance > 0) {
            solve(s, idx + 1, curr + ch,
                  open, close, balance - 1);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int open = 0, close = 0;

        // Find the minimum removals required
        for (char ch : s) {
            if (ch == '(') {
                open++;
            } 
            else if (ch == ')') {
                if (open > 0) {
                    open--;
                } 
                else {
                    close++;
                }
            }
        }

        solve(s, 0, "", open, close, 0);

        return vector<string>(ans.begin(), ans.end());
    }
};