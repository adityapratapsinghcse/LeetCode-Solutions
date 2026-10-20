
import java.util.*;

class Solution {
    private boolean isRotation(int[] nums, int[] sorted,
                               int start, int k) {
        int[] pattern = new int[k];
        int[] lps = new int[k];

        for (int i = 0; i < k; i++) {
            pattern[i] = nums[start + i];
        }

        for (int i = 1, len = 0; i < k;) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int i = 0, j = 0;

        while (i < 2 * k && j < k) {
            int value = sorted[start + (i % k)];

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

    public int sortableIntegers(int[] nums) {
        int n = nums.length;
        int[] sorted = nums.clone();
        Arrays.sort(sorted);

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            boolean valid = true;

            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sorted, start, k)) {
                    valid = false;
                    break;
                }
            }

            if (valid) ans += k;
        }

        return ans;
    }
}
