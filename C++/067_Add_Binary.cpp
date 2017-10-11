class Solution {
public:
    string addBinary(string a, string b) {
        if ( !a.length() )   
            return b ; 
        if ( !b.length() ) 
            return a ; 
        int len1 = a.length() , len2 = b.length() , add = 0 ; 
        string res ; 
        int maxx = max(len1,len2) ; 
        for ( int i = 0 , f1 = 0 , f2 = 0 ; i < maxx ; i++ ){
            char tmp1 = ( i < len1 ) ? a[len1-i-1] : '0' ;
            char tmp2 = ( i < len2 ) ? b[len2-i-1] : '0' ; 
            f1 = ( tmp1 == tmp2 ) ? 0 : 1 ;   
            f2 = ( f1 == add ) ? 0 : 1 ; 
            res += (f2 ? '1' :'0') ; 
            if ( !f1 && tmp1 == '1' || f1 && add )  
                add = 1 ; 
            else 
                add = 0 ; 
        }
        if ( add ) 
            res += '1' ; 
        reverse(res.begin(),res.end()) ;
        return res ; 
    }
} ;