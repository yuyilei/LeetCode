// 从左下角开始查找 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.empty() || matrix[0].empty() ) 
            return false ; 
        int row = matrix.size() - 1 , col = 0 ; 
        while ( row >= 0 && col < matrix[0].size() ) {
            if ( matrix[row][col] == target ) 
                return true ; 
            if ( matrix[row][col] > target ) 
                row-- ; 
            else 
                col++ ; 
        }
        return false ; 
    }
};