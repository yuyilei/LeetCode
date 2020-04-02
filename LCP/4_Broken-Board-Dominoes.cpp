/*
你有一块棋盘，棋盘上有一些格子已经坏掉了。你还有无穷块大小为1 * 2的多米诺骨牌，你想把这些骨牌不重叠地覆盖在完好的格子上，请找出你最多能在棋盘上放多少块骨牌？这些骨牌可以横着或者竖着放。

 

输入：n, m代表棋盘的大小；broken是一个b * 2的二维数组，其中每个元素代表棋盘上每一个坏掉的格子的位置。

输出：一个整数，代表最多能在棋盘上放的骨牌数。

 

示例 1：

输入：n = 2, m = 3, broken = [[1, 0], [1, 1]]
输出：2
解释：我们最多可以放两块骨牌：[[0, 0], [0, 1]]以及[[0, 2], [1, 2]]。（见下图）


 

示例 2：

输入：n = 3, m = 3, broken = []
输出：4
解释：下图是其中一种可行的摆放方式


 

限制：

1 <= n <= 8
1 <= m <= 8
0 <= b <= n * m

*/


/*
 *  匈牙利算法
 * 将相邻的点分为两个阵营
 */

class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        n1 = n;
        m1 = m;
        match.resize(n*m, -1);
        brok.resize(n*m, false);
        for (vector<int> b: broken) {
            brok[b[0]*m+b[1]] = true;;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i+j) % 2 || brok[i*m+j])     // 只查找(i+j)%2 == 0 的点
                    continue;
                used = vector<bool> (n*m, false);
                if (dfs(i, j))
                    res++;
            }
        }
        return res;
    }
private:
    int n1 = 0, m1 = 0;
    vector<bool> used;
    vector<int> match;
    vector<int> brok;
    int move[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0}};
    bool dfs(int x, int y) {
        for (int i = 0; i < 4; i++) {
            int tx = x + move[0][i];
            int ty = y + move[1][i];
            int id = tx*m1 + ty;
            // 检查这个点是否在超出图的范围，且是否被检查过(used)，是否为坏点
            if (tx < 0 || tx >= n1 || ty < 0 || ty >= m1 || used[id] || brok[id])
                continue;
            used[id] = true;
            // 如果这个点还没被匹配过，或者匹配这个点的点能找到其他点
            if (match[id] == -1 || dfs(match[id]/m1, match[id]%m1)) {
                match[id] = x*m1 + y;
                return true;
            }
        }
        return false;
    }
};
