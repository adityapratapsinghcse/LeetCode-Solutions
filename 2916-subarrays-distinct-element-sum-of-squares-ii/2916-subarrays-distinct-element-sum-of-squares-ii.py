
class Solution:
    def sumCounts(self, nums: list[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        tree_sum = [0] * (4 * n + 5)
        tree_sq = [0] * (4 * n + 5)
        lazy = [0] * (4 * n + 5)

        def apply(p, l, r, v):
            length = r - l + 1

            tree_sq[p] = (
                tree_sq[p]
                + 2 * v * tree_sum[p]
                + length * v * v
            ) % MOD

            tree_sum[p] = (
                tree_sum[p] + length * v
            ) % MOD

            lazy[p] = (lazy[p] + v) % MOD

        def push(p, l, r):
            if lazy[p] == 0 or l == r:
                return

            m = (l + r) // 2

            apply(p * 2, l, m, lazy[p])
            apply(p * 2 + 1, m + 1, r, lazy[p])

            lazy[p] = 0

        def update(p, l, r, ql, qr):
            if ql > r or qr < l:
                return

            if ql <= l and r <= qr:
                apply(p, l, r, 1)
                return

            push(p, l, r)

            m = (l + r) // 2

            update(p * 2, l, m, ql, qr)
            update(p * 2 + 1, m + 1, r, ql, qr)

            tree_sum[p] = (
                tree_sum[p * 2] + tree_sum[p * 2 + 1]
            ) % MOD

            tree_sq[p] = (
                tree_sq[p * 2] + tree_sq[p * 2 + 1]
            ) % MOD

        last = {}
        ans = 0

        for i, x in enumerate(nums):
            prev = last.get(x, -1)

            update(1, 0, n - 1, prev + 1, i)

            ans = (ans + tree_sq[1]) % MOD

            last[x] = i

        return ans
