/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

*/

// 递归
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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return isSame(root->left, root->right);
    }
private:
    bool isSame(TreeNode* l, TreeNode* r) {
        if (!l && !r)
            return true;
        if (!l || !r)
            return false;
        if (l->val != r->val)
            return false;
        return isSame(l->left, r->right) && isSame(l->right, r->left);
    }
};



// 迭代
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
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<TreeNode*> now;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur) {
                    q.push(cur->left);
                    q.push(cur->right);
                }
                now.push_back(cur);
            }
            int left = 0;
            int right = now.size()-1;
            for (; left < right ; left++, right--) {
                if (!now[left] && !now[right])
                    continue;
                if (!now[left] || !now[right])
                    return false;
                if (now[left]->val != now[right]->val)
                    return false;
            }
        }
        return true;
    }
};

