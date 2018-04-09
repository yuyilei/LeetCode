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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = min(p->val,q->val) ; 
        int y = max(p->val,q->val) ; 
        if ( root->val >= x && root->val <= y ) 
            return root ;
        if ( root->val >= y ) 
            return lowestCommonAncestor(root->left,p,q) ; 
        if ( root->val <= x ) 
            return lowestCommonAncestor(root->right,p,q) ;     
    }
};