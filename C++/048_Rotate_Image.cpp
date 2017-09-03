// 沿着中轴竖线对称，再沿着对角线对称 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size() , i , tmp , j ;
        for ( i = 0 ; i < len ; i++ ){
            for ( j = 0 ; j < len / 2 ; j++ ){
                tmp = matrix[i][j] ; 
                matrix[i][j] = matrix[i][len-1-j] ;
                matrix[i][len-1-j] = tmp ; 
            }
        }
        for ( i = 0 ; i < len - 1 ; i++ ){
            for ( j = 0 ; i + j < len - 1 ; j++ ) {
                tmp = matrix[i][j] ; 
                matrix[i][j] = matrix[len-1-j][len-1-i] ; 
                matrix[len-1-j][len-1-i] = tmp ; 
            }
        }
    }
};
