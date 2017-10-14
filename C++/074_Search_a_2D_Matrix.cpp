// 解法一： 把二维数组看成一维数组 
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if ( matrix.empty() || matrix[0].empty() ) 
            return false ; 
        int rows = matrix.size() , cols = matrix[0].size() , mid ;
        int l = 0 , r = rows*cols -1 ; 
        while ( l <= r ) {
            mid = l + ( r - l ) / 2  ; 
            int row = mid / cols, col = mid % cols ; 
            if ( matrix[row][col] == target ) 
                return true ; 
            if ( matrix[row][col] > target ) 
                r = mid - 1 ; 
            else 
                l = mid + 1 ; 
        } 
        return false ; 
    }
}; 

// 解法二：从右上角那个点开始
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if ( matrix.empty() || matrix[0].empty() )  
            return false ; 
        int row = 0 , col = matrix[0].size() - 1 ; 
        while ( row < matrix.size() && col >= 0  ){
            if ( matrix[row][col] == target ) 
                return true ; 
            if ( matrix[row][col] < target )
                 row++ ;    
            else 
                 col-- ;                 
        }
        return false ; 
    }
};