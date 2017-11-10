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
    void postorder(vector<int> &res, TreeNode *root){
        if ( !root ) return ; 
        postorder(res,root->left) ; 
        postorder(res,root->right) ; 
        res.push_back(root->val) ; 
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res ; 
        postorder(res,root) ; 
        return res ; 
    }
};