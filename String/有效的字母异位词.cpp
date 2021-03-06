/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
你可以假设字符串只包含小写字母。 
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.size() != t.size() ) 
            return false;
        vector<int> counter(26,0);
        for ( char c : s ) {
            counter[c-'a']++; 
        }
        for ( char c : t ) {
            counter[c-'a']--;
            if ( counter[c-'a'] < 0 )
                return false;
        }
        return true;
    }
}; 

// 二、
class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.size() != t.size() ) 
            return false;
        int len = s.size();
        int flag[26] = {0};
        for ( int i = 0 ; i < len ; i++ ) {
            flag[s[i]-'a']++;
            flag[t[i]-'a']--;
        }
        for ( int i = 0 ; i < 26 ; i++ ) {
            if ( flag[i] != 0 ) 
                return false;
        }
        return true;
    }
};
