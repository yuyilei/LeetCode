/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], maxx = nums[0], minn = nums[0];
        for ( int i = 1 ; i < nums.size() ; i++ ) {
            int now = nums[i];
            int pre_max = maxx, pre_min = minn;
            maxx = max(now, max(pre_max*now, pre_min*now));
            minn = min(now, min(pre_max*now, pre_min*now));
            res = max(res, maxx);
        }
        return res;
    }
};
