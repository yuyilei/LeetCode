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
    TreeNode* prev, * miss1, * miss2 ; 
    void recoverTree(TreeNode* root) {
        if ( !root ) return ; 
        getmiss(root) ;
        swap(miss1->val,miss2->val) ;
    }
    void getmiss(TreeNode* root) {
        if ( root->left )  
            getmiss(root->left) ; 
        if ( prev && prev->val > root->val ) {
            if ( !miss1 ) {
                miss1 = prev ; 
                miss2 = root ; 
            }
            else 
                miss2 = root ; 
        }
        prev = root ; 
        if ( root->right ) 
            getmiss(root->right) ; 
    }
};