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
    vector<int> sorted; 
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root);
        return sorted[k-1];
    }
    void inOrder(TreeNode* root) {
        if ( root->left ) {
            inOrder(root->left);
        }
        sorted.push_back(root->val); 
        if ( root->right ) {
            inOrder(root->right); 
        }
    }
};