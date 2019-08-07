/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

*/

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
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
private:
    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie) {
        if (ps > pe)
            return NULL;
        TreeNode* root = new TreeNode(preorder[ps]);
        int index = is;
        for (; index <= ie; index++ ) {
            if (inorder[index] == preorder[ps])
                break;
        }
        int left_num = index - is;
        root->left = build(preorder, ps+1, ps+left_num, inorder, is, is+left_num-1);
        root->right = build(preorder, ps+left_num+1, pe, inorder, is+left_num+1, ie);
        return root;
    }
};
