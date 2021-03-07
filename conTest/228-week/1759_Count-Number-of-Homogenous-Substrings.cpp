/*
Given a string s, return the number of homogenous substrings of s. Since the answer may be too large, return it modulo 109 + 7.

A string is homogenous if all the characters of the string are the same.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abbcccaa"
Output: 13
Explanation: The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
Example 2:

Input: s = "xy"
Output: 2
Explanation: The homogenous substrings are "x" and "y".
Example 3:

Input: s = "zzzzz"
Output: 15
 

Constraints:

1 <= s.length <= 105
s consists of lowercase letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-number-of-homogenous-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int countHomogenous(string s) {
        long mod = 1000000007;
        int len = s.size();
        int res = 0;
        for (int i = 0; i < len; ) {
            char cur = s[i];
            int j = i+1;
            for (; j < len; j++) {
                if (s[j] != cur)
                    break;
            }
            long sub = j - i;
            long count = (sub+1)*sub/2;
            res = (res + (count %  mod)) % mod;
            i = j;
        }
        return res;
    }
};
