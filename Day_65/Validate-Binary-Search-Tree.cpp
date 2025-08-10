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
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
    
private:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) return true;
        
        // Check if current node violates BST property
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }
        
        // Recursively validate left and right subtrees with updated bounds
        return validate(node->left, minVal, node->val) && 
               validate(node->right, node->val, maxVal);
    }
};