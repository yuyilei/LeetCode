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
    void flatten(TreeNode* root) {
        vector<int> tmp ; 
        if ( !root ) return ; 
        gettmp(tmp,root) ; 
        for ( int i = 0 ; i < tmp.size() ; i++ ){
            root->val = tmp[i] ; 
            if (root->left) root->left = NULL ; 
            if (!root->right && i != tmp.size()-1 ) root->right = new TreeNode(0) ;  
            root = root->right ; 
        }
    } 
    void gettmp(vector<int> &tmp, TreeNode *root){
        if ( root ) tmp.push_back(root->val) ; 
        if ( root->left) gettmp(tmp,root->left) ; 
        if ( root->right ) gettmp(tmp,root->right) ;  
    }
};