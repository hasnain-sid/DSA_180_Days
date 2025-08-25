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
    int helper(TreeNode* root, int prev){
        if(!root) return 0;
        if(root->val >= prev){
            return 1 + helper(root->left, max(root->val,prev)) + helper(root->right, max(root->val,prev));
        }
        else
            return helper(root->left, max(root->val,prev)) + helper(root->right, max(root->val,prev));
    }
    int goodNodes(TreeNode* root) {
        return helper(root, -1000000);                    
    }
};