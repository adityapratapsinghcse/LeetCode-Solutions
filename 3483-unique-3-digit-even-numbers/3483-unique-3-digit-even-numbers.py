class Solution:
    def totalNumbers(self, digits):
        freq = [0] * 10

        for d in digits:
            freq[d] += 1

        ans = 0

        for num in range(100, 1000):

            # Must be even
            if num % 2 != 0:
                continue

            ones = num % 10
            tens = (num // 10) % 10
            hundreds = num // 100

            need = [0] * 10

            need[hundreds] += 1
            need[tens] += 1
            need[ones] += 1

            possible = True

            for d in range(10):
                if need[d] > freq[d]:
                    possible = False
                    break

            if possible:
                ans += 1

        return ans