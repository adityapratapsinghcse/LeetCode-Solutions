class Solution(object):
    def is_possible(self,weights,mid,days):
        day=1
        ship_load=0
        i=0
        while(i< len(weights)):
            if(ship_load + weights[i] <= mid):
                ship_load += weights[i]
                i +=1
            else:
                day +=1
                ship_load =0
            
            if(day > days): 
                return False

        return True

    def shipWithinDays(self, weights, days):
        """
        :type weights: List[int]
        :type days: int
        :rtype: int
        """
        start = 1
        total =0 
        for i in weights:
            total += i
        end = total
        ans=0
        while(start <= end):
            mid = (start+end) // 2

            if(self.is_possible(weights,mid,days)):
                ans = mid
                end = mid-1
            else:
                start = mid +1
        return ans
        