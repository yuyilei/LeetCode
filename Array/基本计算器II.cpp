/*
实现一个基本的计算器来计算一个简单的字符串表达式的值。

字符串表达式仅包含非负整数，+， - ，*，/ 四种运算符和空格  。 整数除法仅保留整数部分。

示例 1:

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
        if ( s.empty() )
            return 0;
        int res = 0, num = 0;
        char op = '+';
        stack<int> st;
        s = s + "+"; // 加一个  +  是为了把最后一个数也算进去 
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] >= '0' && s[i] <= '9' )
                num = num * 10 + (s[i] - '0');
            else if ( s[i] != ' ' || i == s.size()-1 ) {
                if ( op == '+' )
                    st.push(num);
                else if ( op == '-' )
                    st.push(-num);
                else if ( op == '*' || op == '/' ) {
                    int tmp = st.top();
                    st.pop();
                    tmp = (op == '*') ? tmp * num : tmp / num;
                    st.push(tmp);
                }
                num = 0;
                op = s[i];
            }
        }
        while ( !st.empty() ) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};
