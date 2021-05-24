/*
Given a binary string s, return true if the longest contiguous segment of 1s is strictly longer than the longest contiguous segment of 0s in s. Return false otherwise.

For example, in s = "110100010" the longest contiguous segment of 1s has length 2, and the longest contiguous segment of 0s has length 3.
Note that if there are no 0s, then the longest contiguous segment of 0s is considered to have length 0. The same applies if there are no 1s.

 

Example 1:

Input: s = "1101"
Output: true
Explanation:
The longest contiguous segment of 1s has length 2: "1101"
The longest contiguous segment of 0s has length 1: "1101"
The segment of 1s is longer, so return true.
Example 2:

Input: s = "111000"
Output: false
Explanation:
The longest contiguous segment of 1s has length 3: "111000"
The longest contiguous segment of 0s has length 3: "111000"
The segment of 1s is not longer, so return false.
Example 3:

Input: s = "110100010"
Output: false
Explanation:
The longest contiguous segment of 1s has length 2: "110100010"
The longest contiguous segment of 0s has length 3: "110100010"
The segment of 1s is not longer, so return false.
 

Constraints:

1 <= s.length <= 100
s[i] is either '0' or '1'.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longer-contiguous-segments-of-ones-than-zeros
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool checkZeroOnes(string s) {
        if (s.size() == 1)
            return s[0] == '1';
        s += '2';
        int len = s.size();
        vector<int> count (2, 0);
        int cnt = 1;
        for (int i = 1; i < len; i++) {
            if (s[i] != s[i-1]) {
                int t = s[i-1]-'0';
                count[t] = max(cnt, count[t]);
                cnt = 0;
            }
            cnt++;
        }
        return count[1] > count[0];
    }
};


// 2
class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxZero = 0, maxOne = 0;
        int cntZero = 0, cntOne = 0;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            if (s[i] == '0') {
                cntOne = 0;
                cntZero++;
                maxZero = max(maxZero, cntZero);
            }
            if (s[i] == '1') {
                cntZero = 0;
                cntOne++;
                maxOne = max(maxOne, cntOne);
            }
        }
        return maxOne > maxZero;
    }
};
