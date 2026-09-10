/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Custom struct to return two values from DFS
struct SubtreeData {
    int sum;
    int count;
};

struct SubtreeData dfs(struct TreeNode* node, int* matchCount) {
    struct SubtreeData data = {0, 0};
    if (node == NULL) {
        return data;
    }

    struct SubtreeData leftData = dfs(node->left, matchCount);
    struct SubtreeData rightData = dfs(node->right, matchCount);

    data.sum = leftData.sum + rightData.sum + node->val;
    data.count = leftData.count + rightData.count + 1;

    // Check if the current node's value equals the average
    if (node->val == data.sum / data.count) {
        (*matchCount)++;
    }

    return data;
}

int averageOfSubtree(struct TreeNode* root) {
    int matchCount = 0;
    dfs(root, &matchCount);
    return matchCount;
}