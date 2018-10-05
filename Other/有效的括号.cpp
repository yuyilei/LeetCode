/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for ( char c : s ) {
            if ( c == '(' || c == '[' || c == '{' ) {
                ss.push(c);
            }
            if ( c == ')' ) {
                if ( ss.empty() || ss.top() != '(' )
                    return false;
                ss.pop();
            }
            if ( c == ']' ) {
                if ( ss.empty() || ss.top() != '[' )
                    return false;
                ss.pop();
            }
            if ( c == '}' ) {
                if ( ss.empty() || ss.top() != '{' )
                    return false;
                ss.pop();
            }
        }

        return ss.empty() ? true : false;
    }
};
