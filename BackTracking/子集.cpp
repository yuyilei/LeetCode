/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

// 思路：先在res放一个空集;
// 遍历nums，对于nums中的每个元素，遍历res中的全部集合，在集合中加入nums的当前元素，再把集合加入res
// 做法像树的层次遍历
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res (1,vector<int>(0));
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            int len = res.size();
            for ( int j = 0 ; j < len ; j++ ) {
                vector<int> tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
