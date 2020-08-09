/*
Your are given an array of integers prices, for which the i-th element is the price of a given stock on day i; and a non-negative integer fee representing a transaction fee.

You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction. You may not buy more than 1 share of a stock at a time (ie. you must sell the stock share before you buy again.)

Return the maximum profit you can make.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
Buying at prices[0] = 1
Selling at prices[3] = 8
Buying at prices[4] = 4
Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Note:

0 < prices.length <= 50000.
0 < prices[i] < 50000.
0 <= fee < 50000.

*/

// cash表示当前不持有股票的最大收益，hold表示当前持有股票的最大收益。
// 在每个交易日，可以选择卖出或者买入股票
// cash = max(cash, hold+price-fee) 前一种情况表示，之前不持有股票，当前也不持有股票，后一种情况表示，之前持有股票，当前卖出股票并扣除手续费
// hold = max(hold, cash-price) 前一种情况表示，之前持有股票，当前也持有股票，后一种情况表示，之前不持有股票，当前买入股票的过程的情况。
// 可以不需要中间变量，当 cash = hold+price-fee时，表示当天卖出，由于一天只能交易一次，所以卖出之后不能买入，也就是hold = hold

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for (int p: prices) {
            cash = max(cash, hold+p-fee);
            hold = max(hold, cash-p);
        }
        return cash;
    }
};
