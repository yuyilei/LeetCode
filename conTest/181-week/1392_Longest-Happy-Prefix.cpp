/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s. Return the longest happy prefix of s .

Return an empty string if no such prefix exists.

 

Example 1:

Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
Example 2:

Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
Example 3:

Input: s = "leetcodeleet"
Output: "leet"
Example 4:

Input: s = "a"
Output: ""
 

Constraints:

1 <= s.length <= 10^5
s contains only lowercase English letters.

*/

// kmp算法，求next数组, next数组表示字符串中前缀和后缀的最长匹配长度
// next[i] = j 表示，前i 个字符中，最长匹配长度为j，即前缀 [0, ..., j - 1] 与后缀 [i - j, ..., i - 1] 匹配
// next[len] 就是最长快乐前缀
// 其中，next[0] = -1 长度为0，无意义
// next[1] = 0，长度为1，没有前缀和后缀

class Solution {
public:
    string longestPrefix(string s) {
        if (s.size() <= 1)
            return "";
        int len = s.size();
        vector<int> next (len+1, 0);
        next[0] = -1;
        next[1] = 0;
        int i = 1, j = 0;
        // j 表示已有的匹配的前缀和后缀的长度
        while (i < len) {
            if (j == -1 || s[i] == s[j]) {
                // 1. j = -1 时，说明所有前缀都不匹配，令 next[i+1] = 0
                // 2. 已有 [0, ..., j - 1] 与 [i - j, ..., i - 1] 匹配, 同时 s[j] == s[i]
                j++;
                i++;
                // 匹配长度增加 1, 查看下一个匹配位置
                next[i] = j;
            }
            else {
                 // 不匹配, 说明当前查看的前缀太长, 将 j 跳回到上一个可能的匹配位置
                j = next[j];
            }
        }
        string res = s.substr(0, next[len]);
        return res;
    }
};



// memcmp
// memcmp函数的原型为 int memcmp(const void *str1, const void *str2, size_t n));其功能是把存储区 str1 和存储区 str2 的前 n 个字节进行比较。该函数是按字节比较的
class Solution {
public:
    string longestPrefix(string s) {
        if (s.size() <= 1)
            return "";
        int len = s.size();
        for (int i = len-1; i >= 1; i--) {
            if (memcmp(s.c_str(), s.c_str()+len-i, i) == 0) {
                return s.substr(0, i);
            }
        }
        return "";
    }
};
