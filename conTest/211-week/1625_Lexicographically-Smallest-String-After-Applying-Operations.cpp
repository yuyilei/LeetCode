/*
You are given a string s of even length consisting of digits from 0 to 9, and two integers a and b.

You can apply either of the following two operations any number of times and in any order on s:

Add a to all odd indices of s (0-indexed). Digits post 9 are cycled back to 0. For example, if s = "3456" and a = 5, s becomes "3951".
Rotate s to the right by b positions. For example, if s = "3456" and b = 1, s becomes "6345".
Return the lexicographically smallest string you can obtain by applying the above operations any number of times on s.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "0158" is lexicographically smaller than "0190" because the first position they differ is at the third letter, and '5' comes before '9'.

 

Example 1:

Input: s = "5525", a = 9, b = 2
Output: "2050"
Explanation: We can apply the following operations:
Start:  "5525"
Rotate: "2555"
Add:    "2454"
Add:    "2353"
Rotate: "5323"
Add:    "5222"
​​​​​​​Add:    "5121"
​​​​​​​Rotate: "2151"
​​​​​​​Add:    "2050"​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller then "2050".
Example 2:

Input: s = "74", a = 5, b = 1
Output: "24"
Explanation: We can apply the following operations:
Start:  "74"
Rotate: "47"
​​​​​​​Add:    "42"
​​​​​​​Rotate: "24"​​​​​​​​​​​​
There is no way to obtain a string that is lexicographically smaller then "24".
Example 3:

Input: s = "0011", a = 4, b = 2
Output: "0011"
Explanation: There are no sequence of operations that will give us a lexicographically smaller string than "0011".
Example 4:

Input: s = "43987654", a = 7, b = 3
Output: "00553311"
 

Constraints:

2 <= s.length <= 100
s.length is even.
s consists of digits from 0 to 9 only.
1 <= a <= 9
1 <= b <= s.length - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lexicographically-smallest-string-after-applying-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
 * 轮转和相加都是循环循环操作
 * 轮转：对于长度为len的字符串s，每次右移b位，轮转len次后字符串恢复原状
 * 相加：对于长度为len的字符串s，每次对奇数位加a，则最多相加10次后，字符串恢复原状
 * 因此变换产生的字符串是有限的
 * 当b为奇数时，只会修改字符串奇数位的字符，所以最多会产生10*len种字符串
 * 当b为偶数时，会修改字符串奇数和偶数位的字符串，所以最多会产生10*10*len种字符串
 */

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string res = s;
        string cur = s;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            cur = cur.substr(len-b, b) + cur.substr(0, len-b);
            for (int m = 0; m < 10; m++) {
                for (int j = 1; j < len; j += 2) {
                    char tmp = cur[j] + a;
                    cur[j] = (tmp > '9') ? tmp - 10 : tmp;
                }
                if (b % 2) {
                    for (int n = 0; n < 10; n++) {
                        for (int k = 0; k < len; k += 2) {
                            char temp = cur[k] + a;
                            cur[k] = (temp > '9') ? temp - 10 : temp;
                        }
                        res = min(res, cur);
                    }
                }
                else {
                    res = min(res, cur);
                }
            }
        }
        return res;
    }
};
