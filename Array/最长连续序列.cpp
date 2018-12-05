/*

给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/

// 使用 set，遍历set中的元素，向两边扩散
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        set<int> s(nums.begin(),nums.end());
        for ( int num : nums ) {
            if ( s.find(num) == s.end() )
                continue;
            int pre = num - 1, last = num;
            while ( s.count(pre) != 0 ) {
                s.erase(pre--);
            }
            while ( s.count(last) != 0 ) {
                s.erase(last++);
            }
            res = max(res,last-pre-1);
        }
        return res;
    }
};
