/*
给定一个二叉树，返回它的 前序 遍历。
递归算法很简单，你可以通过迭代算法完成吗？
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
// 迭代法
// 先把当前的节点的值存入res，再分别将它的右孩子和左孩子存入stack中，注意是先右后左。
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if ( !root ) {
            return res;
        }
        stack<TreeNode *> s;
        s.push(root);
        while ( !s.empty() ) {
            TreeNode* now = s.top();
            s.pop();
            res.push_back(now->val);
            if ( now->right ) s.push(now->right);
            if ( now->left ) s.push(now->left);
        }
        return res;
    }
};
