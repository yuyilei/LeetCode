/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
说明: 叶子节点是指没有子节点的节点。
*/

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
    bool hasPathSum(TreeNode* root, int sum) {
        if ( !root )
            return false;
        if ( !root->left && !root->right ) {
            return root->val == sum;
        }
        bool l = hasPathSum(root->left,sum-root->val);
        bool r = hasPathSum(root->right,sum-root->val);
        return l || r;
    }
};
