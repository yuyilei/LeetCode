/*
给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:

输入: [1,2,3]
输出: 6
示例 2:

输入: [1,2,3,4]
输出: 24
注意:

给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。

*/

// 先排序
// 三个数的最大乘积只有两种情况：
// 1. 最后三个数的乘积
// 2. 前两个数与最后一个数的乘积（有两个及两个以上的负数）
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int flag = 0;
        int len = nums.size();
        int res = nums[len-3]*nums[len-2]*nums[len-1];
        res = max(res, nums[0]*nums[1]*nums[len-1]);
        return res;
    }
};
