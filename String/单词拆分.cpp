/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/

// 单词分拆 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if ( s.empty() && wordDict.empty() )
            return true;
        if ( s.empty() || wordDict.empty() )
            return false;
        int len = s.size();
        unordered_set<string> wordset;
        for ( string each : wordDict ) {
            wordset.insert(each);
        }
        vector<bool> dp (len+1, false);
        dp[0] = true;
        for ( int i = 0 ; i < len ; i++ ) {
            for ( int j = 0 ; j <= i ; j++ ) {
                string tmp = s.substr(j, i+1-j);
                if ( dp[j] && wordset.find(tmp) != wordset.end() ) {
                    dp[i+1] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};
