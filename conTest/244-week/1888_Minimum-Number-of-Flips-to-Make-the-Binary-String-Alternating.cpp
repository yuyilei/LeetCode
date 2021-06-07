/*
You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
 

Example 1:

Input: s = "111000"
Output: 2
Explanation: Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
Example 2:

Input: s = "010"
Output: 0
Explanation: The string is already alternating.
Example 3:

Input: s = "1110"
Output: 1
Explanation: Use the second operation on the second element to make s = "1010".
 

Constraints:

1 <= s.length <= 105
s[i] is either '0' or '1'.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
 * 滑动窗口
 * 1. 将s拷贝一份加到s后面，能更方便地执行滑动窗口
 * 2. 构造长度为2*len的01串
 * 3. 对于每一个窗口的字符串，分别计算生成01字符串和10字符串所需要的操作数
 *
 */

class Solution {
public:
    int minFlips(string s) {
        if (s.size() == 1)
            return 0;
        int len = s.size();
        string target = "";
        for (int i = 0; i < len; i++) {
            target += "01";
        }
        s += s;
        int diff = 0;
        int res = len;
        for (int i = 0; i < len; i++) {
            if (s[i] != target[i]) {
                diff++;
            }
        }
        for (int i = 0; i < len; i++) {
            res = min(res, diff);
            res = min(res, len - diff);
            diff -= (s[i] != target[i]);
            diff += (s[i+len] != target[i+len]);
        }
        return res;
    }
};
