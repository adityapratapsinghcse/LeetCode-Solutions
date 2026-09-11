class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        for (int num = 100; num <= 999; num++) {

            // Must be even
            if (num % 2 != 0)
                continue;

            int x = num;

            int ones = x % 10;
            x /= 10;

            int tens = x % 10;
            x /= 10;

            int hundreds = x;

            // Check availability
            vector<int> need(10, 0);

            need[hundreds]++;
            need[tens]++;
            need[ones]++;

            bool possible = true;

            for (int d = 0; d <= 9; d++) {
                if (need[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans++;
        }

        return ans;
    }
};