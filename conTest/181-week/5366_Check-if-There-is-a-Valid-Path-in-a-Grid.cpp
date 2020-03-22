/*
Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.


You will initially start at the street of the upper-left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.

 

Example 1:


Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
Example 2:


Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
Example 3:

Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
Example 4:

Input: grid = [[1,1,1,1,1,1,3]]
Output: true
Example 5:

Input: grid = [[2],[2],[2],[2],[2],[2],[6]]
Output: true
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
1 <= grid[i][j] <= 6

*/

// 借鉴别人的代码
// dfs
// 0: 下， 1: 右， 2: 上，3: 左， -1:不能走
// 如 pipe[3][2]=3，代表三号拼图可以由向上的方向进入其中，并转向左方向继续前进。
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int start = grid[0][0];
        for (int i = 0; i < 4; i++) {
            if (pipe[start][i] != -1) {              // 注意，第一格是可以从任意方向进入的，4也是可以的
                if (dfs(grid, 0, 0, pipe[start][i]))   // pipe[start][i] 就是下一格进入的方向
                    return true;
            }
        }
        return false;
    }
private:
    int m, n;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int pipe[7][4] = {{-1,-1,-1,-1}, {-1, 1, -1, 3}, {0, -1, 2, -1}, {-1, 0, 3, -1}, {-1, -1, 1, 0}, {3, 2, -1, -1}, {1, -1, -1, 2}};
    bool dfs(vector<vector<int>> &grid, int x, int y, int cur) {
        if (x == m-1 && y == n-1)
            return true;
        int tx = x + dx[cur];             // 下一格的坐标
        int ty = y + dy[cur];
        if (tx < 0 || tx >= m || ty < 0 || ty >= n)   // 越界
            return false;
        int next = grid[tx][ty];
        if (pipe[next][cur] == -1)             // 能够从当前格进入下一格
            return false;
        return dfs(grid, tx, ty, pipe[next][cur]);
    }
};
