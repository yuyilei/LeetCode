class Solution {
public:
    int strStr(string haystack, string needle) {
        if ( needle.size() == 0 ) 
            return 0;
        if ( haystack.size() == 0 ) 
            return -1;
        int len1 = haystack.size(), len2 = needle.size(); 
        for ( int i = 0 ; i <= len1-len2 ; i++ ) {
            int j = 0;
            for ( int k = i ; j < len2 ; j++, k++ ) {
                if ( haystack[k] != needle[j] ) 
                    break;
            }
            if ( j == len2 ) 
                return i;
        }
        return -1;
    }
};