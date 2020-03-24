/*
Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.

If there is no such integer in the array, return 0.

 

Example 1:

Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.
 

Constraints:

1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5

*/

// 枚举法
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        for (int num: nums) {
            set<int> s;
            s.insert(1);
            s.insert(num);
            int start = 2, step = 1;
            if (num % 2 == 1) {
                start = 3;
                step = 2;
            }
            for (int i = start; i <= sqrt(num); i += step) {
                if (num % i == 0) {
                    s.insert(i);
                    s.insert(num/i);
                }
                if (s.size() > 4)
                    break;
            }
            if (s.size() == 4) {
                for (auto it = s.begin(); it != s.end(); it++) {
                    res += *it;
                }
            }
        }
        return res;
    }
};


//质数法
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        // 只有四个因数的数有两种情况，1，两个质数的乘积，2，一个质数的三次方
        int res = 0;
        int maxx = 0;
        int C3 = 46;    // 46^3 < 100000 < 47^3
        for (int num: nums)
            maxx = max(maxx, num);
        vector<bool> isPrim (maxx+1, true);
        vector<int> prim;
        // 如果一个数为质数，则它的2倍、3倍、4倍...都是合数
        for (int i = 2; i*i <= maxx+1; i++) {
            if (isPrim[i]) {
                for (int j = i+i; j <= maxx; j += i) {
                    isPrim[j] = false;
                }
            }
        }
        for (int i = 2; i <= maxx; i++) {
            if (isPrim[i]) {
                prim.push_back(i);
            }
        }
        for (int num: nums) {
            for (int p: prim) {
                if (num/p < p)
                    break;
                if (p <= C3 && num == p*p*p) {     // 检查是否为一个质数的立方
                    res += (1+p+p*p+num);
                    break;
                }
                if (num % p == 0 && isPrim[num/p] && p != num/p) {    // 检查是否为两个质数的乘积，且这两个质数不能相等
                    res += (1+p+num/p+num);
                    break;
                }
            }
        }
        return res;
    }
};
