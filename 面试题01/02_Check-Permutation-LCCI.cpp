/*
Given two strings,write a method to decide if one is a permutation of the other.

Example 1:

Input: s1 = "abc", s2 = "bca"
Output: true
Example 2:

Input: s1 = "abc", s2 = "bad"
Output: false
Note:

0 <= len(s1) <= 100
0 <= len(s2) <= 100

*/

/*
  两个相同的数进行异或等于0
*/

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        int flag = 0;
        int len = s1.size();
        for (int i = 0; i < len; i++) {
            flag ^= (int)s1[i];
            flag ^= (int)s2[i];
        }
        return flag == 0;
    }
};
