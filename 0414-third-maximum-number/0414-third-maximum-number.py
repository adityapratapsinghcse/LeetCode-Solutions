class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        max2 = float('-inf')
        max1 = float('-inf')
        max3 = float('-inf')

        for i in nums:
            
            if(i == max1 or i == max2 or i == max3):
                continue

            if(i > max1):
                max3 = max2
                max2 = max1
                max1 = i
            elif(i > max2):
                max3 = max2
                max2 = i
            elif(i > max3):
                max3 = i
        
        if(max3 == float('-inf')):
            return max1
        return max3