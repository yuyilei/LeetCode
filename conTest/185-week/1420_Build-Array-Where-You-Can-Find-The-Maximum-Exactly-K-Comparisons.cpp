/*
Given three integers n, m and k. Consider the following algorithm to find the maximum element of an array of positive integers:


You should build the array arr which has the following properties:

arr has exactly n integers.
1 <= arr[i] <= m where (0 <= i < n).
After applying the mentioned algorithm to arr, the value search_cost is equal to k.
Return the number of ways to build the array arr under the mentioned conditions. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

 

Example 1:

Input: n = 2, m = 3, k = 1
Output: 6
Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]
Example 2:

Input: n = 5, m = 2, k = 3
Output: 0
Explanation: There are no possible arrays that satisify the mentioned conditions.
Example 3:

Input: n = 9, m = 1, k = 1
Output: 1
Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]
Example 4:

Input: n = 50, m = 100, k = 25
Output: 34549172
Explanation: Don't forget to compute the answer modulo 1000000007
Example 5:

Input: n = 37, m = 17, k = 7
Output: 418930126
 

Constraints:

1 <= n <= 50
1 <= m <= 100
0 <= k <= n

*/

// dp[n][i][k] 表示长度为n，最大值为i，search_cost为k的数组数量。
// dp[1][x][1] = 1
// 对于dp[n][i][k]有两种情况：
//     1. i只出现在最后一位，构造方法有 sum(dp[n-1][j][k-1]) j == [1, i-1] 种
//     2. i出现在前n-1位中，最后一位可以是1到i中任意取值，所以 i*dp[n-1][i][k]

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if (k == 0 || k > m)
            return 0;
        const int mod = 1000000007;
        int dp[51][101][51] = {0};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int t = 1; t <= k; t++) {
                    if (i == 1 && t == 1)
                        dp[i][j][t] = 1;
                    else {
                        // j 为最后一位
                        long tmp1 = 0;
                        for (int p = 1; p <= j-1; p++)
                            tmp1 += dp[i-1][p][t-1];
                        // j 不为最后一位
                        long tmp2 = (long)j * dp[i-1][j][t];
                        if (tmp1 >= mod)
                            tmp1 %= mod;
                        if (tmp2 >= mod)
                            tmp2 %= mod;
                        int tmp = tmp1 + tmp2;
                        if (tmp >= mod)
                            tmp %= mod;
                        dp[i][j][t] = tmp;
                    }
                }
            }
        }
        int res = 0;
        for (int j = 0; j <= m; j++) {
            res += dp[n][j][k];
            if (res >= mod)
                res %= mod;
        }
        return res;
    }
};
