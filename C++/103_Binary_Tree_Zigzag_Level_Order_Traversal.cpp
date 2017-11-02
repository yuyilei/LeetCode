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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res ; 
        if ( !root ) return res ; 
        queue<TreeNode *> tmp ; 
        tmp.push(root) ; 
        int flag = 0 ; 
        while ( !tmp.empty() ){
            int len = tmp.size() ; 
            vector<int> t ; 
            for ( int i = 0 ; i < len ; i++ ){
                TreeNode *s = tmp.front() ; 
                tmp.pop() ; 
                if ( s->left ) tmp.push(s->left) ; 
                if ( s->right ) tmp.push(s->right) ; 
                t.push_back(s->val) ; 
            } 
            if ( flag % 2 ) reverse(t.begin(),t.end()) ; 
            flag++ ; 
            res.push_back(t) ; 
        }
        return res ; 
    }
};