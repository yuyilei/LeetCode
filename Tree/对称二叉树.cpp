/*
给定一个二叉树，检查它是否是镜像对称的。
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if ( !root ) 
            return true;
        return Symmetric(root->left,root->right); 
    }
    bool Symmetric(TreeNode* l, TreeNode* r) {
        if ( !l && !r ) 
            return true;
        if ( !l || !r ) 
            return false;
        if ( l->val != r->val ) 
            return false;
        return Symmetric(l->left,r->right) && Symmetric(l->right,r->left); 
    }
};