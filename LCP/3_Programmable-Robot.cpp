/*
力扣团队买了一个可编程机器人，机器人初始位置在原点(0, 0)。小伙伴事先给机器人输入一串指令command，机器人就会无限循环这条指令的步骤进行移动。指令有两种：

U: 向y轴正方向移动一格
R: 向x轴正方向移动一格。
不幸的是，在 xy 平面上还有一些障碍物，他们的坐标用obstacles表示。机器人一旦碰到障碍物就会被损毁。

给定终点坐标(x, y)，返回机器人能否完好地到达终点。如果能，返回true；否则返回false。

 

示例 1：

输入：command = "URR", obstacles = [], x = 3, y = 2
输出：true
解释：U(0, 1) -> R(1, 1) -> R(2, 1) -> U(2, 2) -> R(3, 2)。
示例 2：

输入：command = "URR", obstacles = [[2, 2]], x = 3, y = 2
输出：false
解释：机器人在到达终点前会碰到(2, 2)的障碍物。
示例 3：

输入：command = "URR", obstacles = [[4, 2]], x = 3, y = 2
输出：true
解释：到达终点后，再碰到障碍物也不影响返回结果。
 

限制：

2 <= command的长度 <= 1000
command由U，R构成，且至少有一个U，至少有一个R
0 <= x <= 1e9, 0 <= y <= 1e9
0 <= obstacles的长度 <= 1000
obstacles[i]不为原点或者终点

*/


/*
 * 记录一个command周期中，机器人可能为经过的点，记为vis
 * 已知机器人在第一次循环中走过的所有点vis，和向右移动的总距离r，和向上移动的总距离u
 * 从原点到某一个点(tx, ty)需要多少个循环： circle = min(tx/r, ty/u)
 * canVisit函数：对于某一个点(tx, ty)，找出其在第一个循环中对应的点，检查它是否会被经过
 * 1. 检查(x, y) 的 canVisit
 * 2. 检查obstacles中所有可能的点的canVisit
 */

class Solution {
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int len = command.size();
        vector<vector<bool>> vis (len+1, vector<bool> (len+1));
        int tx = 0, ty = 0;
        for (char c: command) {
            vis[tx][ty] = true;
            if (c == 'U') {
                u++;
                ty++;
            }
            else {
                r++;
                tx++;
            }
        }
        if (!canVisit(vis, x, y))
            return false;
        for (vector<int> o: obstacles) {
            if (o[0] <= x && o[1] <= y) {
                if (canVisit(vis, o[0], o[1]))
                    return false;
            }
        }
        return true;
    }
private:
    int u = 0, r = 0;
    bool canVisit(vector<vector<bool>> &vis, int tx, int ty) {
        int circle = min(tx/r, ty/u);
        tx -= circle*r;
        ty -= circle*u;
        if (tx > r || ty > u)
            return false;
        if (!vis[tx][ty])
            return false;
        return true;
    }
};
