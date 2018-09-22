/*
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col (9,vector<bool> (10,false));
        vector<vector<bool>> row (9,vector<bool> (10,false));
        vector<vector<bool>> grid (9,vector<bool> (10,false));
        for ( int i = 0 ; i < 9 ; i++ ) {
            for ( int j = 0 ; j < 9 ; j++ ) {
                if ( board[i][j] == '.' ) 
                    continue;
                int num = board[i][j] - '0';
                if ( col[i][num] || row[j][num] || grid[3*(i/3)+j/3][num] ) {
                    return false;
                } 
                col[i][num] = row[j][num] = grid[3*(i/3)+j/3][num] = true;
            }
        }
        return true;
    }
}; 