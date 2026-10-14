class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum == 0 or sum > 9 * num:
            return ""

        ans = []

        while sum >= 9:
            ans.append('9')
            sum -= 9
            num -= 1

        if sum > 0:
            ans.append(str(sum))
            num -= 1

        ans.extend(['0'] * num)

        return ''.join(ans)