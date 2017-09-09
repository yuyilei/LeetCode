// 解法一： 
class Solution {
public:
    int myAtoi(string str) {
        if ( str.length() == 0 ) 
            return 0 ; 
        int res = 0 , i = 0 , len = str.length() , flag = 1 ;
        while ( i < len ) {
            if ( str[i] != ' ' ) 
                break ; 
            i++ ; 
        }
        if ( i >= len ) 
            return 0 ;
        if ( str[i] == '-' || str[i] == '+' )  {
            flag = ( str[i] == '-') ? -1 : 1 ; 
            i++ ; 
        } 
        for ( ; i < len ; i++ ) { 
            if ( str[i] < '0' || str[i] > '9') 
                break ;  
            if ( flag > 0 ) { 
                if ( res  >= INT_MAX/10 ) { 
                    if ( res > INT_MAX/10 )
                        return INT_MAX ; 
                    else if ( str[i] >= '8') 
                        return INT_MAX ; 
                    }
                res = res * 10 + (str[i]-'0') ; 
            } 
            else { 
                if ( res <= INT_MIN/10 ) {
                    if ( res < INT_MIN/10 )
                        return INT_MIN ;
                    else if ( str[i] >= '8' ) 
                        return INT_MIN ; 
                }
                res = res * 10 - (str[i] -'0') ; 
            }
        }
        return res ; 
    }
};
// 解法二： 
class Solution {
public:
    int myAtoi(string str) {
        stringstream ss(str) ; // 将str写入ss 
        int res = 0 ;
        ss >> res ;    // 将ss写入res 
        return res ; 
    }
};