/*

给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
*/

// 参考别人的写法，直接减法太硬核了。。很慢
// 用 << 代替乘法
class Solution {
public:
    int divide(int dividend, int divisor) {
        if ( dividend == INT_MIN && divisor == -1 )
            return INT_MAX;
        int flag = ((dividend ^ divisor) >> 31) & 1 ? -1 : 1;
        long did = labs(dividend);
        long dis = labs(divisor);
        long res = 0;
        while ( did >= dis ) {
            long tmp = dis;
            long count = 1;
            while ( did >= (tmp << 2) ) {
                tmp <<= 1;
                count <<= 1;
            }
            did -= tmp;
            res += count;
        }
        return flag*res;
    }
};
