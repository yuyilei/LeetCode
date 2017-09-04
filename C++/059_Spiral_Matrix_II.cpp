class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res (n , vector<int> (n) ) ; 
        int i = 0 , j = 0 , all = 1 , maxx = n*n; 
        while( all <= maxx ){
            for ( ; j < n ; j++ ){
                if ( res[i][j] != 0 ) {
                    break ; 
                }
                res[i][j] = all++ ; 
            } 
            j-- ; 
            i++ ; 
            for ( ; i < n ; i++ ){
                if ( res[i][j] != 0 )
                    break ; 
                res[i][j] = all++ ; 
            } 
            i-- ; 
            j-- ;
            for  ( ; j >= 0 ; j-- ){
                if ( res[i][j] != 0 )
                    break ; 
                res[i][j] = all++ ; 
            }
            j++ ; 
            i-- ; 
            for ( ; i >= 0 ; i-- ){
                if ( res[i][j] !=  0 )
                    break ; 
                res[i][j] = all++ ; 
            }
            j++ ; 
            i++ ; 
        }  
        return res ; 
    }
};