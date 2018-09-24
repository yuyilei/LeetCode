/*
给定一个 32 位有符号整数，将整数中的数字进行反转。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
*/
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while ( x ) {
            if ( abs(res) > INT_MAX/10 ) 
                return 0; 
            res = res*10 + x %10;
            x /= 10;
        }
        return res; 
    }
}; 