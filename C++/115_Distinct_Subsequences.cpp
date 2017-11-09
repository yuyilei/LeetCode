class Solution {
public:
    int numDistinct(string s, string t) {
        int lens = s.length() , lent = t.length() ; 
        if ( lens < lent ) return 0 ; 
        int res[lens+1][lent+1] ; 
        for ( int i = 0 ; i <= lens ; i++ ) 
            res[i][0] = 1 ; 
        for ( int i = 0 ; i <= lens ; i++ ){
            for ( int j = 0 ; j <= lent &&  j <= i ; j++ ){
                if ( i == j ) 
                    res[i][j] = s.substr(0,i) == t.substr(0,j) ; 
                else if ( s[i-1] != t[j-1] ) 
                    res[i][j] = res[i-1][j] ; 
                else 
                    res[i][j] = res[i-1][j-1] + res[i-1][j] ; 
            }
        }
        return res[lens][lent] ; 
    }
};