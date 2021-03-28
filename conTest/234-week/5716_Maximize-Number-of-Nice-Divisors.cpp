/*
You are given a positive integer primeFactors. You are asked to construct a positive integer n that satisfies the following conditions:

The number of prime factors of n (not necessarily distinct) is at most primeFactors.
The number of nice divisors of n is maximized. Note that a divisor of n is nice if it is divisible by every prime factor of n. For example, if n = 12, then its prime factors are [2,2,3], then 6 and 12 are nice divisors, while 3 and 4 are not.
Return the number of nice divisors of n. Since that number can be too large, return it modulo 109 + 7.

Note that a prime number is a natural number greater than 1 that is not a product of two smaller natural numbers. The prime factors of a number n is a list of prime numbers such that their product equals n.

 

Example 1:

Input: primeFactors = 5
Output: 6
Explanation: 200 is a valid value of n.
It has 5 prime factors: [2,2,2,5,5], and it has 6 nice divisors: [10,20,40,50,100,200].
There is not other value of n that has at most 5 prime factors and more nice divisors.
Example 2:

Input: primeFactors = 8
Output: 18
 

Constraints:

1 <= primeFactors <= 109


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-number-of-nice-divisors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
 * 好因子的个数等于每个质因数的个数的乘积
 * 此问题转化为：有若干个数相加等于n, 求这些数乘积的最大值
 */

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 3)
            return primeFactors;
        long res = 0;
        if (primeFactors % 3 == 0) {   // 3*m
            res = myPow(3, primeFactors/3);
        }
        else if (primeFactors % 3 == 1) {  // 3*m+1 = 3*(m-1)+4
            res = 2*2*myPow(3, primeFactors/3-1) % mod;
        }
        else {                             // 3*m+2 =  3*m+2
            res = 2*myPow(3, primeFactors/3) % mod;
        }
        return res;
    }
private:
    long mod = 1000000007;
    long myPow(long long x, long long n) {
        long long res = 1;
        while (n) {
            if (n & 1) {
                res = res * x % mod;
            }
            x = x * x % mod;
            n >>= 1;
        }
        return res;
    }
};
