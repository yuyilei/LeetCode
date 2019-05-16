/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。

示例:

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
*/


// 快慢指针
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right = 0;
        int len = nums.size();
        int minlen = len + 1;
        int tmp_sum = 0;
        while ( right < len ) {
            if ( tmp_sum < s ) {
                tmp_sum += nums[right];
                right++;
            }
            while ( tmp_sum >= s ) {
                minlen = min(minlen, right-left);
                tmp_sum -= nums[left];
                left++;
            }
        }
        return (minlen > len) ? 0 : minlen;
    }
};
