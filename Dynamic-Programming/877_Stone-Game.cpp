/*
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

 

Example 1:

Input: [5,3,4,5]
Output: true
Explanation:
Alex starts first, and can only take the first 5 or the last 5.
Say he takes the first 5, so that the row becomes [3, 4, 5].
If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
This demonstrated that taking the first 5 was a winning move for Alex, so we return true.
 

Note:

2 <= piles.length <= 500
piles.length is even.
1 <= piles[i] <= 500
sum(piles) is odd.

*/


/*
 * dp[begin][end] 表示在[begin, end]之间先手能拿到的最大石子数
 * 分为三种情况：
 *   1. begin > end 说明石子堆不存在，dp[begin][end] = 0
 *   2. begin == end 说明只有一堆石子，先手肯定选这一堆 dp[begin][end] = piles[begin]
 *   3. begin < end 说明有两堆及以上的石子，先手需要从begin和end中选择一个
 */

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        vector<vector<int>> dp (len, vector<int> (len, 0));
        int alex = helper(dp, piles, 0, len-1);
        int sum = 0;
        for (int pile: piles)
            sum += pile;
        return alex > sum - alex;
    }
private:
    int helper(vector<vector<int>> &dp, vector<int> &piles, int begin, int end) {
        if (begin > end)
            return 0;
        if (begin == end) {
            dp[begin][end] = piles[begin];
            return dp[begin][end];
        }
        int tmp = helper(dp, piles, begin+1, end-1);
        dp[begin][end] = max(piles[begin]+tmp, piles[end]+tmp);
        return dp[begin][end];
    }
};
