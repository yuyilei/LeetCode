/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 */


// 法一：
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 如果root等于p，q任意一个的话，直接返回p，q，否则，在左右子树中查找，
// 如果一个节点出现在左子树，另一个节点出现在右子树，说明root是公共根
// 否则，如果两个节点都出现在左子树，则左子树是根，同理，右子树。
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( !root || root->val == p->val || root->val == q->val )
            return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if ( left && right )
            return root;
        return ( left ) ? left : right;
    }
};


//法二：
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 先将从根节点到当前p或q节点的路径求出，最后一个公共节点就是最近公共祖先
class Solution {
public:
    void preorder(vector<TreeNode*>& tmp, vector<TreeNode*>& res, TreeNode* root, TreeNode* now, bool &finish) {
        if ( !root || finish ) // 搜索已经结束
            return;
        tmp.push_back(root);
        if ( root == now ) {  // 当前root是要找的那个节点，结束搜索
            finish = true;
            res = tmp;
        }
        // 搜索左右子树
        preorder(tmp,res,root->left,now,finish);
        preorder(tmp,res,root->right,now,finish);
        tmp.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> tmp, pt, qt;
        bool finish = false;
        preorder(tmp,pt,root,p,finish);
        tmp.clear(); finish = false;
        preorder(tmp,qt,root,q,finish);
        int len = min(pt.size(),qt.size());
        TreeNode* res = NULL;
        for ( int i = 0 ; i < len ; i++ ) {
            if ( pt[i] != qt[i] )
                break;
            res = pt[i];
        }
        return res;
    }
};
