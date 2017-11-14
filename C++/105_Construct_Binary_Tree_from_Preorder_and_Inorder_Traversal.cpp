/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归法: 
class Solution {
public:
    map<int,int> res ;  
    TreeNode* getroot(vector<int>pre,int pS, int pE, vector<int> in, int iS, int iE){
        if ( pS > pE || iS > iE ) return NULL ; 
        int rootval = pre[pS] ;  // 根节点是当前先序遍历数组中的第一个节点。 
        int rootindex = res[rootval] ;  // 根结点在中序遍历数组中将左右两边分为左右子树 
        TreeNode* root = new TreeNode(rootval) ; 
        int len = rootindex - iS ; 
        root->left = getroot(pre,pS+1,pS+len,in,iS,rootindex-1) ; 
        root->right = getroot(pre,pS+len+1,pE,in,rootindex+1,iE) ; 
        return root ; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
        for ( int i = 0 ; i < inorder.size() ; i++ ) 
            res[inorder[i]] = i ; 
        return getroot(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1) ; 
    }
};