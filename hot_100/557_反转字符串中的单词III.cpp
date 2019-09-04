/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。



*/

class Solution {
public:
    string reverseWords(string s) {
        if (s.size() <= 1)
            return s;
        int len = s.size();
        int start = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ' || i == len-1) {
                int end = (s[i] == ' ') ? i-1 : i;
                reverse(s, start, end);
                while (i < len && s[i] == ' ') {
                    i++;
                }
                start = i;
            }
        }
        return s;
    }
private:
    void reverse(string &s, int start, int end) {
        while (start < end) {
            char c = s[start];
            s[start] = s[end];
            s[end] = c;
            start++;
            end--;
        }
    }
};
