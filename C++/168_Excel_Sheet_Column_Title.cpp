// 本质是十进制转化为二十六进制，但是这个二十六进制是从1开始到26的
class Solution {
public:
    string convertToTitle(int n) {
        string res = "" ; 
        while ( n > 0 ) {
            char tmp = 'A' + (n % 26 + 25) % 26 ; 
            res = tmp + res ;  
            n = (n-1) / 26 ; 
        }
        return res ; 
    }
};