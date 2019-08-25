/*
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）



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
    vector<int> findMode(TreeNode* root) {
        if (!root)
            return {};
        inorder(root);
        vector<int> res;
        for (map<int, int>::iterator it = counter.begin(); it != counter.end(); it++) {
            if (it->second == max_count) {
                res.push_back(it->first);
            }
        }
        return res;
    }
private:
    map<int, int> counter;
    int max_count = 0;
    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        counter[root->val]++;
        max_count = max(max_count, counter[root->val]);
        inorder(root->right);
    }
};



// 法二：
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
    vector<int> findMode(TreeNode* root) {
        if (!root)
            return {};
        TreeNode* pre = NULL;
        int curCount = 1, maxCount = 0;
        vector<int> res;
        inorder(root, pre, curCount, maxCount, res);
        return res;
    }
private:
    void inorder(TreeNode* root, TreeNode *&pre, int &curCount, int &maxCount, vector<int>& res) {
        if (!root)
            return;
        inorder(root->left, pre, curCount, maxCount, res);
        if (pre)
            curCount = (pre->val == root->val) ? curCount+1 : 1;
        if (curCount == maxCount) {
            res.push_back(root->val);
        }
        else if (curCount > maxCount) {
            res.clear();
            res.push_back(root->val);
            maxCount = curCount;
        }
        pre = root;
        inorder(root->right, pre, curCount, maxCount, res);
    }
};
