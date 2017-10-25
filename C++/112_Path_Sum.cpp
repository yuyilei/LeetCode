/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  递归法
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if ( root == NULL ) 
            return false ; 
        if ( root->left == NULL && root->right == NULL ) 
            return sum == root->val ; 
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val) ; // 这里用或是因为只要有一个满足就行 
    } 
};