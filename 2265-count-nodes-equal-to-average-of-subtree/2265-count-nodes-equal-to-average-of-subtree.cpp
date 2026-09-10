/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int matchCount = 0;

    // Helper function that returns a pair: {sum_of_subtree, count_of_nodes_in_subtree}
    std::pair<int, int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, 0};
        }

        // Post-order: process left and right subtrees first
        std::pair<int, int> leftData = dfs(node->left);
        std::pair<int, int> rightData = dfs(node->right);

        // Calculate current node's subtree sum and count
        int currentSum = leftData.first + rightData.first + node->val;
        int currentCount = leftData.second + rightData.second + 1;

        // Check if the current node's value equals the average of its subtree
        if (node->val == currentSum / currentCount) {
            matchCount++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchCount;
    }
};