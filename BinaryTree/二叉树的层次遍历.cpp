/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if ( !root )
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while ( !q.empty() ) {
            int len = q.size();
            vector<int> each;
            for ( int i = 0 ; i < len ; i++ ) {
                TreeNode* now = q.front();
                q.pop();
                each.push_back(now->val);
                if ( now->left ) q.push(now->left);
                if ( now->right ) q.push(now->right);
            }
            res.push_back(each);
        }
        return res;
    }
};
