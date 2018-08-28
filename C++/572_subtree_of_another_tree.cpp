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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if ( !s && !t ) 
            return true;
        if ( !s && t || s && !t ) 
            return false;
        return Sametree(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    bool Sametree(TreeNode* s, TreeNode *t) {
        if ( !s && !t ) 
            return true;
        if ( !s && t || s && !t ) 
            return false;
        if ( s->val == t->val && Sametree(s->left,t->left) && Sametree(s->right,t->right)) 
            return true;
        return false;
    }
};