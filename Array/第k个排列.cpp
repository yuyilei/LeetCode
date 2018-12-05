/*

给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"
示例 2:

输入: n = 4, k = 9
输出: "2314"
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        string nums = "123456789";
        int fac = 1;
        for ( int i = 2 ; i < n ; i++ )
            fac *= i;
        k--;
        while ( n >= 1 ) {
            int index = k/fac;
            res = res + nums[index];
            nums.erase(index,1);
            k %= fac;
            n--;
            if ( n != 0 )
                fac /= n;
        }
        return res;
    }
};
