/*
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

 

Example 1:



Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
 

Constraints:

The number of nodes in the tree is between 1 and 10^4.
The tree nodes will have distinct values between 1 and 10^5.


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
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        TreeNode* res = buildTree(0, value.size()-1);
        return res;
    }
private:
    vector<int> value;
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        value.push_back(root->val);
        inorder(root->right);
    }
    TreeNode* buildTree(int start, int end) {
        if (start > end)
            return NULL;
        int mid = (start+end)/2;
        TreeNode *root = new TreeNode(value[mid]);
        root->left = buildTree(start, mid-1);
        root->right = buildTree(mid+1, end);
        return root;
    }
};
