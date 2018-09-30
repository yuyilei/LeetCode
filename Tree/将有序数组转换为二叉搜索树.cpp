/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if ( nums.empty() ) 
            return NULL;
        int root_index = nums.size()/2;
        TreeNode* root = new TreeNode(nums[root_index]);
        vector<int>left = partnums(0,root_index-1,nums);
        vector<int>right = partnums(root_index+1,nums.size()-1,nums);
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
    vector<int> partnums(int a, int b, vector<int> nums) {
        vector<int> res;
        for ( int i = a ; i <= b ; i++ ) {
            res.push_back(nums[i]);
        }
        return res;
    }
};

// 或。。。 

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = Sort(0,nums.size()-1,nums);
        return root;
    }
    TreeNode* Sort(int low, int high, vector<int> nums) {
        if ( low > high ) 
            return NULL;
        int mid = (low + high)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = Sort(low,mid-1,nums);
        root->right = Sort(mid+1,high,nums);
        return root;
    }
};