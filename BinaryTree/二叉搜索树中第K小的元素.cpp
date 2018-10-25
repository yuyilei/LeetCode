/*
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
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
    vector<int> sorted;
    int kthSmallest(TreeNode* root, int k) {
        sortTree(root);
        return sorted[k-1];
    }
    void sortTree(TreeNode *root) {
        if ( root->left )
            sortTree(root->left);
        sorted.push_back(root->val);
        if ( root->right )
            sortTree(root->right);
    }
};


// 迭代法
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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted;
        inorder(root,sorted);
        return sorted[k-1];
    }
    void inorder(TreeNode* root, vector<int> &sorted) {
        stack<TreeNode* > s;
        TreeNode* now = root;
        while ( now || !s.empty() ) {
            while ( now ) {
                s.push(now);
                now = now->left;
            }
            TreeNode* tmp = s.top();
            s.pop();
            sorted.push_back(tmp->val);
            now = tmp->right;
        }
    }
};
