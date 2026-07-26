#include<deque>
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return{};
        }

        bool zig = true;
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int LevelSize = q.size();
            vector<int> CurrentLevel;

            for(int i=0 ; i < LevelSize ; i++){
                TreeNode* node = q.front();
                q.pop();
                CurrentLevel.push_back(node->val);
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            if(zig){
                result.push_back(CurrentLevel);
            }else{
                reverse(CurrentLevel.begin(),CurrentLevel.end());
                result.push_back(CurrentLevel);
            }
            zig = !zig;
        }
        return result;
    }
};