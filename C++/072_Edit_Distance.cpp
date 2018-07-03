/*
动态规划 
replace: dp[i - 1][j - 1] + 1 //保留从word1[0 ... i-1]转变到word2[0 ... j-1]的次数，再加一，加一指的是本次的修改，如果word1[i-1]==word2[j-1] 就不需要加一
insert: dp[i][j - 1] + 1 // 保留从word1[0 ... i]转变到word2[0 ... j-1]的次数，加一
delete: dp[i - 1][j] + 1// 保留从word1[0 ... i-1]转变到word2[0 ... j]的次数，加一
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        int i, j; 
        vector<vector<int>> dp (m+1, vector<int> (n+1,0)) ;
        for ( i = 0 ; i <= m ; i++ ) dp[i][0] = i;
        for ( j = 0 ; j <= n ; j++ ) dp[0][j] = j;
        for ( i = 1 ; i <= m ; i++ ){
            for ( j = 1 ; j <= n ; j++ ){
                int tmp_min = min(dp[i-1][j]+1,dp[i][j-1]+1);
                if ( word1[i-1] == word2[j-1] )
                    dp[i][j] = min(dp[i-1][j-1],tmp_min);
                else
                    dp[i][j] = min(dp[i-1][j-1]+1,tmp_min);
            }
        }
        return dp[m][n];
    }
};