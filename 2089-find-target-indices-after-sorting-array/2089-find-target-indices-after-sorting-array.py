class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        smaller = 0
        equal = 0

        for x in nums:
            if x < target:
                smaller += 1
            elif x == target:
                equal += 1

        ans = []

        for i in range(smaller, smaller + equal):
            ans.append(i)

        return ans