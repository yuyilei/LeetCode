/*
You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.

 

Example 1:

Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
Example 2:

Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score.
The total score is 50 + 15 - 9 + 4 + 42 = 102.
 

Constraints:

n == nums.length
m == multipliers.length
1 <= m <= 103
m <= n <= 105
-1000 <= nums[i], multipliers[i] <= 1000


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-score-from-performing-multiplication-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/*
  dp[i][j] 表示nums前面取i个,后面取j个所取得的最大分数
  dp[i][0] 表示全部取前面
  dp[0][i] 表示全部取后面
  dp[i][j] 可以通过 dp[i-1][j] 和 dp[i][j-1] 得到
 */
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp (m+1, (vector<int> (m+1, 0)));
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0] + nums[i-1]*multipliers[i-1];
        }
        for (int i = 1; i <= m; i++) {
            dp[0][i] = dp[0][i-1] + nums[n-i]*multipliers[i-1];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; i+j <= m; j++) {
                dp[i][j] = max(dp[i-1][j] + nums[i-1]*multipliers[i-1+j], dp[i][j-1] + nums[n-j]*multipliers[i-1+j]);
            }
        }
        int res = INT_MIN;
        for (int i = 0; i <= m; i++) {
            res = max(res, dp[i][m-i]);
        }
        return res;
    }
};
