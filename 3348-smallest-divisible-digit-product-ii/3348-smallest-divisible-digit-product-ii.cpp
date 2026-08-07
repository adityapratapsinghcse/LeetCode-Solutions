#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // digit -> {e2, e3, e5, e7}
    array<int,4> digitFactors(int d) {
        switch (d) {
            case 1: return {0,0,0,0};
            case 2: return {1,0,0,0};
            case 3: return {0,1,0,0};
            case 4: return {2,0,0,0};
            case 5: return {0,0,1,0};
            case 6: return {1,1,0,0};
            case 7: return {0,0,0,1};
            case 8: return {3,0,0,0};
            case 9: return {0,2,0,0};
        }
        return {0,0,0,0};
    }

    // Smallest (fewest-digit, then lexicographically smallest) sorted digit
    // string whose product supplies at least e2,e3,e5,e7 of each prime.
    string minDigits(int e2, int e3, int e5, int e7) {
        int nine = e3 / 2, r3 = e3 % 2;
        int eight = e2 / 3, r2 = e2 % 3;
        int six = 0, four = 0, two = 0, three = 0;

        if (r3 == 1 && r2 >= 1) { six = 1; r2 -= 1; r3 = 0; }
        if (r2 == 2) { four = 1; r2 = 0; }
        else if (r2 == 1) { two = 1; r2 = 0; }
        if (r3 == 1) { three = 1; }

        string res;
        res.append(eight, '8');
        res.append(nine, '9');
        res.append(e5, '5');
        res.append(e7, '7');
        res.append(six, '6');
        res.append(four, '4');
        res.append(two, '2');
        res.append(three, '3');
        sort(res.begin(), res.end());
        return res;
    }

    string smallestNumber(string num, long long t) {
        int te2=0, te3=0, te5=0, te7=0;
        for (int p : {2,3,5,7}) {
            int &cnt = (p==2?te2 : p==3?te3 : p==5?te5 : te7);
            while (t % p == 0) { cnt++; t /= p; }
        }
        if (t > 1) return "-1"; // t has a prime factor > 7, impossible

        int n = num.size();

        // prefix[i] = factors of num[0..i-1]
        vector<array<int,4>> prefix(n+1, {0,0,0,0});
        for (int i = 0; i < n; ++i) {
            auto f = digitFactors(num[i]-'0');
            prefix[i+1] = prefix[i];
            for (int k = 0; k < 4; ++k) prefix[i+1][k] += f[k];
        }

        int firstZero = num.find('0');
        if (firstZero == (int)string::npos) {
            firstZero = n;
            auto &tot = prefix[n];
            if (tot[0] >= te2 && tot[1] >= te3 && tot[2] >= te5 && tot[3] >= te7)
                return num;
        }

        int hi = min(firstZero, n - 1);
        for (int i = hi; i >= 0; --i) {
            int startD = (i == firstZero && firstZero < n) ? 1 : (num[i]-'0'+1);
            int remaining = n - 1 - i;
            for (int d = startD; d <= 9; ++d) {
                auto fd = digitFactors(d);
                int ne2 = max(0, te2 - prefix[i][0] - fd[0]);
                int ne3 = max(0, te3 - prefix[i][1] - fd[1]);
                int ne5 = max(0, te5 - prefix[i][2] - fd[2]);
                int ne7 = max(0, te7 - prefix[i][3] - fd[3]);
                string suffix = minDigits(ne2, ne3, ne5, ne7);
                if ((int)suffix.size() <= remaining) {
                    string res = num.substr(0, i) + char('0'+d);
                    res.append(remaining - suffix.size(), '1');
                    res += suffix;
                    return res;
                }
            }
        }

        // No same-length answer: go to a longer length
        string core = minDigits(te2, te3, te5, te7);
        int targetLen = max(n + 1, (int)core.size());
        string res(targetLen - core.size(), '1');
        res += core;
        return res;
    }
};