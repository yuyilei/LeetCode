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

// 最大乘积可能是正数乘以正数，或负数乘以负数，所以要保留最大值和最小值
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if ( nums.size() == 1 )
            return nums[0];
        int len = nums.size();
        vector<int> maxx (len, 0);
        vector<int> minn (len, 0);
        maxx[0] = nums[0]; minn[0] = nums[0];
        int res = nums[0];
        for ( int i = 1 ; i < len ; i++ ) {
            maxx[i] = max(max(maxx[i-1]*nums[i], minn[i-1]*nums[i]), nums[i]);
            minn[i] = min(min(maxx[i-1]*nums[i], minn[i-1]*nums[i]), nums[i]);
            res = max(res, maxx[i]);
        }
        return res;
    }
};
