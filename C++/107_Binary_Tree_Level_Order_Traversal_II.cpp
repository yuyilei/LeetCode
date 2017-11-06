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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res ; 
        if ( !root ) return res ; 
        queue<TreeNode *> q ; 
        q.push(root) ; 
        while (!q.empty()){
            int len = q.size() ; 
            vector<int> tmp ; 
            for ( int i = 0 ; i < len ; i++ ){
                TreeNode *t = q.front() ; 
                q.pop() ; 
                tmp.push_back(t->val) ; 
                if ( t->left ) q.push(t->left) ; 
                if ( t->right ) q.push(t->right) ; 
            }
            res.push_back(tmp) ; 
        } 
        reverse(res.begin(),res.end()) ; 
        return res ; 
    }
};