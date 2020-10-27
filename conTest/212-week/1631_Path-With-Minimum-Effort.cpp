/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.
 

Constraints:

rows == heights.length
columns == heights[i].length
1 <= rows, columns <= 100
1 <= heights[i][j] <= 106

*/

/*
 * dp + bfs 剪枝
 * dp[x][y] 表示到达(x, y)处的最短消耗路径
 */

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> dp (rows, vector<int> (cols, INT_MAX));
        dp[0][0] = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            for (int i = 0; i < 4; i++) {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 0 || tx >= rows || ty < 0 || ty >= cols) {
                    continue;
                }
                int diff = abs(heights[x][y] - heights[tx][ty]);        // 从(x, y)到(tx, ty)需要的消耗
                int tmp = max(dp[x][y], diff);                          // 从(0, 0)到(tx, ty)并且经过(x, y)需要的消耗
                if (tmp >= dp[tx][ty]) {                                // 如果这条路径的消耗比原有的大，那就不选择它，剪枝
                    continue;
                }
                dp[tx][ty] = tmp;
                q.push({tx, ty});
            }
        }
        return dp[rows-1][cols-1];
    }
};



// 二分法 + dfs

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        int left = 0, right = 1e6;
        int res = 0;
        while (left < right) {
            int mid = (left + right) / 2;
            vector<vector<bool>> vis (rows, vector<bool> (cols, false));
            if (dfs(heights, vis, 0, 0, mid)) {        //  此时,[left, mid] 内的值都有可能
                right = mid;
            }
            else {                                     // 此时,[mid+1, right] 内的值都有可能
                left = mid + 1;
            }
        }
        return left;
    }
private:
    bool dfs(vector<vector<int>> &heights, vector<vector<bool>> &vis, int x, int y, int d) {
        vis[x][y] = true;
        int rows = heights.size();
        int cols = heights[0].size();
        if (x == rows-1 && y == cols-1) {
            return true;
        }
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx < 0 || tx >= rows || ty < 0 || ty >= cols || vis[tx][ty]) {
                continue;
            }
            if (abs(heights[x][y] - heights[tx][ty]) <= d) {
                if (dfs(heights, vis, tx, ty, d))
                    return true;
            }

        }
        return false;
    }
};
