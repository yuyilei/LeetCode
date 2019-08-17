/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false


*/

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int left = 0, right = s.size()-1;
        while (left < right) {
            while (left < right && !valid(s[left]))
                left++;
            while (left < right && !valid(s[right]))
                right--;
            if (!equal(s[left], s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
private:
    bool valid(char c) {
        if (c >= 'A' && c <= 'Z')
            return true;
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= '0' && c <= '9')
            return true;
        return false;
    }
    bool equal(char a, char b) {
        if (a >= 'a' && a <= 'z')
            a = a + 'A' - 'a';
        if (b >= 'a' && a <= 'z')
            b = b + 'A' - 'a';
        return a == b;
    }
};
