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

        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);

        int level_count=0;

        while(!q.empty()){
            int LevelSize = q.size();
            deque<int> CurrentLevel;
            for(int i=0 ; i < LevelSize ; i++){
                TreeNode* node = q.front();
                q.pop();
                if(level_count %2 == 0){
                    CurrentLevel.push_back(node->val);
                }else{
                    CurrentLevel.push_front(node->val);
                }
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            vector<int> CurrentlevelVec(CurrentLevel.begin(),CurrentLevel.end());    
            result.push_back(CurrentlevelVec);
            level_count++;
        }
        return result;
    }
};