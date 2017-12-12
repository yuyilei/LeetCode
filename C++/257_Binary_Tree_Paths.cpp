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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res ;
        if ( !root ) return res ; 
        getres(root,to_string(root->val),res) ; 
        return res ; 
    }
    void getres(TreeNode* root, string now, vector<string> &res) {
        if ( root->left ) 
            getres(root->left,now+"->"+to_string(root->left->val),res) ; 
        if ( root->right) 
            getres(root->right,now+"->"+to_string(root->right->val),res) ; 
        if ( !root->left && !root->right ) 
            res.push_back(now) ; 
    }
};