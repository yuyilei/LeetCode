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
    map<int,int> tmp ; 
    TreeNode* getroot(vector<int>in,int iS, int iE, vector<int> post, int pS, int pE){
        if ( iS > iE || pS > pE ) return NULL ; 
        int rootval = post[pE] ; 
        int rootindex = tmp[rootval] ; 
        int len = iE - rootindex ; 
        TreeNode* root = new TreeNode(rootval) ; 
        root->left = getroot(in,iS,rootindex-1,post,pS,pE-len-1) ; 
        root->right = getroot(in,rootindex+1,iE,post,pE-len,pE-1) ; 
        return root ; 
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for ( int i = 0 ; i < inorder.size() ; i++ )
            tmp[inorder[i]] = i ; 
        return getroot(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1) ; 
    }
};