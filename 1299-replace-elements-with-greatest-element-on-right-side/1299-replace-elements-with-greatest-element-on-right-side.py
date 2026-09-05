class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        suffix_max = [0] * len(arr)
        n = len(arr)
        suffix_max[n-1] = -1
        for i in range(n-2,-1,-1):
            if(suffix_max[i+1] > arr[i+1]):
                suffix_max[i] = suffix_max[i+1]
            else:
                suffix_max[i] = arr[i+1]
        return suffix_max