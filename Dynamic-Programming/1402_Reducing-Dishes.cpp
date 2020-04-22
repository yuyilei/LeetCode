/*
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]

Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People don't like the dishes. No dish is prepared.
Example 4:

Input: satisfaction = [-2,5,-1,0,3,-3]
Output: 35
 

Constraints:

n == satisfaction.length
1 <= n <= 500
-10^3 <= satisfaction[i] <= 10^3

*/


// 从小到大排序
// dp[i] 每道菜作为第一道菜时的分数总和
//
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        if (satisfaction.back() < 0)
            return 0;
        int n = satisfaction.size();
        vector<int> sum (n, 0);
        sum[0] = satisfaction[0];
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i-1] + satisfaction[i];
        }
        vector<int> dp (n, 0);
        dp[n-1] = satisfaction[n-1];
        int res = dp[n-1];
        for (int i = n-2; i >= 0; i--) {
            int left = (i > 0) ? sum[i-1] : 0;
            int right = sum[n-1];
            dp[i] = dp[i+1] + (right-left);
            res = max(res, dp[i]);
        }
        return res;
    }
};
