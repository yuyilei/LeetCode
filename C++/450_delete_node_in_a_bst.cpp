/*
在一个平衡树中删除一个节点，分为四种情况：
1. 被删除的节点没有左右孩子，即为叶子节点，直接将当前节点设为NULL
2. 被删除的节点只有左孩子，用左孩子代替当前节点
3. 被删除的节点只有右孩子，用右孩子代替当前节点
4. 被删除的节点既有左孩子又有右孩子，选择当前节点右子树中最小的节点（后继节点），用后继节点代替当前节点 
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if ( !root )
            return NULL;
        if ( root->val > key ) {                      // key 在左子树中
            root->left = deleteNode(root->left,key); 
        }
        else if ( root->val < key ) {                 // key 在右子树中
            root->right = deleteNode(root->right,key); 
        }
        else {                                        // 当前节点为 key 
            if ( !root->left ) {                      // 只有右子树
                root = root->right; 
            }
            else if ( !root->right ) {                // 只有左子树
                root = root->left; 
            }
            else {                                    // 左右子树都有 
                int minchild = 0;
                root->right = deleteMin(root->right,minchild); 
                root->val = minchild;
            }
        }
        return root; 
    }
    TreeNode* deleteMin(TreeNode* root, int &minchild) {
        if ( !root ) 
            return NULL;
        if ( !root->left ) {
            minchild = root->val;
            return root->right; 
        }
        root->left = deleteMin(root->left,minchild);
        return root;
    }
};