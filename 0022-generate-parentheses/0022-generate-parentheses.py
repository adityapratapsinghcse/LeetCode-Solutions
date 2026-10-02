class Solution:
    def solve(self,current , open , close , n , result):
        if len(current) == 2*n:
            result.append(current)
            return
        
        if(open < n):
            self.solve(current + '(' , open +1 , close ,n, result)
        
        if(close < open):
            self.solve(current + ')' , open , close+1 ,n, result)

    def generateParenthesis(self, n: int) -> list[str]:
        result= []

        self.solve("" , 0 ,0 , n,result)
        return result