/*
给定一个字符串，找出不含有重复字符的最长子串的长度。
*/

// 思路:
// 维持一个滑动窗口
// left表示当前子串(子串中没有重复字符)的最左边字符的位置，tmp数组中保存遇到每个字符最后一次出现的位置（所以每次都要更新）
// 遍历字符串，每次遇到一个字符，如果在字符串中没出现过（tmp[s[i]] == 0）或者在子串中没有出现过（ tmps[i] < left），就可能要更新res
// 否则，就更新left（因为出现重复字符，子串的左边需要更新）
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int tmp[256] = {0};
        int left = 0, res = 0;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( tmp[s[i]] == 0 || tmp[s[i]] < left ) {
                res = max(res,i-left+1);
            }
            else {
                left = tmp[s[i]];
            }
            tmp[s[i]] = i + 1;
        }
        return res;
    }
};
