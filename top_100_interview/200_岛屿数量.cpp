/*
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3

*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    DFS(grid, i, j);
                }
            }
        }
        return res;
    }
private:
    void DFS(vector<vector<char>> &grid, int x, int y) {
        grid[x][y] = '0';
        int m = grid.size();
        int n = grid[0].size();
        int move[2][4] = {{1,-1,0,0}, {0,0,1,-1}};
        for (int i = 0; i < 4; i++) {
            int tx = x + move[0][i];
            int ty = y + move[1][i];
            if (tx >= 0 && tx < m && ty >= 0 && ty < n && grid[tx][ty] == '1') {
                DFS(grid, tx, ty);
            }
        }
    }
};
