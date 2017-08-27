class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() <= 1  )
            return s.size() ; 
        int i , j , k , l = s.size() , sum = 0 ; 
        int ** pb = new int *[l] ; 
        int * pc = new int [l] ;  // 表示 pc[i] == 1 表示存在长度为i的子字符串 
        for ( i = 0 ; i < l ; i++ ) { 
            pb[i] = new int [l] ; 
            pc[i] = 0 ; 
        }
        pc[1] = 1 ; 
        for ( i = 0 ; i < l ; i++ ) 
            pb[i][i] = 1 ; 
        sum = l ; 
        for ( i = 0 ; i < l - 1 ; i++ ){
            if (s[i] == s[i+1]){
                pb[i][i+1] = 1 ; 
                sum++ ; 
            } 
        }
        for ( k = 2 ; k < l ; k++ ){ 
            pc[k] = 0 ; 
            for ( i = 0 ; i < l - k ; i++ ){
                j = i + k ;
                if ( s[i] == s[j] ) {
                    pb[i][j] = pb[i+1][j-1] ; // 回文的条件是pb[i+1][j-1] == 1 && s[i] == s[j] 
                    if ( pb[i][j] == 1 ) { // 非常坑爹，这里一定要写 == 1 ， 不写的话有个样例过不了
                        sum++ ;       
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
        return sum ; 
    }
};