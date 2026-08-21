class Solution {
    // Overflow-safe LCM computation
    long long lcm(long long a, long long b) {
        long long g = __gcd(a, b);
        // Check overflow before multiplying
        if (a / g > LLONG_MAX / b) return LLONG_MAX; // treat as "too big, contributes 0"
        return (a / g) * b;
    }

    bool is_possible(vector<int>& coins, long long mid, int k) {
        int n = coins.size();
        long long count = 0;

        // Iterate over all non-empty subsets of coins
        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            int bits = __builtin_popcount(mask); // subset size -> tells sign

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    l = lcm(l, coins[i]);
                    if (l > mid) break; // no point continuing, term will be 0 anyway
                }
            }

            if (l > mid) continue; // this subset's lcm exceeds mid, contributes 0

            if (bits % 2 == 1)
                count += mid / l;   // odd-size subset -> add
            else
                count -= mid / l;   // even-size subset -> subtract
        }

        return count >= k;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long start = 1;
        long long end = (long long) k * (*min_element(coins.begin(), coins.end()));
        long long ans = end; // safe fallback

        while (start <= end) {
            long long mid = start + (end - start) / 2; // avoids overflow on addition too

            if (is_possible(coins, mid, k)) {
                ans = mid;
                end = mid - 1;   // try to find a smaller valid mid
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};