/*
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

示例:

输入: [5,2,6,1]
输出: [2,1,1,0]
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.

*/


class Solution {
public:
    struct TreeNode {
        TreeNode* left;
        TreeNode* right;
        int val;
        int count;
        TreeNode(int v): val(v), count(0), left(NULL), right(NULL) {}
    };
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return res;
        res.resize(nums.size());
        TreeNode* root = NULL;
        for (int i = nums.size()-1; i >= 0; i--) {
            root = BuildTree(nums, i, root);
        }
        return res;
    }
private:
    vector<int> res;
    TreeNode* BuildTree(vector<int>& nums, int index, TreeNode* root) {
        if (!root) {
            root = new TreeNode(nums[index]);
            return root;
        }
        if (root->val >= nums[index]) {
            root->count++;
            root->left = BuildTree(nums, index, root->left);
        }
        else {
            res[index] += root->count+1;
            root->right = BuildTree(nums, index, root->right);
        }
        return root;
    }
};


