/*
给定一个二叉树（具有根结点 root）， 一个目标结点 target ，和一个整数值 K 。
返回到目标结点 target 距离为 K 的所有结点的值的列表。 答案可以以任何顺序返回。

本质是图的广度优先搜索，但是树是单向的，所以先找出每个节点的父节点，然后进行广度优先遍历 
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
    map<TreeNode*, TreeNode*> parent; 
    //set<TreeNode*> visited;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        findParent(root); 
        vector<int> res;
        bfs(target,K,res); 
        return res;
    }
    void findParent(TreeNode* root) {
        if ( !root ) return;
        if ( root->left ) {
            parent[root->left] = root;
            findParent(root->left); 
        }
        if ( root->right ) {
            parent[root->right] = root; 
            findParent(root->right); 
        }
    }
    void bfs(TreeNode* now, int K, vector<int> &res) {
        queue<TreeNode*> q;
        q.push(now); 
        set<TreeNode*> vis;
        while ( K >= 0 && !q.empty() ) {
            if ( K == 0 ) {
                while ( !q.empty() ) {
                    TreeNode* t = q.front(); 
                    q.pop();
                    res.push_back(t->val); 
                }
            }
            K--;
            int len = q.size();
            for ( int i = 0 ; i < len ; i++ ) {
                TreeNode* t = q.front();
                vis.insert(t);
                q.pop();
                if ( t->left && !vis.count(t->left) ) q.push(t->left);
                if ( t->right && !vis.count(t->right) ) q.push(t->right);
                if ( parent[t] && !vis.count(parent[t]) ) q.push(parent[t]); 
            }
        } 
    }
};