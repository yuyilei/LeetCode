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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res ; 
        if ( !root ) return res ; 
        queue<TreeNode*> q ; 
        q.push(root) ; 
        while ( !q.empty() ){
            int len = q.size() ; 
            for ( int i = 0 ; i < len ; i++ ) {
                TreeNode* tmp = q.front() ; 
                q.pop() ;
                if ( tmp->left ) 
                    q.push(tmp->left) ; 
                if ( tmp->right ) 
                    q.push(tmp->right) ; 
                if ( i == len-1 ) 
                    res.push_back(tmp->val) ; 
            }
        } 
        return res ; 
    }
};