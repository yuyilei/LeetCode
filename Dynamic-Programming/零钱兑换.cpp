/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
你可以认为每种硬币的数量是无限的。
*/

// count[i]表示可以凑成 i 元的最少硬币个数
// 如果coins[j]比i小，那么总金额i可以由count[i-conis[j]]再加上这枚零钱构成， count[i]=min(count[i],count[i-coins[j]]+1)。如果count[mount]=mount+1,则表示总金额mount不能由这些零钱兑换。

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if ( amount == 0 )
            return 0;
        sort(coins.begin(),coins.end());
        vector<int> count (amount+1,amount+1);
        count[0] = 0;
        for ( int i = 1 ; i <= amount ; i++ ) {
            for ( int j = 0 ; j < coins.size() && coins[j] <= i ; j++ ) {
                count[i] = min(count[i],count[i-coins[j]]+1);
            }
        }
        return count[amount] != amount + 1 ? count[amount] : -1;
    }
};
