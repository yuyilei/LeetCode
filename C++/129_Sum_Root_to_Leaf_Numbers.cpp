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
    int res = 0 ; 
    int sumNumbers(TreeNode* root){
        getres(root,0) ; 
        return res ; 
    } 
    void getres(TreeNode* root, int last){ 
        if  ( !root ) return ;
        last = last*10 + root->val ; 
        getres(root->left,last) ; 
        getres(root->right,last) ; 
        if ( !root->left && !root->right ) 
            res += last ; 
    }
};