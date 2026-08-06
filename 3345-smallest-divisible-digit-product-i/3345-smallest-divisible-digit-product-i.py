class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        i=n
        while True:
            copy =i
            prod=1
            while(copy>0):
                digit = copy % 10
                prod *= digit
                copy //= 10
            if(prod % t == 0):
                return i
            i +=1