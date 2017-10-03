class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0 , last = -1 ; // last是上一个没被匹配的右括号的下标 
        stack<int> tmp ; 
        for ( int i = 0 ; i < s.length() ; i++ ){
            if ( s[i] == '(' ) 
                tmp.push(i) ; 
            else { 
                if ( tmp.empty() ) 
                    last = i ; 
                else {
                    tmp.pop() ;   // 消去一对括号
                    if ( tmp.empty() )  
                        res = max(res,i - last) ; 
                    else 
                        res = max(res,i - tmp.top()) ; 
                }
            }
        }
        return res ; 
    }
};