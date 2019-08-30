/*
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> dp (len+1, 0);
        for (int i = 2; i <= len; i++) {
            dp[i] = dp[i-1];
            for (int j = 1; j < i; j++) {
                if (prices[i-1] > prices[j-1]) {
                    int before = (j > 2) ? dp[j-2] : 0;
                    dp[i] = max(dp[i], prices[i-1]-prices[j-1]+before);
                }
            }
        }
        return dp[len];
    }
};
