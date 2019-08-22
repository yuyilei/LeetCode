/*
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

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
    int maxPathSum(TreeNode* root) {
        helper(root);
        return res_max;
    }
private:
    int res_max = INT_MIN;
    int helper(TreeNode* root) {
        if (!root)
            return 0;
        int left_sum = helper(root->left);
        int right_sum = helper(root->right);
        int max_sum = max(left_sum, right_sum);
        int res = root->val;
        if (max_sum > 0)
            res += max_sum;
        int tmp_res = root->val;
        if (left_sum > 0)
            tmp_res += left_sum;
        if (right_sum > 0)
            tmp_res += right_sum;
        res_max = max(res_max, tmp_res);
        return res;
    }
};
