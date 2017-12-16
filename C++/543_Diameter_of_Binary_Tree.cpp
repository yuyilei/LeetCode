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
    int diameterOfBinaryTree(TreeNode* root) {
        if ( !root ) return 0 ; 
        int res = 0 ; 
        getres(root,res) ; 
        return res - 1 ; 
    }
    int getres(TreeNode *root, int &res) {
        if ( !root ) return 0 ; 
        int deepL = getres(root->left,res) ; 
        int deepR = getres(root->right,res) ; 
        int tmp = deepL + deepR + 1 ; 
        res = max(res,tmp) ; 
        return max(deepL,deepR) + 1 ; 
    }
};