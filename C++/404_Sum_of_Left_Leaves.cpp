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
    int sumOfLeftLeaves(TreeNode* root) {
        if ( !root ) return 0 ; 
        int res = 0 ; 
        queue<TreeNode*> q ; 
        q.push(root) ; 
        while ( !q.empty() ) {
            int len = q.size() ; 
            for ( int i = 0 ; i < len ; i++ ){
                TreeNode* tmp = q.front() ; 
                q.pop() ;
                if ( tmp->left ) {
                    if ( !tmp->left->left && !tmp->left->right )
                        res += tmp->left->val ;
                    q.push(tmp->left) ; 
                } 
                if ( tmp->right ) 
                    q.push(tmp->right) ; 
            }
        }
        return res ; 
    }
};