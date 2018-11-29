/*
给定一个字符串，逐个翻转字符串中的每个单词。

示例:

输入: "the sky is blue",
输出: "blue is sky the".
说明:

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
进阶: 请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法。
*/

// 1. 清除字符串首的空格
// 2. 翻转整个字符串
// 3. 清除字符串首的空格
// 4. 清除字符串内的多余空格
// 5. 翻转单个单词
class Solution {
public:
    void reverseWords(string &s) {
        rmblank(s);
        reverse(s,0,s.size()-1);
        rmblank(s);
        rmInterBlank(s);
        reverseOne(s);
    }
    void rmblank(string &s) {
        while ( s.size() != 0 && s[0] == ' ' ) {
            s.erase(0,1);
        }
    }
    void reverse(string &s, int left, int right) {
        if ( left < 0 || right >= s.size() )
            return;
        while ( left < right ) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++; right--;
        }
    }
    void rmInterBlank(string &s) {
        if ( s.empty() )
            return;
        int index = 0;
        while ( index < s.size() - 1 ) {
            if ( s[index] == ' ' && s[index+1] == ' ' ) {
                s.erase(index,1);
            }
            else {
                index++;
            }
        }
    }
    void reverseOne(string &s) {
        int left = 0, right = 0;
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( s[i] == ' ' ) {
                right = i - 1;
                reverse(s,left,right);
                left = i + 1;
            }
        }
        reverse(s,left,s.size()-1);
    }
};
