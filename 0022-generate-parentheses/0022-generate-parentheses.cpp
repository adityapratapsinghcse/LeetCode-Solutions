class Solution {
    vector<string> result;

    void solve(string current , int open , int close , int n){
        //Base Case 
        if(current.length() == 2* n){
            result.push_back(current);
            return;
        }

        if(open < n){
            solve(current + '(' , open+1 , close , n);
        }

        if(close < open){
            solve(current + ')' , open , close+1 , n);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        solve("",0,0,n);
        return result;
    }
};