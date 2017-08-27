class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int tmp[256] = {0} ; 
        int max = 0 , cur = 0 , i = 0 , j = 0 ;
        for ( ; j < s.size() ; ) {
            if ( tmp[s[j]] == 0 ) { // 如果当前字符不在当前子字符串内
                tmp[s[j]] = 1 ; 
            }
            else { 
                while ( s[i] != s[j] ){
                    tmp[s[i]] = 0 ;  //   把中间的字符都设为不在当前子字符串内 
                    i++ ; 
                }
                i++ ; 
            }
            j++ ; 
            cur = j - i ; 
            max = (max > cur ) ? max : cur ; 
        }
        return max ; 
    }
};   