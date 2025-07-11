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
    int maxm = 0;
    int helper(TreeNode* root,int height)
    {
        if(root == NULL)
            return 0;
        // if(root->left )
        int left = 1 + helper(root->left,height);
        int right = 1 + helper(root->right,height);
        maxm = max(maxm,left+right);

        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int height = 0;
        helper(root,height);
        return maxm-2;
    }
};