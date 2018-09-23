class Solution {
public:
    bool isLetterorNum(char a) {
        return (a >= '0' && a <= '9') || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'); 
    }
    bool isEqual(char a, char b) {
        a = tolower(a);
        b = tolower(b); 
        return a == b; 
    }
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while ( left <= right ) {
            while ( !isLetterorNum(s[left]) ) 
                left++;
            while ( !isLetterorNum(s[right]) ) 
                right--;
            if ( left > right ) 
                break;
            if ( !isEqual(s[left],s[right]) ) 
                return false;
            left++; right--;
        }
        return true;
    }
};