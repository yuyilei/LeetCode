/*
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

*/

class Solution {
public:
    string decodeString(string s) {
        if (s.empty())
            return "";
        stack<string> store;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            string cur = s.substr(i, 1);
            if (cur == "]") {
                string encode = "";
                while (store.top() != "[") {
                    encode = store.top() + encode;
                    store.pop();
                }
                store.pop();
                string countstr = "";
                while (!store.empty() && store.top()[0] >= '0' && store.top()[0] <= '9') {
                    countstr = store.top() + countstr;
                    store.pop();
                }
                int count = stoi(countstr);
                string tmp = "";
                for (int i = 0; i < count; i++) {
                    tmp += encode;
                }
                store.push(tmp);
            }
            else {
                store.push(cur);
            }
        }
        string res = "";
        while (!store.empty()) {
            res = store.top() + res;
            store.pop();
        }
        return res;
    }
};
