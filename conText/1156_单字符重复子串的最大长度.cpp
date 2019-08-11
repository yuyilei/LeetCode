/*
如果字符串中的所有字符都相同，那么这个字符串是单字符重复的字符串。

给你一个字符串 text，你只能交换其中两个字符一次或者什么都不做，然后得到一些单字符重复的子串。返回其中最长的子串的长度。



示例 1：

输入：text = "ababa"
输出：3
示例 2：

输入：text = "aaabaaa"
输出：6
示例 3：

输入：text = "aaabbaaa"
输出：4
示例 4：

输入：text = "aaaaa"
输出：5
示例 5：

输入：text = "abcdef"
输出：1

*/

class Solution {
public:
    int maxRepOpt1(string text) {
        if (text.empty())
            return 0;
        int res = 1;
        int start = 0;
        vector<vector<int>> sub;
        for (int i = 1; i <= text.size(); i++) {
            if (i == text.size() || text[i-1] != text[i]) {
                sub.push_back({start, i-start});
                res = max(res, i-start);
                start = i;
            }
        }
        for (int i = 0; i < sub.size(); i++) {
            int s = sub[i][0];
            int len = sub[i][1];
            if (s + len >= text.size())
                break;
            int count = rangeCount(text, text[s], s, s+len-1);
            if (count >= 1)
                res = max(res, len+1);
            if (i + 2 < sub.size() && sub[i+1][1] == 1 && text[sub[i+2][0]] == text[s]) {
                int count = rangeCount(text, text[s], s, sub[i+2][0]+sub[i+2][1]-2);
                if (count == 1)
                    res = max(res, len+sub[i+2][1]);
                else
                    res = max(res, len+sub[i+2][1]+1);
            }
        }
        return res;
    }
private:
    int rangeCount(string &text, char t, int s, int e) {
        int res = 0;
        for (int i = 0; i < s && res <= 1; i++) {
            if (text[i] == t)
                res++;
        }
        for (int i = e+1; i < text.size() && res <= 1; i++) {
            if (text[i] == t)
                res++;
        }
        return res;
    }
};
