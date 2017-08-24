class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x) ;
        string tmp = s ;
        reverse(s.begin(),s.end()) ;
        if (strcmp(s.c_str(),tmp.c_str()) == 0 )
            return true ;
        return false ;
    }
};
