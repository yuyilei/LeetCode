/*
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1:
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2:
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return matrix;
        queue<pair<int,int>> q;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 0) {
                    q.push({i,j});
                }
                else {
                    matrix[i][j] = INT_MAX;
                }
            }
        }
        int move[2][4] = {{0,0,-1,1},{-1,1,0,0}};
        while  (!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            for (int j = 0; j < 4; j++) {
                int tr = cur.first + move[0][j];
                int tc = cur.second + move[1][j];
                if (tr >= 0 && tr < row &&
                    tc >= 0 && tc < col &&
                    matrix[tr][tc] > matrix[cur.first][cur.second]+1) {
                    matrix[tr][tc] = matrix[cur.first][cur.second]+1;
                    q.push({tr,tc});
                }
            }
         }
        return matrix;
    }
};
