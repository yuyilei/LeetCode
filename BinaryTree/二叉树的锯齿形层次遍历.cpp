/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if ( !root )
            return res;
        queue<TreeNode *> q;
        q.push(root);
        int flag = 0;
        while ( !q.empty() ) {
            vector<int> tmp;
            int len = q.size();
            for ( int i = 0 ; i < len ; i++ ) {
                TreeNode* now = q.front();
                q.pop();
                tmp.push_back(now->val);
                if ( now->left ) q.push(now->left);
                if ( now->right ) q.push(now->right);
            }
            if ( flag )
                reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
            flag = !flag;
        }
        return res;
    }
};
