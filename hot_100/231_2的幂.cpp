/*
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // return (n > 0) && ((n & -n) == n);
        return (n > 0) && ((n & (n-1)) == 0);
    }
};
