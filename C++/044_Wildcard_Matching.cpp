/*
动态规划
参照第10题
'?' 可以匹配任何单个字符。
'*' 可以匹配任意字符串（包括空字符串）。
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length(); 
        vector<vector<bool> > dp (m+1, vector<bool> (n+1,false));
        dp[0][0] = true; 
        for ( int i = 0 ; i <= m ; i++ ){
            for ( int j = 1 ; j <= n ; j++ ){
                if ( p[j-1] == '*' ) {
                    int t = i; 
                    while ( t >= 0 && !dp[i][j] ){
                        if ( dp[t][j-1] )
                            dp[i][j] = true;
                        t--; 
                    }
                }
                else {
                    dp[i][j] = ( i > 0 ) && ( dp[i-1][j-1] ) && ( s[i-1] == p[j-1] || p[j-1] == '?'); 
                }
            }
        }
        return dp[m][n]; 
    }
};