/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if ( strs.empty() )
            return res;
        for ( int i = 0 ; i < strs[0].size() ; i++ ) {
            int j = 1;
            for ( ; j < strs.size() ; j++ ) {
                if ( i >= strs[j].size() || strs[0][i] != strs[j][i] ) 
                    break;
            }
            if ( j != strs.size() ) 
                break;
            res += strs[0][i];
        }
        return res;
    }
};