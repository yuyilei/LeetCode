/*
给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？
*/


// 思路：
// 将某行某列是否出现零，存储到对应的首行首列，最后遍历首行首列来决定某行后列要不要置为0
// 对于首行，首列，用两个布尔值来记录它本身是不是要置为0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if ( matrix.size() == 0 )
            return;
        bool firstcol = false, firstrow = false;
        for ( int i = 0 ; i < matrix.size() ; i++ ) {
            for ( int j = 0 ; j < matrix[0].size() ; j++ ) {
                if ( matrix[i][j] == 0 ) {
                    if ( i != 0 && j != 0 )
                        matrix[i][0] = matrix[0][j] = 0;
                    else {
                        firstrow = ( i == 0 ) ? true : firstrow;
                        firstcol = ( j == 0 ) ? true : firstcol;
                    }
                }
            }
        }
        for ( int i = 1 ; i < matrix.size() ; i++ ) {
            for ( int j = 1 ; j < matrix[0].size() ; j++ ) {
                if ( matrix[i][0] == 0 || matrix[0][j] == 0 )
                    matrix[i][j] = 0;
            }
        }
        for ( int j = 0 ; firstrow && j < matrix[0].size() ; j++ )
            matrix[0][j] = 0;
        for ( int i = 0 ; firstcol && i < matrix.size() ; i++ )
            matrix[i][0] = 0;
    }
};
