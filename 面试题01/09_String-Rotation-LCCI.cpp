/*
Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 (e.g.,"waterbottle" is a rotation of"erbottlewat"). Can you use only one call to the method that checks if one word is a substring of another?

Example 1:

Input: s1 = "waterbottle", s2 = "erbottlewat"
Output: True
Example 2:

Input: s1 = "aa", "aba"
Output: False
 

Note:

0 <= s1.length, s1.length <= 100000

*/


// 字符串旋转: 对于某个特定的位置，将包括这个位置在内的左边部分移动到右边，将右边部分移动到左边

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        string ss = s2+s2;
        return ss.find(s1) != ss.npos;           // 使用一次寻找子串的方法
    }
};
