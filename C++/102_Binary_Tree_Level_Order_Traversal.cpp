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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res  ;
        if (!root) return res ; 
        queue<TreeNode *> q ; 
        q.push(root) ; 
        while ( !q.empty() ){
            int len = q.size() ; 
            vector<int> t ; 
            for ( int i = 0 ; i < len ; i++ ){
                TreeNode *tmp = q.front() ; 
                q.pop() ; 
                if ( tmp ) t.push_back(tmp->val) ; 
                if ( tmp && tmp->left ) q.push(tmp->left) ;
                if ( tmp && tmp->right ) q.push(tmp->right) ; 
            }
            res.push_back(t) ; 
        }
        return res ; 
    }
};