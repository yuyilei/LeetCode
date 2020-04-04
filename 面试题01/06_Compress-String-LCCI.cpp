/*
Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).

Example 1:

Input: "aabcccccaaa"
Output: "a2b1c5a3"
Example 2:

Input: "abbccd"
Output: "abbccd"
Explanation:
The compressed string is "a1b2c2d1", which is longer than the original string.
 

Note:

0 <= S.length <= 50000

*/

class Solution {
public:
    string compressString(string S) {
        if (S.empty())
            return S;
        string res = "";
        int count = 1;
        int len = S.size();
        for (int i = 1; i < len; i++) {
            if (S[i] != S[i-1]) {
                res += S[i-1];
                res += to_string(count);
                count = 0;
            }
            count++;
        }
        res += S[len-1];
        res += to_string(count);
        return res.size() < S.size() ? res : S;
    }
};
