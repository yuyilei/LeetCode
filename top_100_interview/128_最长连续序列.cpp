/*
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。


*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, bool> help;
        for (int num: nums) {
            help[num] = true;
        }
        int res = 0;
        for (int num: nums) {
            if (help[num]) {
                help[num] = false;
                int tmp = 1;
                for (int i = num-1; ; i--) {
                    if (help.find(i) == help.end() || help[i] == false)
                        break;
                    help[i] = false;
                    tmp++;
                }
                for (int i = num+1; ; i++) {
                    if (help.find(i) == help.end() || help[i] == false)
                        break;
                    help[i] = false;
                    tmp++;
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};
