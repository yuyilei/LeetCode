/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp (n+1, 0);
        for (int i = 1; i <= n; i++) {
            int tmp = i;
            for (int j = 1; j*j <= i; j++) {
                tmp = min(tmp, dp[i-j*j]);
            }
            dp[i] = tmp+1;
        }
        return dp[n];
    }
};


class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        int step = 0;
        while (!q.empty()) {
            step++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int cur = q.front();
                q.pop();
                for (int j = sqrt(cur); j >= 1; j--) {
                    if (j*j == cur) {
                        return step;
                    }
                    else {
                        q.push(cur-j*j);
                    }
                }
            }
        }
        return step;
    }
};
