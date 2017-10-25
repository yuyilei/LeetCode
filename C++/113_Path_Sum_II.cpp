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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res ; 
        vector<int> tmp ; 
        getres(root,sum,res,tmp) ; 
        return res ; 
    } 
    void getres(TreeNode* root, int sum, vector<vector<int> > &res, vector<int> tmp) {
        if ( root == NULL ) 
            return ; 
        tmp.push_back(root->val) ; 
        if ( root->left == NULL && root->right == NULL ) {
            if ( sum == root->val ) 
                res.push_back(tmp) ; 
            return ; 
        } 
        getres(root->left,sum-root->val,res,tmp) ; 
        getres(root->right,sum-root->val,res,tmp) ; 
    }
};