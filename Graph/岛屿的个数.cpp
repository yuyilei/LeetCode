/*
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。
*/

class Solution {
public:
    void bfs(vector<vector<char>> &grid, int x, int y) {
        int change[2][4] = {{-1,1,0,0},{0,0,1,-1}};
        int row = grid.size(), col = grid[0].size();
        for ( int i = 0 ; i < 4 ; i++ ) {
            int tx = x + change[0][i], ty = y + change[1][i];
            if ( tx < 0 || tx >= row || ty < 0 || ty >= col || grid[tx][ty] == '0')
                continue;
            grid[tx][ty] = '0';
            bfs(grid,tx,ty);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if ( grid.empty() || grid[0].empty() )
            return 0;
        int row = grid.size(), col = grid[0].size();
        int res = 0;
        for ( int i = 0 ; i < row ; i++ ) {
            for ( int j = 0 ; j < col ; j++ ) {
                if ( grid[i][j] == '0' )
                    continue;
                res++;
                bfs(grid,i,j);
            }
        }
        return res;
    }
};
