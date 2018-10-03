/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
*/
// 思路：我们考虑在i处时，题中要求是连续子数组，因此只有两种选择，一种将nums[i]加入到已选定的子数组中，一种是放弃前面的子数组，从nums[i]开始重新记录子数组。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = INT_MIN;
        for ( int num : nums ) {
            int tmp = max(sum+num,num);          // tmp表示包括当前最后一位的的连续子数组的最大和
            res = max(res,tmp);
            sum = tmp;                            
        }
        return res;
    }
};