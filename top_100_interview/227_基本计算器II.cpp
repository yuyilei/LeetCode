/*
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

示例 1:

输入: "3+2*2"
输出: 7
示例 2:

输入: " 3/2 "
输出: 1
示例 3:

输入: " 3+5 / 2 "
输出: 5
说明：

你可以假设所给定的表达式都是有效的。
请不要使用内置的库函数 eval。


*/
class Solution {
public:
    int calculate(string s) {
        if (s.empty())
            return 0;
        stack<int> nums;
        char sign = '+';
        int cur = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                cur = cur*10 + (s[i]-'0');
            }
            if ((s[i] < '0'&&s[i] != ' ')|| i == len-1) {
                if (sign == '+') {
                    nums.push(cur);
                }
                else if (sign == '-') {
                    nums.push(-cur);
                }
                else {
                    int top = nums.top();
                    nums.pop();
                    if (sign == '/')
                        nums.push(top/cur);
                    else if (sign == '*')
                        nums.push(top*cur);
                }
                cur = 0;
                sign = s[i];
            }
        }
        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};

