
class Solution {
    bool isRotation(vector<int>& nums, vector<int>& sortedNums,
                    int start, int k) {
        vector<int> pattern(nums.begin() + start,
                            nums.begin() + start + k);

        vector<int> lps(k, 0);

        // Build the KMP LPS array
        for (int i = 1, len = 0; i < k;) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search pattern in the doubled sorted block
        int i = 0, j = 0;

        while (i < 2 * k && j < k) {
            int value = sortedNums[start + (i % k)];

            if (value == pattern[j]) {
                i++;
                j++;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return j == k;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sortedNums, start, k)) {
                    valid = false;
                    break;
                }
            }

            if (valid) ans += k;
        }

        return ans;
    }
};
