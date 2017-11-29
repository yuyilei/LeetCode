/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 以每个节点为根节点，获得这个节点左右两边的单边最长路径，将当前节点的值，和左右节点的最长路径相加，最后获得当前节点为根节点的最长路径，再与全局变量 res相比较。 
class Solution {
public:
    int res = INT_MIN ; 
    int maxPathSum(TreeNode* root){
        getres(root) ; 
        return res ; 
    }
    int getres(TreeNode* root) { 
        int lmax = 0, rmax = 0 ; 
        if ( root->left ) lmax = getres(root->left) ;    // 当前节点的左边最长的一条单向路径 
        if ( root->right ) rmax = getres(root->right) ;   // 当前节点右边的最长的一条单向路径 
        int now = root->val + ((lmax>0)?lmax:0) + ((rmax>0)?rmax:0) ;  // 获取以当前节点为跟节点的最长路径 
        res = max(res,now) ;                                           // 与全局变量相比较 
        return root->val + max((lmax>0)?lmax:0,(rmax>0)?rmax:0) ;       // 只加一边，（这就是获取单向路径的关键）
    } 
};