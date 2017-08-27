// 动态规划，时间复杂度 O(n*n) ,非常慢 pb[i][j]==true就表示i到j的字符串是回文的
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1  )
            return s ; 
        int i , j , k , l = s.size() , max_l = 1 , flag  ; 
        string max_s = s.substr(0,1) ; 
        bool ** pb = new bool *[l] ; 
        bool * pc = new bool [l] ;  // 表示 pc[i] = true 表示存在长度为i的子字符串 
        for ( i = 0 ; i < l ; i++ ) { 
            pb[i] = new bool [l] ; 
            pc[i] = false ; 
        }
        pc[0] = true ; 
        pc[1] = true ; 
        for ( i = 0 ; i < l ; i++ ) 
            pb[i][i] = true ; 
        for ( i = 0 ; i < l - 1 ; i++ ){
            if (s[i] == s[i+1]){
                pb[i][i+1] = true ; 
                max_l = 2 ; 
                max_s = s.substr(i,2) ; 
            } 
        } 
        for ( k = 2 ; k < l ; k++ ){ 
            pc[k] = false ; 
            for ( i = 0 ; i < l - k ; i++ ){
                j = i + k ;
                if ( s[i] == s[j] ) {
                    pb[i][j] = pb[i+1][j-1] ; // 回文的条件是pb[i+1][j-1] == true && s[i] == s[j] 
                    if ( k + 1 >= max_l && pb[i][j] ) {
                        max_l = k + 1 ;
                        max_s = s.substr(i,k+1) ;          
                        pc[k] = true ; 
                    }
                }
                else {
                    pb[i][j] = false ; 
                }
            }
            if ( !pc[k-1] && !pc[k] )  //  长度为k 和 k-1  的回文字符串不存在，说明没有比较下去的必要了，所以break 
                break ; 
        }
        return max_s ; 
    }
 };