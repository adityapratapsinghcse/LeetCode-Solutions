from collections import defaultdict
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        mp[0] = 1
        prefix_sum = 0
        count = 0
        for num in nums:
            prefix_sum += num
            target = prefix_sum - k
            if target in mp:
                count += mp[target]
            mp[prefix_sum] += 1
        return count