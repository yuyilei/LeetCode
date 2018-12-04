/*
给定一个未经排序的整数数组，找到最长且连续的的递增序列。

示例 1:

输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。
示例 2:

输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。
注意：数组长度不会超过10000。
*/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        int res = 1;
        int left = 0, right = 1;
        while ( right < nums.size() ) {
            while ( right < nums.size() && nums[right-1] < nums[right] ) {
                right++;
            }
            res = max(res,right-left);
            left = right;
            right++;
        }
        return res;
    }
};
