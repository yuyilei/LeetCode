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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if ( !root ) 
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while ( !q.empty() ) {
            int len = q.size(); 
            int maxx = q.front()->val;
            for ( int i = 0 ; i < len ; i++ ) {
                auto t = q.front();
                q.pop();
                maxx = max(maxx,t->val);
                if ( t->left ) 
                    q.push(t->left);
                if ( t->right ) 
                    q.push(t->right);
            }
            res.push_back(maxx);
        }
        return res;
    }
}; 