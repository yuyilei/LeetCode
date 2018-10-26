/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
*/

// tmp[i] 表示 以 nums[i]结尾的最长上升子序列长度
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        int len = nums.size();
        int res = 1;
        vector<int> tmp (len,1);
        for ( int i = 1 ; i < len ; i++ ) {
            for ( int j = i - 1 ; j >= 0 ; j-- ) {
                if ( nums[j] < nums[i] ) {
                    tmp[i] = max(tmp[i],tmp[j] + 1);
                }
            }
        }
        for ( int t : tmp )
            res = max(res,t);
        return res;
    }
};
