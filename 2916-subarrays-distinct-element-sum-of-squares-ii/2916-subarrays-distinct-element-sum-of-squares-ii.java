
import java.util.*;

class Solution {
    static final long MOD = 1_000_000_007L;

    long[] sum, sq, lazy;
    int n;

    void apply(int p, int l, int r, long v) {
        long len = r - l + 1;

        sq[p] = (sq[p] + 2 * v * sum[p]
                + (len * v % MOD) * v) % MOD;

        sum[p] = (sum[p] + len * v) % MOD;
        lazy[p] = (lazy[p] + v) % MOD;
    }

    void push(int p, int l, int r) {
        if (lazy[p] == 0 || l == r) return;

        int m = (l + r) / 2;

        apply(p * 2, l, m, lazy[p]);
        apply(p * 2 + 1, m + 1, r, lazy[p]);

        lazy[p] = 0;
    }

    void update(int p, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(p, l, r, 1);
            return;
        }

        push(p, l, r);

        int m = (l + r) / 2;

        update(p * 2, l, m, ql, qr);
        update(p * 2 + 1, m + 1, r, ql, qr);

        sum[p] = (sum[p * 2] + sum[p * 2 + 1]) % MOD;
        sq[p] = (sq[p * 2] + sq[p * 2 + 1]) % MOD;
    }

    public int sumCounts(int[] nums) {
        n = nums.length;

        sum = new long[4 * n + 5];
        sq = new long[4 * n + 5];
        lazy = new long[4 * n + 5];

        Map<Integer, Integer> last = new HashMap<>();
        long ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last.getOrDefault(nums[i], -1);

            update(1, 0, n - 1, prev + 1, i);

            ans = (ans + sq[1]) % MOD;

            last.put(nums[i], i);
        }

        return (int) ans;
    }
}
