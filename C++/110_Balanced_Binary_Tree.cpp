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
    bool isBalanced(TreeNode* root){
        return (getres(root) < 0 ) ? false : true ; 
    }
    int getres(TreeNode *root){
        if ( !root ) return 0 ; 
        int hl = getres(root->left) ; 
        int hr = getres(root->right) ; 
        if ( hl < 0 || hr < 0 || abs(hl-hr) > 1 ) 
            return -1 ; 
        return max(hl,hr) + 1 ; 
    }
};