/*
给定一个整数矩阵，找出最长递增路径的长度。

对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。

示例 1:

输入: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
输出: 4
解释: 最长递增路径为 [1, 2, 6, 9]。
示例 2:

输入: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
输出: 4
解释: 最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。

*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<node> allNode;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                struct node n = node(i, j, matrix[i][j]);
                allNode.push_back(n);
            }
        }
        sort(allNode.begin(), allNode.end(), cmp);
        int res = 1;
        vector<vector<int>> dp (row, vector<int> (col, 1));
        int move[2][4] = {{-1,1,0,0},{0,0,-1,1}};
        for (struct node n: allNode) {
            int tmp = -1;
            for (int i = 0; i < 4; i++) {
                int tx = n.x + move[0][i];
                int ty = n.y + move[1][i];
                if (tx < 0 || tx >= row || ty < 0 || ty >= col)
                    continue;
                if (matrix[tx][ty] < matrix[n.x][n.y]) {
                    tmp = max(tmp, dp[tx][ty]);
                }
            }
            if (tmp != -1) {
                dp[n.x][n.y] = tmp+1;
                res = max(res, dp[n.x][n.y]);
            }
        }
        return res;
    }
private:
    struct node {
        int x;
        int y;
        int val;
        node(int a, int b, int c): x(a), y(b), val(c) {}
    };
    static bool cmp(const node &n1, const node &n2) {
        return n1.val < n2.val;
    }
};

