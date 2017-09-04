// 对空间复杂度有要求，就把这一行是否有0存在第一行和第一列  
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1 ; 
        for ( int i = 0 ; i < matrix.size() ; i++ ){
            if ( matrix[i][0] == 0 ) 
                col0 = 0 ; 
            for ( int j = 1 ; j < matrix[i].size() ; j++ ){
                if ( matrix[i][j] == 0 ){
                    matrix[i][0] = matrix[0][j] = 0 ; 
                }
            }
        }
        for ( int i = matrix.size() - 1 ; i >= 0 ; i-- ) {
            for ( int j = 1 ; j < matrix[i].size() ; j++ ){
                if ( matrix[i][0] == 0 || matrix[0][j] == 0 ){
                    matrix[i][j] = 0 ; 
                }
            }
            if ( col0 == 0 ) 
                matrix[i][0] = 0 ; 
        }
    }
};