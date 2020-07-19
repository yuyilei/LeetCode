/*
Given a binary string s (a string consisting only of '0' and '1's).

Return the number of substrings with all characters 1's.

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: s = "0110111"
Output: 9
Explanation: There are 9 substring in total with only 1's characters.
"1" -> 5 times.
"11" -> 3 times.
"111" -> 1 time.
Example 2:

Input: s = "101"
Output: 2
Explanation: Substring "1" is shown 2 times in s.
Example 3:

Input: s = "111111"
Output: 21
Explanation: Each substring contains only 1's characters.
Example 4:

Input: s = "000"
Output: 0
 

Constraints:

s[i] == '0' or s[i] == '1'
1 <= s.length <= 10^5

*/

// 先统计出字符串中连续为1的子串长度与个数的关系，再使用(len+1)*len/2计算出符合要求的子串个数，注意中间变量使用long long，否则会溢出
class Solution {
public:
    int numSub(string s) {
        int mod = 1000000007;
        int res = 0;
        map<int, int> cnt;
        s += '0';
        int len = s.size();
        long long sublen = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '0' && sublen != 0) {
                cnt[sublen]++;
                sublen = 0;
                continue;
            }
            if (s[i] == '1')
                sublen++;
        }
        for (auto it: cnt) {
            sublen = it.first;
            int n = it.second;
            long long cur = ((sublen+1)*sublen/2)%mod;
            long long tmp = (cur*n)%mod;
            res = (res+tmp)%mod;
        }
        return res;
    }
};
