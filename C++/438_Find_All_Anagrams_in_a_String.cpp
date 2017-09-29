class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res , tmp1(256) , tmp2(256) ;
        for ( auto i : p )
            tmp1[i]++ ; 
        int len1 = s.length() , len2 = p.length() ; 
        for ( int i = 0 ; i <len1 ; i++ ){
            tmp2[s[i]]++ ; 
            if ( i >= len2 ) tmp2[s[i-len2]]-- ; 
            if  ( tmp1 == tmp2 )
                res.push_back(i-len2+1) ; 
        } 
        return res ; 
    }
};