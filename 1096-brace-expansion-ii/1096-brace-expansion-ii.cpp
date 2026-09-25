class Solution {
public:

    set<string> combine(set<string>& A, set<string>& B) {
        set<string> result;

        for (string a : A) {
            for (string b : B) {
                result.insert(a + b);
            }
        }

        return result;
    }

    set<string> parse(string& s, int& i) {

        set<string> result;

        set<string> current;
        current.insert("");

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {

                result.insert(current.begin(), current.end());

                current.clear();
                current.insert("");

                i++;
            }

            else if (s[i] == '{') {

                i++;
                set<string> inside = parse(s, i);

                i++; 
                current = combine(current, inside);
            }

            else {

                set<string> letter;
                letter.insert(string(1, s[i]));

                current = combine(current, letter);

                i++;
            }
        }

        result.insert(current.begin(), current.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ansSet = parse(expression, i);

        return vector<string>(ansSet.begin(), ansSet.end());
    }
};