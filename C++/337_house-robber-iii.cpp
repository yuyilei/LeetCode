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
    int rob(TreeNode* root){
        if ( !root ) 
            return 0;
        int childsum = rob(root->left) + rob(root->right);
        int grandchildsum = 0;
        if ( root->left ) 
            grandchildsum += rob(root->left->left) + rob(root->left->right);
        if ( root->right )
            grandchildsum += rob(root->right->left) + rob(root->right->right);
        return max(childsum,grandchildsum+root->val);
    }
}; 