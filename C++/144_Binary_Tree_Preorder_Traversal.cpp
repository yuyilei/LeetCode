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
    void preorder(vector<int> &res,TreeNode *root){
        if ( !root ) return ; 
        res.push_back(root->val) ; 
        preorder(res,root->left) ; 
        preorder(res,root->right) ; 
    }
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res ; 
        preorder(res,root) ; 
        return res ; 
    } 
};