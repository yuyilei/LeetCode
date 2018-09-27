class Solution {
public:
    int myAtoi(string str) {
        int index = 0, res = 0, pos = 1;
        if ( str.empty() ) 
            return 0;
        while ( index < str.size() && str[index] == ' ' ) 
            index++;
        if ( str[index] != '+' && str[index] != '-' && 
            !(str[index] >= '0' && str[index] <= '9') )
            return 0; 
        if ( str[index] == '+' || str[index] == '-' ) {
            if ( str[index] == '-' )
                pos = -1;
            index++;
        }
        while ( index < str.size() ) {
            if ( str[index] < '0' || str[index] > '9' ) {
                break;
            }
            // 主要是对溢出的判断 　
            if ( res > INT_MAX/10 || ( res == INT_MAX/10 && str[index] > '7' ) ) {
                return ( pos == 1 ) ? INT_MAX : INT_MIN;
            }
            res = res*10 + (str[index]-'0');
            index++;
        }
        return res*pos;
    }
};