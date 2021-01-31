/*
You are given two strings a and b that consist of lowercase letters. In one operation, you can change any character in a or b to any lowercase letter.

Your goal is to satisfy one of the following three conditions:

Every letter in a is strictly less than every letter in b in the alphabet.
Every letter in b is strictly less than every letter in a in the alphabet.
Both a and b consist of only one distinct letter.
Return the minimum number of operations needed to achieve your goal.

 

Example 1:

Input: a = "aba", b = "caa"
Output: 2
Explanation: Consider the best way to make each condition true:
1) Change b to "ccc" in 2 operations, then every letter in a is less than every letter in b.
2) Change a to "bbb" and b to "aaa" in 3 operations, then every letter in b is less than every letter in a.
3) Change a to "aaa" and b to "aaa" in 2 operations, then a and b consist of one distinct letter.
The best way was done in 2 operations (either condition 1 or condition 3).
Example 2:

Input: a = "dabadd", b = "cda"
Output: 3
Explanation: The best way is to make condition 1 true by changing b to "eee".
 

Constraints:

1 <= a.length, b.length <= 105
a and b consist only of lowercase letters.


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int minCharacters(string a, string b) {
        int ca[26] = {0};
        int cb[26] = {0};
        for (char c: a) ca[c-'a']++;
        for (char c: b) cb[c-'a']++;
        // condition 3
        int maxa = 0, maxb = 0;
        for (int i = 0; i < 26; i++) {
            maxa = max(maxa, ca[i]);
            maxb = max(maxb, cb[i]);
        }
        int la = a.size(), lb = b.size();
        int res3 = la - maxa + lb - maxb;
        // condition 1, 2
        int res1 = max(la, lb), res2 = max(la, lb);
        for (int i = 1; i < 26; i++) {
            ca[i] += ca[i-1];
            cb[i] += cb[i-1];
        }
        for (int i = 1; i < 26; i++) {
            // all letters of a is less than i, all letters of b is greater or equal to i
            res1 = min(res1, la-ca[i-1]+cb[i-1]);
            // all letters of b is less than i, all letters of a is greater or equal to i
            res2 = min(res2, lb-cb[i-1]+ca[i-1]);
        }
        return min(res3, min(res1, res2));
    }
};
