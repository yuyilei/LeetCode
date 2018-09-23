/*
编写一个函数，其作用是将输入的字符串反转过来。
*/
class Solution {
public:
    string reverseString(string s) {
        string res = "";
        for ( int i = s.size()-1 ; i >= 0 ; i-- ) {
            res += s[i];
        }
        return res;
    }
};


// 或者直接调用reverse函数
class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(),s.end());
        return s;
    }
};