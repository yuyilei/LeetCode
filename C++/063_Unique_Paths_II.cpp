class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size() , n = obs[0].size() , i , j , k ; 
        if ( m == 1 && n == 1 && obs[0][0] == 0 )
            return  1 ; 
        vector<vector<int> > way (m, vector<int> (n,0)) ; 
        if  ( obs[0][0] == 0 )
            way[0][0] = 1 ; 
        for ( i = 1 ; i < n ; i++ ){
            if ( way[0][i-1] == 1 && obs[0][i] == 0 && obs[0][i-1] == 0 ) {
                way[0][i] = 1 ; 
            }
        } 
        for ( i = 1 ; i < m ; i++ ) {
            if ( way[i-1][0] == 1 && obs[i][0] == 0 && obs[i-1][0] == 0 ) { 
                way[i][0] = 1 ; 
            }
        } 
        for ( i = 1 ; i < m ; i++ ) {
            for ( j = 1 ; j < n ; j++ ) {
                if ( obs[i-1][j] == 0 && obs[i][j] == 0 ) {
                    way[i][j] += way[i-1][j] ; 
                }
                if ( obs[i][j-1] == 0 && obs[i][j] == 0 ) { 
                    way[i][j] += way[i][j-1] ; 
                }
            }
        }
        return way[m-1][n-1] ; 
    }
};