/*
1155. 掷骰子的N种方法  显示英文描述
用户通过次数 211
用户尝试次数 339
通过次数 215
提交次数 645
题目难度 Medium
这里有 d 个一样的骰子，每个骰子上都有 f 个面，分别标号为 1, 2, ..., f。

我们约定：掷骰子的得到总点数为各骰子面朝上的数字的总和。

如果需要掷出的总点数为 target，请你计算出有多少种不同的组合情况（所有的组合情况总共有 f^d 种），模 10^9 + 7 后返回。



示例 1：

输入：d = 1, f = 6, target = 3
输出：1
示例 2：

输入：d = 2, f = 6, target = 7
输出：6
示例 3：

输入：d = 2, f = 5, target = 10
输出：1
示例 4：

输入：d = 1, f = 2, target = 3
输出：0
示例 5：

输入：d = 30, f = 30, target = 500
输出：222616187


提示：

1 <= d, f <= 30
1 <= target <= 1000
*/

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        if (d*f < target)
            return 0;
        int row = d+1;
        int col = d*f+1;
        vector<vector<int>> dp (row, vector<int>(col, 0));
        long flag = 1000000007;
        for (int i = 1; i <= f; i++)
            dp[1][i] = 1;
        for (int i = 2; i <= d; i++) {
            for (int j = i; j <= d*f; j++) {
                for (int k = j-1; k >= j-f && k >= 0; k--) {
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= flag;
                }
            }
        }
        return dp[d][target];
    }
};
