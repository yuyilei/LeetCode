/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q
merged: a p b q c   d
 

Constraints:

1 <= word1.length, word2.length <= 100
word1 and word2 consist of lowercase English letters.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-strings-alternately
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 == 0)
            return word2;
        if (len2 == 0)
            return word1;
        string res = "";
        int index1 = 0, index2 = 0;
        bool flag = true;
        while (index1 < len1 && index2 < len2) {
            if (flag) {
                res += word1[index1];
                index1++;
            }
            else {
                res += word2[index2];
                index2++;
            }
            flag = !flag;
        }
        if (index1 < len1)
            res += word1.substr(index1, len1);
        if (index2 < len2)
            res += word2.substr(index2, len2);
        return res;
    }
};
