/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]


*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        helper(s, 0, s.size()-1);
        return res;
    }
private:
    vector<vector<string>> res;
    vector<string> cur;
    void helper(string &s, int start, int end) {
        if (start >= s.size()) {
            res.push_back(cur);
        }
        else {
            for (int i = start; i <= end ; i++) {
                if (isVaild(s, start, i)) {
                    cur.push_back(s.substr(start, i-start+1));
                    helper(s, i+1, end);
                    cur.pop_back();
                }
            }
        }
    }
    bool isVaild(string &s, int start, int end) {
        if (start > end)
            return false;
        if (start == end)
            return true;
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};
