class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        ans = 0
        alt_sum = 0
        for i in range(len(gain)):
            alt_sum += gain[i]

            if(ans < alt_sum):
                ans = alt_sum
        
        return ans