/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
注意你不能在买入股票前卖出股票。
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.size() <= 1 ) 
            return 0;
        int minn = prices[0], res = 0;
        for ( int i = 1 ; i < prices.size() ; i++ ) {
            if ( prices[i] > minn ) {
                res = max(res,prices[i]-minn);
            }
            minn = min(minn,prices[i]);
        }
        return res;
    }
};