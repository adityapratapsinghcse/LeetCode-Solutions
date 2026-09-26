#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Build the hash map for O(1) lookups
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        
        string res = "";
        string curr_key = "";
        bool inside = false;
        
        for (char c : s) {
            if (c == '(') {
                inside = true;
            } else if (c == ')') {
                inside = false;
                // Look up the extracted key
                if (dict.count(curr_key)) {
                    res += dict[curr_key];
                } else {
                    res += "?";
                }
                curr_key = ""; // Reset for the next bracket pair
            } else if (inside) {
                curr_key += c;
            } else {
                res += c;
            }
        }
        
        return res;
    }
};