
#define MOD 1000000007LL
#define MAXN 1001

long long comb[MAXN][MAXN];

long long solve(int nums[], int n) {
    if (n <= 2)
        return 1;

    int left[MAXN], right[MAXN];
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[0])
            left[l++] = nums[i];
        else
            right[r++] = nums[i];
    }

    long long ways = comb[n - 1][l];

    ways = ways * solve(left, l) % MOD;
    ways = ways * solve(right, r) % MOD;

    return ways;
}

int numOfWays(int* nums, int numsSize) {
    for (int i = 0; i <= numsSize; i++) {
        comb[i][0] = comb[i][i] = 1;

        for (int j = 1; j < i; j++) {
            comb[i][j] =
                (comb[i - 1][j - 1] +
                 comb[i - 1][j]) % MOD;
        }
    }

    return (solve(nums, numsSize) - 1 + MOD) % MOD;
}
