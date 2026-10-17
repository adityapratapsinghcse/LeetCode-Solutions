
class Solution:
    def digitSum(self, num):
        total = 0

        while num > 0:
            total += num % 10
            num //= 10

        return total

    def minSwaps(self, nums):
        n = len(nums)

        arr = []

        for i in range(n):
            arr.append((self.digitSum(nums[i]), nums[i], i))

        arr.sort()

        visited = [False] * n
        swaps = 0

        for i in range(n):
            if visited[i] or arr[i][2] == i:
                continue

            cycle_size = 0
            j = i

            while not visited[j]:
                visited[j] = True
                j = arr[j][2]
                cycle_size += 1

            if cycle_size > 1:
                swaps += cycle_size - 1

        return swaps
