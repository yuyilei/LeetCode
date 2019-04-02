/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

// dp + 回溯 
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if ( s.empty() )
            return res;
        len = s.size();
        dp.resize(len, vector<bool> (len, false));
        for ( int i = 0 ; i < len ; i++ ) {
            dp[i][i] = true;
            if ( i+1 < len && s[i] == s[i+1] )
                dp[i][i+1] = true;
        }
        for ( int i = len-3 ; i >= 0 ; i-- ) {
            for ( int j = i+2 ; j < len ; j++ ) {
                if ( dp[i+1][j-1] && s[i] == s[j] )
                    dp[i][j] = true;
            }
        }
        vector<string> tmp;
        helper(tmp, 0, s);
        return res;
    }
private:
    int len;
    vector<vector<string>> res;
    vector<vector<bool>> dp;
    void helper(vector<string>& tmp, int index, string s) {
        if ( index == len ) {
            res.push_back(tmp);
            return;
        }
        for ( int i = index ; i < len ; i++ ) {
            if ( dp[index][i] ) {
                string now = s.substr(index, i-index+1);
                tmp.push_back(now);
                helper(tmp, i+1, s);
                tmp.pop_back();
            }
        }
    }
};
