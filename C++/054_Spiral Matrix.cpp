class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) { 
        vector<int> res ; 
        if ( matrix.size() == 0 ) 
            return  res ;  
        int i = 0 , j = 0 , m = matrix.size() , n = matrix[0].size() , sum = 0 ;  
        vector<vector<int> > tmp (m,vector<int>(n,0)) ;  // 借助辅助空间tmp来标记是否以被输出 
        while ( sum < m * n ) {
            for ( ; j < n && tmp[i][j] == 0 ; j++ , sum++  ) { 
                res.push_back(matrix[i][j]) ; 
                tmp[i][j] = 1 ; 
            } 
            j-- ; 
            i++ ; 
            for ( ; i < m && tmp[i][j] == 0 ; i++ , sum++ ) {
                res.push_back(matrix[i][j]) ; 
                tmp[i][j] = 1 ; 
            } 
            i-- ; 
            j-- ; 
            for ( ; j >= 0 && tmp[i][j] == 0 ; j-- , sum++ ) { 
                res.push_back(matrix[i][j]) ;
                tmp[i][j] = 1 ; 
            } 
            j++ ; 
            i-- ; 
            for ( ; i >= 0 && tmp[i][j] == 0 ; i-- , sum++ ) {
                res.push_back(matrix[i][j]) ; 
                tmp[i][j] = 1 ;
            } 
            i++ ; 
            j++ ; 
        } 
        return res ; 
    }
};