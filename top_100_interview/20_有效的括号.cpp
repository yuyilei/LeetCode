/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true


*/

class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
            return true;
        map<char, int> m = {{'[', 1}, {'{', 2}, {'(', 3}, {')', 4}, {'}', 5}, {']', 6}};
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] <= 3 && m[s[i]] >= 1) {
                st.push(s[i]);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if (m[top] + m[s[i]] != 7) {
                    return false;
                }
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};
