/*
给定一个二叉树，返回它的 后序 遍历。
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
// 先把根结点设为当前节点
// 1. 如果当前节点为叶子节点，或者上一个放入栈的节点是当前节点的孩子节点，就将当前元素存入res
// 2. 否则，就按照先右后左的顺序压入栈..
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if ( !root )
            return res;
        stack<TreeNode *> s;
        TreeNode* pre = NULL;
        s.push(root);
        while ( !s.empty() ) {
            TreeNode* now = s.top();
            if ( (!now->left && !now->right) ||
                ( pre && ( pre == now->left || pre == now->right) )) {
                s.pop();
                res.push_back(now->val);
                pre = now;
            }
            else {
                if ( now->right )
                    s.push(now->right);
                if ( now->left )
                    s.push(now->left);
            }
        }
        return res;
    }
};
