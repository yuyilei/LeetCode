/*
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例 1:

输入:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出: 3
解释:
长度最长的公共子数组是 [3, 2, 1]。
说明:

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100

*/

// 动态规划
// dp[i][j]表示以A[i]和B[j]结尾的公共字符串长度，且必须以A[i]和B[j]结尾
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty())
            return 0;
        int lenA = A.size();
        int lenB = B.size();
        vector<vector<int>> dp (lenA, vector<int> (lenB, 0));
        int res = 0;
        for (int i = 0 ; i < lenA ; i++) {
            for ( int j = 0 ; j < lenB ; j++) {
                if (A[i] == B[j]) {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i-1][j-1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};
