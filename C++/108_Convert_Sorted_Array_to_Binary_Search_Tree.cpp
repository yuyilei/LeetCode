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
        return createBST(nums,0,nums.size()-1) ; 
    }
    TreeNode *createBST(vector<int>nums, int s, int e){
        if ( s > e ) return NULL ; 
        int mid = ( s + e ) / 2 ; 
        TreeNode *root = new TreeNode(nums[mid]) ;  
        root->left = createBST(nums,s,mid-1) ; 
        root->right = createBST(nums,mid+1,e) ; 
        return root ; 
    }
};