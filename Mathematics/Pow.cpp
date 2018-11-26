/*

实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。
*/

class Solution {
public:
    double myPow(double x, int n) {
        if ( x == 1 )
            return 1;
        if ( x == -1 )
            return (n % 2) ? -1 : 1;
        long num = (long)n;
        // n 从 -2147483648 变为正的时候，会溢出，所以要变为 long
        if ( n < 0 ) {
            x = 1/x;
            num = -num;
        }
        double res = 1;
        for ( long i = 0 ; i < num ; i++ ) {
            if ( res == 0 )
                break;
            res *= x;
        }
        return res;
    }
};


//
class Solution {
public:
    double myPow(double x, int n) {
        if ( n == 0 )
            return 1;
        if ( n < 0 ) {
            // 防止 n 从 -2147483648 变为正的时候，溢出
            return (1/x)*myPow((1/x),-(n+1));
        }
        double tmp = myPow(x*x,n/2);
        return ( n % 2 ) ? x*tmp : tmp;
    }
};
