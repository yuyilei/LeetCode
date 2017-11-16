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
    int pathSum(TreeNode* root, int sum) {
        if ( !root ) return 0 ; 
        return dfs(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum) ; // 路径数量等于（当前跟节点的深度遍历）+左子树的中满足数量+右子树中满足的数量 
    } 
    int dfs(TreeNode* root, int sum){ // 深度遍历，就是查找从当前跟节点开始，所有路径之和加起来为sum的数量 
        if ( !root ) 
            return 0 ;
        int res ; 
        if ( sum == root->val ) //  当前节点等于sum，属于一种情况
            res++ ; 
        res += dfs(root->left,sum-root->val) ; //   从左子树中找
        res += dfs(root->right,sum-root->val) ; //  从右子树中找 
        return res ; 
    }
};