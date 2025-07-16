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
    vector<int> t;
    void find(vector<int> &v,TreeNode* root)
    {
        if(root == NULL)
            return;
        
        
        find(v,root->left);
        v.push_back(root->val);
        find(v,root->right);
        return;
    }
    bool flag = false;
    bool traverse(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL and subRoot == NULL)
            return true;
        else if(root == NULL or subRoot == NULL)
            return false;

        bool a = true;
        bool x = traverse(root->left,subRoot->left);
        if(root->val != subRoot->val)
        {
            a = false;
        }
        bool y = traverse(root->right,subRoot->right);
        return (x and y and a);

    }
    void helper(TreeNode* root, TreeNode* subRoot) {
        
        if(root == NULL)
            return;
        if(root->val == subRoot->val)
        {
            bool k = traverse(subRoot,root);
            // vector<int> v;
            // find(v,root);
            if(k == true)
                flag = true;
            // return;
        }
        helper(root->left,subRoot);
        helper(root->right,subRoot);
        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         
        // find(t,subRoot);
        helper(root,subRoot);
        return flag;
    }
};