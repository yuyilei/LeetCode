class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for ( int i = 0 ; i < 9 ; i++ ){
            vector<int> flag (10,0) ; 
            for ( int j = 0 ; j < 9 ; j++ ){
                if ( board[i][j] == '.' )
                    continue ;
                int tmp = board[i][j] - '0'  ; 
                if ( flag[tmp] ) 
                    return false ; 
                flag[tmp] = 1 ; 
            }
        }
        cout << endl ; 
        for ( int j = 0 ; j < 9 ; j++ ){
            vector<int> flag (10,0) ; 
            for ( int i = 0 ; i < 9 ; i++ ){
                if ( board[i][j] == '.' )
                    continue ; 
                int tmp = board[i][j] - '0' ; 
                if ( flag[tmp] )   
                    return false ; 
                flag[tmp] = 1 ; 
            }
        }
        for ( int i = 0 ; i < 3 ; i++ ){
            for ( int j = 0 ; j < 3 ; j++ ){
                vector<int> flag (10,0) ; 
                for ( int p = i*3 ; p < i*3+3 ; p++ ){
                    for ( int q = j*3 ; q < j*3+3 ; q++ ){ 
                        if ( board[p][q] == '.')
                            continue ; 
                        int tmp = board[p][q] - '0' ; 
                        if ( flag[tmp] ) 
                            return false ;
                        flag[tmp] = 1; 
                    }
                }
            }
        }
        return true ; 
    }
};