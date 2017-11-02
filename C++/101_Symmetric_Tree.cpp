/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 要么root节点为NULL,要么调用test函数
// test函数中，要么两个节点全为空，要么全不为空，却节点中的值相等，再比较节点的孩子 
class Solution {
public:
    bool testSysmmetric(TreeNode* l, TreeNode* r){
        if ( !l && !r )  return true ;
        return l && r && (l->val == r->val ) && testSysmmetric(l->left,r->right) && testSysmmetric(l->right,r->left) ; 
    }
    bool isSymmetric(TreeNode* root){
        return !root || testSysmmetric(root->left,root->right) ; 
    }
};