/*
The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the numeric value of c is 3, and so on.

The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.

You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.

Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

 

Example 1:

Input: n = 3, k = 27
Output: "aay"
Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.
Example 2:

Input: n = 5, k = 73
Output: "aaszz"
 

Constraints:

1 <= n <= 105
n <= k <= 26 * n
通过次数4,338提交次数7,751

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-string-with-a-given-numeric-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res = "";
        for (int left = n; left >= 1; left--) {
            int allZ = 26 * (left - 1);                   // 剩余left-1个位置全为z所需的num
            if (k > allZ) {
                char tmp = 'a' + (k - allZ - 1);
                res += tmp;
                k = allZ;
            }
            else {
                res += 'a';
                k--;
            }
        }
        return res;
    }
};
