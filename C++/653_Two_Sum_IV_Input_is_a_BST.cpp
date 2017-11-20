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
    bool findTarget(TreeNode* root, int k) {
        return getres(root,root,k) ; 
    } 
    bool getres(TreeNode* left, TreeNode* right, int k ){
        if ( !left || !right ) 
            return false ; 
        int tmp = left->val + right->val ; 
        if ( left != right && tmp == k ) 
            return true ; 
        if ( tmp < k ) 
            return getres(left->right,right,k) || getres(left,right->right,k) ; 
        return getres(left->left,right,k) || getres(left,right->left,k) ; 
    }  
};