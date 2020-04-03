/*
Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

Example 1:

Input: s = "leetcode"
Output: false
Example 2:

Input: s = "abc"
Output: true
 

Note:

0 <= len(s) <= 100

*/

class Solution {
public:
    bool isUnique(string astr) {
        int flag = 0;
        for (char c: astr) {
            int n = c-'a';
            int tmp = 1 << n;
            if ((flag & tmp) != 0)   // 要加括号，!= 的优先级比&高
                return false;
            flag = flag | tmp;
        }
        return true;
    }
};
