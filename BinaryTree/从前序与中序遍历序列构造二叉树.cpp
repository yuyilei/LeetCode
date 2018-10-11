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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& pre, int preS, int preE, vector<int>& in, int inS, int inE) {
        if ( preS > preE || inS > inE )
            return NULL;
        TreeNode* root = new TreeNode(pre[preS]);
        int flag = 0;
        for ( ; flag + inS <= inE ; flag++ ) {
            if ( in[flag+inS] == pre[preS] )
                break;
        }
        root->left = buildTree(pre,preS+1,preS+flag,in,inS,inS+flag-1);
        root->right = buildTree(pre,preS+flag+1,preE,in,inS+flag+1,inE);
        return root;
    }
};
