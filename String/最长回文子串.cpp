/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。
*/

// 动态规划：
// dp[i][j] 表示 i 到 j 的子串构成最长回文子串的长度
class Solution {
public:
    string longestPalindrome(string s) {
        if ( s.size() == 0 )
            return s;
        int len = s.size(), maxx = 1;
        string res;
        res.assign(s.begin(),s.begin()+1);
        vector<vector<int>> dp (len,vector<int> (len,0));
        for ( int i = 0 ; i < len ; i++ ) {
            dp[i][i] = 1;
            if ( i != len - 1 && s[i] == s[i+1] ) {
                res.assign(s.begin()+i,s.begin()+i+2);
                maxx = dp[i][i+1] = 2;
            }
        }
        for ( int tmp = 2 ; tmp < len ; tmp++ ) {
            for ( int i = 0 ; i + tmp < len ; i++ ) {
                int j = i + tmp;
                if ( dp[i+1][j-1] != 0 && s[i] == s[j] ) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                    maxx = tmp;
                    res.assign(s.begin()+i,s.begin()+j+1);
                }
            }
        }
        return res;
    }
};
