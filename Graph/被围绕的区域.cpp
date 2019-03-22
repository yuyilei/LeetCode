/*
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X
解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
*/

// 遍历边界的点，将与边界的O相邻的O都做上标记，其余的点都是X 
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if ( board.empty() || board[0].empty() )
            return;
        int m = board.size(), n = board[0].size();
        for ( int i = 0 ; i < m ; i++ ) {
            DFS(board, i, 0);
            DFS(board, i, n-1);
        }
        for ( int i = 0 ; i < n ; i++ ) {
            DFS(board, 0, i);
            DFS(board, m-1, i);
        }
        for ( int i = 0 ; i < m ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                if ( board[i][j] == 'O' )
                    board[i][j] = 'X';
                else if ( board[i][j] == 'Y' )
                    board[i][j] = 'O';
            }
        }
    }
private:
    void DFS(vector<vector<char>> &board, int x, int y) {
        int m = board.size(), n = board[0].size();
        if ( x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O' )
            return;
        board[x][y] = 'Y';
        DFS(board, x+1, y);
        DFS(board, x-1, y);
        DFS(board, x, y+1);
        DFS(board, x, y-1);
    }
};
