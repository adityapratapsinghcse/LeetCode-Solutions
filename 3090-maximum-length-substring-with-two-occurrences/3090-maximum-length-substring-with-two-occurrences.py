class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        i = 0
        j = 0
        max_len = 0
        freq = {}

        while(j < len(s)):
            freq[s[j]] = freq.get(s[j], 0) + 1

            while(freq.get(s[j],0) > 2):
                freq[s[i]] -=1
                i+=1

            max_len = max(max_len,(j-i+1))
            j+=1
        return max_len