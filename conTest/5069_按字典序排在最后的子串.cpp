/*
给你一个字符串 s，找出它的所有子串并按字典序排列，返回排在最后的那个子串。



示例 1：

输入："abab"
输出："bab"
解释：我们可以找出 7 个子串 ["a", "ab", "aba", "abab", "b", "ba", "bab"]。按字典序排在最后的子串是 "bab"。
示例 2：

输入："leetcode"
输出："tcode"


提示：

1 <= s.length <= 10^5
s 仅含有小写英文字符。

*/

class Solution {
public:
    string lastSubstring(string s) {
        map<char, vector<int>> counter;
        char maxx = 'a';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > maxx)
                maxx = s[i];
            counter[s[i]].push_back(i);
        }
        int len = 1;
        vector<int> index = counter[maxx];
        if (index.size() == s.size())
            return s;
        queue<string> q;
        string res = "";
        int flag = 0;
        int res_index = -1;
        while (true) {
            for (int i = 0; i < index.size(); i++) {
                if (index[i] == -1)
                    continue;
                string sub = s.substr(index[i], len);
                if (res == "") {
                    res = sub;
                }
                if (flag >= index.size()-1) {
                    res_index = index[i];
                }
                if (res > sub) {
                    index[i] = -1;
                    flag++;
                }
                else {
                    res = sub;
                }
            }
            if (res_index != -1)
                break;
            len++;
        }
        int res_len = s.size()-res_index;
        return s.substr(res_index,res_len);
    }
};
