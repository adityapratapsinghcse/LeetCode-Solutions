class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        i =0
        j =len(nums)-1
        k =len(nums)-1

        ans = [0] * len(nums)

        while(i <= j):
            if(abs(nums[i]) > abs(nums[j])):
                ans[k] = nums[i] * nums[i]
                i+=1
            else:
                ans[k] = nums[j] * nums[j]
                j-=1
            k-=1
        return ans