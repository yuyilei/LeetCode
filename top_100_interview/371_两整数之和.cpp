/*
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1

*/


// 考虑到了负数的情况
class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0)
            return a;
        return getSum(a^b, ((unsigned int)(a&b))<<1);
    }
};
