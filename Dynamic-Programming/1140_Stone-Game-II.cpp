/*
Alex and Lee continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alex and Lee take turns, with Alex starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alex and Lee play optimally, return the maximum number of stones Alex can get.

 

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alex takes one pile at the beginning, Lee takes two piles, then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total. If Alex takes two piles at the beginning, then Lee can take all three piles left. In this case, Alex get 2 + 7 = 9 piles in total. So we return 10 since it's larger.
 

Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 10 ^ 4

*/

/*
 * dp[index][m]表示对于[index, n-1]堆石子（从index开始到最后），M=m的情况下，先手能获得的最多石子
 * 由于Alex一定会拿第一堆石子，所以Alex能获得最大石子为dp[0][1]
 * 记sum[i] =  从i到最后一堆石子的总数
 * 有是三种情况：
 *    1. index >= n 说明没有石子可以被取，dp[index][m] = 0
 *    2. index + 2*m >= n 说明index及后面的石子都可以被取出 dp[index][m] = sum[index]
 *    3. index + 2*m < n 需要遍历所有可能的x，sum[index] - dp[index+x][max(x, 2*m)] 其中dp[index+x][max(x, 2*m)]  为对方为先手时拿的最多石子数，sum[index] 为双方可拿的石子总数
 */

class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp (n+1, vector<int> (n+1, -1));
        vector<int> sum (n, 0);
        sum[n-1] = piles[n-1];
        for (int i = n-2; i >= 0; i--)
            sum[i] = sum[i+1] + piles[i];
        helper(dp, piles, sum, 0, 1);
        return dp[0][1];
    }
private:
    int helper(vector<vector<int>>& dp, vector<int>& piles, vector<int>& sum, int index, int M) {
        if (dp[index][M] != -1)
            return dp[index][M];
        int n = piles.size();
        if (index >= n) {
            dp[index][M] = 0;
            return 0;
        }
        if (index+2*M >= n) {
            dp[index][M] = sum[index];
            return dp[index][M];
        }
        else {
            int maxx = 0;
            for (int i = 1; i <= 2*M; i++) {
                maxx = max(maxx, sum[index] - helper(dp, piles, sum, index+i, max(i, M)));
            }
            dp[index][M] = maxx;
            return dp[index][M];
        }
    }
};

