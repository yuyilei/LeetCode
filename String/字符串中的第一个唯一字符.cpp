/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
您可以假定该字符串只包含小写字母。
*/
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> counter(26,0);
        for ( char c : s ) {
            counter[c-'a']++;
        }
        for ( int i = 0 ; i < s.size() ; i++ ) {
            if ( counter[s[i]-'a'] == 1 ) 
                return i; 
        }
        return -1;
    }
}; 