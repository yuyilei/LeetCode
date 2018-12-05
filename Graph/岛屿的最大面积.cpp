/*
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if ( grid.empty() || grid[0].empty() )
            return 0;
        int res = 0;
        int len1 = grid.size(), len2 = grid[0].size();
        for ( int i = 0 ; i < len1 ; i++ ) {
            for ( int j = 0 ; j < len2 ; j++ ) {
                if ( grid[i][j] == 1 ) {
                    int tmp = shrink(grid,i,j);
                    res = max(res,tmp);
                }
            }
        }
        return res;
    }
private:
    int shrink(vector<vector<int>>& grid, int x, int y) {
        int res = 1;
        grid[x][y] = 0;
        int move[2][4] = {{-1,1,0,0},{0,0,-1,1}};
        for ( int i = 0 ; i < 4 ; i++ ) {
            int tmpx = x + move[0][i];
            int tmpy = y + move[1][i];
            if ( tmpx < 0 || tmpx >= grid.size() || tmpy < 0 || tmpy >= grid[0].size() )
                continue;
            if ( grid[tmpx][tmpy] == 1 ) {
                res += shrink(grid,tmpx,tmpy);
            }
        }
        return res;
    }
};
