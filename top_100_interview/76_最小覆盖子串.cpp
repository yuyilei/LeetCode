/*
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。

*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return "";
        map<char, int> dict;
        map<char, int> window;
        for (char c: t) {
            dict[c]++;
        }
        int need = dict.size();
        int ans[2] = {-1,-1};
        int left = 0, right = 0;
        while (right < s.size()) {
            window[s[right]]++;
            if (dict.find(s[right]) != dict.end() && dict[s[right]] == window[s[right]]) {
                need--;
            }
            while (need == 0 && left <= right) {
                char cur = s[left];
                if (ans[0] == -1 || ans[0] > right-left+1) {
                    ans[0] = right-left+1;
                    ans[1] = left;
                }
                window[cur]--;
                if (dict.find(cur) != dict.end() && dict[cur] > window[cur]) {
                    need++;
                }
                left++;
            }
            right++;
        }
        return (ans[0] == -1) ? "" : s.substr(ans[1], ans[0]);
    }
};
