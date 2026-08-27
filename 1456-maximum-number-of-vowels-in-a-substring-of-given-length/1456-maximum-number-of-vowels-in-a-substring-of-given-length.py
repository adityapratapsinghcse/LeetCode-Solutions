class Solution(object):
    def maxVowels(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        i =0
        maxi=0
        vowel=0
        vowels = {'a','e','i','o','u'}

        for ids in range(k):
            if(s[ids] in vowels):
                vowel+=1
        maxi = vowel

        for j in range(k,len(s)):
            if(s[i] in vowels):
                vowel-=1
            i+=1
            if(s[j] in vowels):
                vowel+=1
            maxi = max(maxi,vowel)
        return maxi