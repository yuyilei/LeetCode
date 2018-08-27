/*
DP + DFS 
*/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if ( matrix.size() == 0 || matrix[0].size() == 0 ) 
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp (row,vector<int>(col,0)); 
        for ( int i = 0 ; i < row ; i++ ) {
            for ( int j = 0 ; j < col ; j++ ) {
                res = max(res,dfs(i,j,matrix,dp)); 
            }
        }
        return res;
    }
    
    int dfs(int n, int m, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
        if ( dp[n][m] != 0 ) 
            return dp[n][m]; 
        int dir[2][4] = {{1,-1,0,0},{0,0,1,-1}};
        int res = 1;
        for ( int i = 0 ; i < 4 ; i++ ) {
            int tn = dir[0][i] + n;
            int tm = dir[1][i] + m;
            if ( tn < 0 || tn >= matrix.size() 
              || tm < 0 || tm >= matrix[0].size() 
              || matrix[tn][tm] <= matrix[n][m] ) {
                continue;
            }
            int len = 1 + dfs(tn,tm,matrix,dp);
            res = max(res,len);
        }
        dp[n][m] = res;
        return res;
    }
}; 