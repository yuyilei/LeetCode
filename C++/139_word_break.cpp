/*
动态规划：
dp[i] 表示前 i 个字母的组成的字符串能不能由 dict里面 单词组成 
dp[0]初始化为 true 
计算 dp[i]:
在计算dp[i]的时候，已知dp[0],dp[1],…,dp[i-1],如果以i为结尾的j~i子串是满足条件的，并且0~j的子串也是在字典中的，那么dp[i]就是true。 
*/
class Solution {
public:
    static bool inDict(string s, vector<string> wordDict){
        for ( int i = 0 ; i < wordDict.size() ; i++ ){
            if ( s == wordDict[i] )
                return true;
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> res (n+1,false);
        res[0] = true;
        for ( int i = 1 ; i <= n ; i++ ){
            for ( int j = 0 ; j < i ; j++ ){
                string tmp = s.substr(j,i-j); 
                if ( res[j] && inDict(tmp,wordDict) ){
                    res[i] = true;
                    break; 
                }
            }
        }
        return res[n];
    }
}; 