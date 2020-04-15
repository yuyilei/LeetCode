/*
A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

Given three integers a, b and c, return any string s, which satisfies following conditions:

s is happy and longest possible.
s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
s will only contain 'a', 'b' and 'c' letters.
If there is no such string s return the empty string "".

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 2, b = 2, c = 1
Output: "aabbc"
Example 3:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0

*/

// 贪心算法
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        vector<pair<int,char>> v{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (true) {
            // 从大到小排序
            sort(v.rbegin(), v.rend());
            int pre_len = res.size();
            for (auto &[cnt, ch]: v) {
                if (cnt == 0)
                    break;
                // 当前字符不会和之前字符构成aaa或bbb或ccc
                if (res.size() < 2 || res.back() != ch || res[res.size()-2] != ch) {
                    res += ch;
                    cnt--;
                    break;
                }
            }
            if (pre_len == res.size())
                break;
        }
        return res;
    }
};
