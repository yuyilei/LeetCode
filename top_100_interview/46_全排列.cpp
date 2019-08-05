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
        vector<vector<int>> res;
        helper(res, 0, nums);
        return res;
    }
private:
    void helper(vector<vector<int>> &res, int index, vector<int> &nums) {
        if (index == nums.size()) {
            res.push_back(nums);
        }
        else {
            for (int i = index; i < nums.size(); i++) {
                swap(nums[index], nums[i]);
                helper(res, index+1, nums);
                swap(nums[index], nums[i]);  // 防止重复
            }
        }
    }
};
