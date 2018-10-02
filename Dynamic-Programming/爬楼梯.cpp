/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> res(n+1,0);
        res[1] = 1, res[2] = 2;
        for ( int i = 3 ; i <= n ; i++ ) {
            res[i] = res[i-1] + res[i-2]; 
        }
        return res[n];
    }
}; 
