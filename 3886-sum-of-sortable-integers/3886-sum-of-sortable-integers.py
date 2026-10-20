
class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        sorted_nums = sorted(nums)

        def is_rotation(a, b):
            k = len(a)
            pattern = a
            lps = [0] * k

            # Build KMP LPS array
            j = 0
            for i in range(1, k):
                while j > 0 and pattern[i] != pattern[j]:
                    j = lps[j - 1]

                if pattern[i] == pattern[j]:
                    j += 1
                    lps[i] = j

            # Search pattern in doubled target block
            i = j = 0
            while i < 2 * k and j < k:
                value = b[i % k]

                if value == pattern[j]:
                    i += 1
                    j += 1
                elif j > 0:
                    j = lps[j - 1]
                else:
                    i += 1

            return j == k

        ans = 0

        for k in range(1, n + 1):
            if n % k != 0:
                continue

            valid = True

            for start in range(0, n, k):
                a = nums[start:start + k]
                b = sorted_nums[start:start + k]

                if not is_rotation(a, b):
                    valid = False
                    break

            if valid:
                ans += k

        return ans
