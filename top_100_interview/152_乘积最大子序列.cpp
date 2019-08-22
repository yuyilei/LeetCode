/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return -1;
        int maxx = nums[0];
        int minn = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int tmax = maxx, tmin = minn;
            minn = min(nums[i], min(tmax*nums[i], tmin*nums[i]));
            maxx = max(nums[i], max(tmax*nums[i], tmin*nums[i]));
            res = max(res, maxx);
        }
        return res;
    }
};
