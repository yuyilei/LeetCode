/*
不使用运算符 + 和 - ，计算两整数 a 、b 之和。
示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1
*/

// 为了支持负数的运算，pos应该增加到 32
class Solution {
public:
    int getSum(int a, int b) {
        int last = 0, sum = 0, pos = 0;
        while ( pos < 32 ) {
            int tmpa = a & 1;
            int tmpb = b & 1;
            a >>= 1;
            b >>= 1;
            int value = (tmpa ^ tmpb ^ last) << pos;
            sum |= value;
            last = (tmpa & tmpb) || (tmpa & last) || (tmpb & last);
            pos++;
        }
        return sum;
    }
};
