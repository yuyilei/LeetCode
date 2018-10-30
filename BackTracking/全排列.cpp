/*

给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if ( nums.empty() )
            return res;
        permutation(nums,0);
        return res;
    }
private:
    vector<vector<int>> res;
    void swap(vector<int>& nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    void permutation(vector<int>& nums, int index) {
        if ( index == nums.size() ) {
            res.push_back(nums);
            return;
        }
        for ( int i = index ; i < nums.size() ; i++ ) {
            swap(nums,index,i);
            permutation(nums,index+1);
            swap(nums,index,i);
        }
    }
};
