/*
给定一个二叉树

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

说明:

你只能使用额外常数空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
示例:

给定二叉树，

     1
   /  \
  2    3
 / \    \
4   5    7
调用你的函数后，该二叉树变为：

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if ( !root )
            return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while ( !q.empty() ) {
            int len = q.size();
            TreeLinkNode* now = q.front();
            q.pop();
            for ( int i = 0 ; i < len ; i++ ) {
                if ( now->left )
                    q.push(now->left);
                if ( now->right )
                    q.push(now->right);
                if ( i != len - 1 ) {
                    now->next = q.front();
                    now = q.front();
                    q.pop();
                }
            }
        }
    }
};
