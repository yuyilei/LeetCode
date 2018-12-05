/*
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842...,
     由于返回类型是整数，小数部分将被舍去。
*/

class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        while ( res <= x ) {
            if ( res != 0 && res >= INT_MAX/res ) {
                if ( INT_MAX % res)
                    return res-1;
                return res;
            }
            if ( res*res == x )
                return res;
            else if ( res*res > x )
                return res-1;
            res++;
        }
    }
};

//二分法
class Solution {
public:
    int mySqrt(int x) {
        if ( x <= 1 )
            return x;
        int left = 0, right = x;
        while ( left < right ) {
            int mid = (left + right)/2;
            if ( x/mid >= mid )
                left = mid + 1;
            else
                right = mid;
        }
        return right-1;
    }
};

// 比较顺眼的二分法
class Solution {
public:
    int mySqrt(int x) {
        if ( x <= 1 )
            return x;
        int left = 0, right = x;
        while ( left <= right ) {
            int mid = (left + right)/2;
            if ( x/mid >= mid )
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left-1;
    }
};
