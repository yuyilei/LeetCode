/*
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if ( matrix.empty() || matrix[0].empty() )
            return 0;
        int len1 = matrix.size(), len2 = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp (len1,vector<int> (len2,0));
        for ( int i = 0 ; i < len1 ; i++ ) {
            for ( int j = 0 ; j < len2 ; j++ ) {
                if ( i == 0 || j == 0 ) {
                    if ( matrix[i][j] == '1' ) {
                        dp[i][j] = 1;
                    }
                }
                else {
                    if ( matrix[i][j] == '0' )
                        dp[i][j] = 0;
                    else {
                        dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
                    }
                }
                res = max(res,dp[i][j]);
            }
        }
        return res*res;
    }
};
