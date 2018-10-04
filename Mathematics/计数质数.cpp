/*
统计所有小于非负整数 n 的质数的数量。
*/

// 直接判断每一个数字，效率低
class Solution {
public:
    bool isPrimes(int n) {
        for ( int i = 2 ; i*i <= n ; i++ ) {
            if ( n % i == 0 ) 
                return false;
        }
        return true;
    }
    int countPrimes(int n) {
        if ( n <= 2 ) 
            return 0; 
        int res = 1;
        for ( int i = 3 ; i < n ; i += 2 ) {
            if ( isPrimes(i) ) {
                res++;
            }
        }
        return res;
    }
}; 

// 利用时间换取空间
// 维持一个大小为n的bool型数组，当x判断完毕后，把数组内所有x的倍数都置位false，每次判断一个数是否为质数时先查表，表里面有才遍历。
class Solution {
public:
    bool isPrime(int n) {
        for ( int i = 2 ; i*i <= n ; i++ ) {
            if ( n % i == 0 ) 
                return false;
        }
        return true;
    }
    int countPrimes(int n) {
        vector<bool> tmp (n,false);
        int res = 0;
        tmp[0] = tmp[1] = false;
        for ( int i = 2 ; i < n ; i++ ) {
            if ( !tmp[i] && isPrime(i) ) {
                res++;
            }
            for ( int j = 2*i; j < n ; j += i ) {
                tmp[j] = true;
            }
        }
        return res;
    }
};