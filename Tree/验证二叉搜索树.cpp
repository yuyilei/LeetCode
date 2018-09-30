/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
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
    vector<int> temp;
    bool isValidBST(TreeNode* root) {
        if ( !root )
            return true;
        inorder(root);
        for ( int i = 0 ; i < temp.size() - 1 ; i++ ) 
            if ( temp[i] >= temp[i+1] ) 
                return false;
        return true;
    }
    void inorder(TreeNode* root) {
        if ( root->left ) 
            inorder(root->left);
        temp.push_back(root->val);
        if ( root->right ) 
            inorder(root->right);
    }
};