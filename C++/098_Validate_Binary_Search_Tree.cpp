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
    bool isValidBST(TreeNode* root) {
        if ( !root )
            return true ; 
        if ( root->left ) 
            if ( root->left->val >= root->val || root->val <= minright(root->left) ) 
                return false ; 
        if ( root->right )
            if ( root->right->val <= root->val || root->val >= maxleft(root->right) )
                return false ; 
        return isValidBST(root->left) && isValidBST(root->right) ; 
    }
    int maxleft(TreeNode* root) {
        while ( root->left ) 
            root = root->left ; 
        return root->val ; 
    }
    int minright(TreeNode* root) {
        while ( root->right ) 
            root = root->right ;
        return root->val ; 
    }
};