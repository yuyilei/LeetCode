/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> helper;          // 用于记录从第一项开始累计和的个数
        helper[0] = 1;
        int sum = 0, res = 0;
        int len = nums.size();
        for ( int i = 0 ; i < len ; i++ ) {
            sum += nums[i];
            if ( helper.find(sum-k) != helper.end() )      // 其实就是 0到第t项的和为sum-k, 0到第n项的和为sum，所以 t+1到n的和为k
                res += helper[sum-k];
            helper[sum]++;
        }
        return res;
    }
};
