/*
动态规划 
'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length(); 
        vector<vector<bool> > dp (m+1, vector<bool> (n+1, false)); 
        dp[0][0] = true; 
        for ( int i = 0 ; i <= s.length() ; i++ ){
            for ( int j = 1 ; j <= p.length() ; j++ ){
                if ( p[j-1] == '*' ) 
                    dp[i][j] = ( dp[i][j-2] ) || ( i > 0 && dp[i-1][j] && ( p[j-2] == '.' || s[i-1] == p[j-2] ));
                else
                    dp[i][j] = ( i > 0 ) && ( dp[i-1][j-1]) && ( p[j-1] == '.' || p[j-1] == s[i-1] );  
            }
        }
        return dp[m][n];
    }
};