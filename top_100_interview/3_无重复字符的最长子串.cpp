/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

*/

// 保证start 到 i 的子串没有重复
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        map<char,int> index;
        int res = 1;
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            if (index.find(s[i]) != index.end());
                start = max(start, index[s[i]]);
            res = max(res, i-start+1);
            index[s[i]] = i+1;
        }
        return res;
    }
};
