// 解法一 
// 动态规划，时间复杂度 O(n*n) ,非常慢 pb[i][j]==true就表示i到j的字符串是回文的
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1  )
            return s ; 
        int i , j , k , l = s.size() , max_l = 1   ; 
        string max_s = s.substr(0,1) ; 
        int  ** pb = new int *[l] ; 
        int  * pc = new int  [l] ;  // 表示 pc[i] = true 表示存在长度为i的子字符串 
        for ( i = 0 ; i < l ; i++ ) { 
            pb[i] = new int [l] ; 
            pc[i] = 1 ; 
        }
        pc[0] = 1 ; 
        pc[1] = 1 ; 
        for ( i = 0 ; i < l ; i++ ) 
            pb[i][i] = 1 ; 
        for ( i = 0 ; i < l - 1 ; i++ ){
            if (s[i] == s[i+1]){
                pb[i][i+1] = 1 ; 
                max_l = 2 ; 
                max_s = s.substr(i,2) ; 
            } 
        } 
        for ( k = 2 ; k < l ; k++ ){ 
            pc[k] = 0 ; 
            for ( i = 0 ; i < l - k ; i++ ){
                j = i + k ;
                if ( s[i] == s[j] ) {
                    pb[i][j] = pb[i+1][j-1] ; // 回文的条件是pb[i+1][j-1] == true && s[i] == s[j] 
                    if ( k + 1 >= max_l && pb[i][j] == 1 ) {
                        max_l = k + 1 ;
                        max_s = s.substr(i,k+1) ;          
                        pc[k] = 1 ; 
                    }
                }
                else {
                    pb[i][j] = 0 ; 
                }
            }
            if ( !pc[k-1] && !pc[k] )  //  长度为k 和 k-1  的回文字符串不存在，说明没有比较下去的必要了，所以break 
                break ; 
        }
        return max_s ; 
    }
 };

 // 解法二 ：比解法一快多了
 // 中心思想是,寻找每一个重复字符串（长度为1也算，比如a  , cccc ) 以重复字符串为中心向两边遍历查找   
class Solution {
public:
    string longestPalindrome(string s) {
        if ( s.size() <= 1 ) 
            return s ; 
        int index = 0 , start , end  , max_l = 1 , res_start = 0 , l = s.size() , tmp ; 
        for ( ; index < l ; ){
            if ( l - index <= max_l / 2 ) 
                break ; 
            start = index ; 
            end = start ; 
            while ( end < l && s[end+1] == s[end] )  //  这个循环得到回文字符串的中间的重复部分 如  abccccba  中的 cccc  
                end++ ;                              // 这个循环是为了找到尽量长的重复字符串
            index = end + 1 ; // index是上一个中间重复子字符串之后的第一个字符 如 abccccba 中的 b(第二个) , 也可以说成是每一个重复字符串的第一个字符
            while ( start > 0 && end < l - 1 && s[start-1] == s[end+1] ) { // 得到中间重复部分之后，向两边散开查找 ，此时的start是下标为2的c,end是下标为5的c(在abccccba中)
                start-- ;                                                  //  循环开始时的start其实是上一次循环的index
                end++ ;
            } 
            tmp = end - start + 1 ; 
            max_l = ( max_l > tmp ) ? max_l : tmp ;
            res_start = ( max_l > tmp ) ? res_start : start ; 
        }
        return s.substr(res_start,max_l) ; 
    }
}