/*
Given a m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:
1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
Notice that there could be some invalid signs on the cells of the grid which points outside the grid.

You will initially start at the upper left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path doesn't have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.

 

Example 1:


Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
The total cost = 3.
Example 2:


Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
Output: 0
Explanation: You can follow the path from (0, 0) to (2, 2).
Example 3:


Input: grid = [[1,2],[4,3]]
Output: 1
Example 4:

Input: grid = [[2,2,2],[2,2,2]]
Output: 3
Example 5:

Input: grid = [[4]]
Output: 0
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100

*/

// Dijkstra
// 求单源最短路径，其中不能有负节点

typedef pair<int,int> pi;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dis (m, vector<int> (n, INT_MAX));
        dis[0][0] = 0;
        vector<bool> vis(m*n, false);
        int step[2][5] = {{0, 0, 0, 1, -1}, {0, 1, -1, 0, 0}};
        priority_queue<pi, vector<pi>, greater<pi>> q;
        // first：到达这一点需要变化的次数，second：这一点的位置 (x*n+y)
        // 优先队列，先变化次数排序
        q.push({0, 0});
        while (!q.empty()) {
            pi now = q.top();
            q.pop();
            if (vis[now.second]) {
                continue;
            }
            vis[now.second] = true;
            int x = now.second / n;
            int y = now.second % n;
            for (int i = 1; i <= 4; i++) {
                int tx = x + step[0][i];
                int ty = y + step[1][i];
                if (tx >= m || tx < 0 || ty >= n || ty < 0)
                    continue;
                int td = now.first + (grid[x][y] == i ? 0 : 1);
                if (td < dis[tx][ty]) {
                    dis[tx][ty] = td;
                    q.push({td, tx*n+ty});
                }
            }
        }
        return dis[m-1][n-1];
    }
};



// bfs

typedef pair<int,int> pi;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dis (m, vector<int> (n, INT_MAX));
        dis[0][0] = 0;
        int step[2][5] = {{0, 0, 0, 1, -1}, {0, 1, -1, 0, 0}};
        queue<pi> q;
        q.push({0,0});
        while (!q.empty()) {
            pi now = q.front();
            q.pop();
            int x = now.first;
            int y = now.second;
            for (int i = 1; i <= 4; i++) {
                int tx = x + step[0][i];
                int ty = y + step[1][i];
                if (tx >= m || tx < 0 || ty >= n || ty < 0) {
                    continue;
                }
                int td = dis[x][y] + (grid[x][y] == i ? 0 : 1);
                // 只要能更新当前点的权重，就重新加入queue
                if (td < dis[tx][ty]) {
                    dis[tx][ty] = td;
                    q.push({tx, ty});
                }
            }
        }
        return dis[m-1][n-1];
    }
};


// 0-1 bfs

typedef pair<int,int> pi;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<bool> vis(m*n, false);
        int step[2][5] = {{0, 0, 0, 1, -1}, {0, 1, -1, 0, 0}};
        deque<pi> q;
        q.push_front({0,0});
        // first: 变化的次数 second：x*n+y
        // 维持队列头部是变化最小的节点
        while (!q.empty()) {
            pi now = q.front();
            q.pop_front();
            if (vis[now.second]) {
                continue;
            }
            vis[now.second] = true;
            int x = now.second / n;
            int y = now.second % n;
            if (x == m-1 && y == n-1)
                return now.first;
            for (int i = 1; i <= 4; i++) {
                int tx = x + step[0][i];
                int ty = y + step[1][i];
                if (tx >= m || tx < 0 || ty >= n || ty < 0) {
                    continue;
                }
                if (grid[x][y] == i) {  // 不用变化就可以到达下一点，加入队列头部
                    q.push_front({now.first, tx*n+ty});
                }
                else {                  // 新节点需要变化，放入队列尾部
                    q.push_back({now.first+1, tx*n+ty});
                }
            }
        }
        return 0;
    }
};


