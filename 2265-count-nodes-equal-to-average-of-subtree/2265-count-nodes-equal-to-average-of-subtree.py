# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
        self.match_count = 0
        
        def dfs(node):
            if not node:
                return 0, 0  # sum, count
            
            left_sum, left_count = dfs(node.left)
            right_sum, right_count = dfs(node.right)
            
            current_sum = left_sum + right_sum + node.val
            current_count = left_count + right_count + 1
            
            # Use integer division // to automatically round down
            if node.val == current_sum // current_count:
                self.match_count += 1
                
            return current_sum, current_count
            
        dfs(root)
        return self.match_count