// 解数独

// 递归法： 
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0) ; 
    }
    bool check(vector<vector<char>> &board, int x, int y) {                      // 限制函数，检查行，列，以及3*3 的块 
        for ( int i = 0 ; i < 9 ; i++ ) {
            if ( i != y && board[x][i] != '.' && board[x][i] == board[x][y] ) 
                return false ; 
        } 
        for ( int i = 0 ; i < 9 ; i++ ) {
            if ( i != x && board[i][y] != '.' && board[i][y] == board[x][y] ) 
                return false ; 
        }
        for ( int i = x/3*3 ; i < x/3*3+3 ; i++ ) {
            for ( int j = y/3*3 ; j < y/3*3+3 ; j++ ) {
                if ( i != x && j != y && board[i][j] != '.' && board[i][j] == board[x][y])
                    return false ; 
             }
        }
        return true ;
    } 
    bool solve(vector<vector<char>>& board, int count) { 
        if ( count == 81 )                                              // 本质上，所有的true都是从这里返回的 
            return true ;  
        int x = count / 9 ; 
        int y = count % 9 ; 
        if ( board[x][y] == '.' ) {                                     // 如果这个格子未填入，就尝试填入
            for ( int i = 1 ; i < 10 ; i++ ) {
                board[x][y] = '0' + i ; 
                if ( check(board,x,y) ) {                               // 检查约束条件
                    if( solve(board,count+1) )
                        return true ; 
                } 
            }
            board[x][y] = '.' ; 
        }
        else {
            if (solve(board,count+1) )
                return true ; 
        }
        return false ;
    }   
};