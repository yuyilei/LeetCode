/*
给定一个整数，写一个函数来判断它是否是 3 的幂次方。
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        int tmp = 1;
        while ( tmp <= n ) {
            if ( tmp == n ) 
                return true;
            if ( tmp >= INT_MAX/3 )
                break;
            tmp *= 3;
        }
        return false;
    }
};


//不使用递归或循环的思路：先计算最大的3的幂次方的数，然后判断n能否被最大3次幂整除即可。 
class Solution {
public:
    bool isPowerOfThree(int n) {
        if ( n <= 0 ) 
            return false;
        int maxx = log(INT_MAX)/log(3);
        int max3 = pow(3,(int)maxx);
        return !(max3 % n);
    }
}; 