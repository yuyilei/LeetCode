/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // 非递归法，使用的是层次遍历，遍历每一层，直到遇到叶子节点，返回当前的层数 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if ( !root )
            return 0 ;
        queue<TreeNode *> tmp ;
        tmp.push(root) ; 
        int deep = 1 ;
        while ( !tmp.empty() ) {
            int all = tmp.size() ; 
            while ( all > 0 ) {
                TreeNode * t = tmp.front() ; 
                tmp.pop() ; 
                if ( t->left ) tmp.push(t->left) ;
                if ( t->right ) tmp.push(t->right) ; 
                if ( !(t->left) && !( t->right) ) return deep ; 
                all-- ; 
            } 
            deep++ ; 
        }
    } 
};


// 递归法 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if ( !root ) 
            return 0 ; 
        if ( !(root->left) ) 
            return 1 + minDepth(root->right) ; 
        if ( !(root->right) ) 
            return 1 + minDepth(root->left) ; 
        return 1 + min( minDepth(root->left), minDepth(root->right)) ; 
    }
};