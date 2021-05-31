/*
A string is good if there are no repeated characters.

Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A substring is a contiguous sequence of characters in a string.

 

Example 1:

Input: s = "xyzzaz"
Output: 1
Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz".
The only good substring of length 3 is "xyz".
Example 2:

Input: s = "aababcabc"
Output: 4
Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".
 

Constraints:

1 <= s.length <= 100
s​​​​​​ consists of lowercase English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/substrings-of-size-three-with-distinct-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int countGoodSubstrings(string s) {
        if (s.size() < 3)
            return 0;
        int res = 0;
        for (int i = 2; i < s.size();) {
            if (s[i-2] != s[i-1] && s[i-1] != s[i] && s[i-2] != s[i]) {
                res++;
                i++;
            }
            else if (s[i-1] == s[i]) {
                i+=2;
            }
            else {
                i++;
            }
        }
        return res;
    }
};
