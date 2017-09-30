class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) { 
        int m = grid.size() , n = grid[0].size() , i , j , k ; 
        vector<vector<int> > res (m,vector<int> (n,0)) ; 
        res[0][0] = grid[0][0] ; 
        for ( i = 1 ; i < m ; i ++ ) 
            res[i][0] = res[i-1][0] + grid[i][0] ; 
        for ( i = 1 ; i < n ; i ++ )
            res[0][i] = res[0][i-1] + grid[0][i] ; 
        for ( i = 1 ; i < m ; i++ ){
            for ( j = 1 ; j < n ; j++ ){ 
                k = min(res[i-1][j],res[i][j-1]) ;
                res[i][j] = k + grid[i][j] ; 
            }
        }
        return res[m-1][n-1] ; 
    }
};