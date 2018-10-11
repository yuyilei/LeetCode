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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& in, int inS, int inE, vector<int>& post, int poS, int poE) {
        if ( inS > inE || poS > poE )
            return NULL;
        TreeNode* root = new TreeNode(post[poE]);
        int flag = 0;
        for ( ; flag + inS <= inE ; flag++ ) {
            if ( in[flag+inS] == post[poE] )
                break;
        }
        root->left = buildTree(in,inS,inS+flag-1,post,poS,poS+flag-1);
        root->right = buildTree(in,inS+flag+1,inE,post,poS+flag,poE-1);
        return root;
    }
};
