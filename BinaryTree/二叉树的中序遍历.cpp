/*
给定一个二叉树，返回它的中序 遍历。
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
// 迭代法：
// 对于任一结点，优先访问其左孩子，而左孩子结点又可以看做一根结点，
// 然后继续访问其左孩子结点，直到遇到左孩子结点为空的结点才进行访问，当前节点，然后再访问当前节点的右孩子
//
// 先把root设为当前节点now，
// 1. 如果当前节点有左孩子，当前节点now入栈，把当前节点的左孩子设为当前节点
// 2. 取栈顶元素，存入res，把栈顶节点的右孩子设为当前节点。
//
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if ( !root )
            return res;
        stack<TreeNode *> s;
        TreeNode* now = root;
        while ( now || !s.empty() ) {
            while ( now ) {
                s.push(now);
                now = now->left;
            }
            TreeNode* top = s.top();
            s.pop();
            res.push_back(top->val);
            now = top->right;
        }
        return res;
    }
};
