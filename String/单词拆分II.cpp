/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]
示例 2：

输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。
示例 3：

输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]
*/

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if ( s.empty() && wordDict.empty() )
            return res;
        if ( s.empty() || wordDict.empty() )
            return res;
        len = s.size();
        for ( string each : wordDict )
            wordset.insert(each);
        dp.resize(len+1);
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
        cout << dp[len] << endl;
        if ( dp[len] == false )
            return res;
        dfs(0, s);
        return res;
    }
private:
    vector<bool> dp;
    vector<string> now, res;
    unordered_set<string> wordset;
    int len;
    void dfs(int index, string &s) {
        if ( index == len ) {
            string tmp = "";
            for  ( string each : now )
                tmp = tmp + each + " ";
            res.push_back(tmp.substr(0, tmp.size()-1));
            return;
        }
        for ( int i = index+1 ; i <= len ; i++ ) {
            string tmp = s.substr(index, i-index);
            if ( wordset.find(tmp) != wordset.end() ) {
                now.push_back(tmp);
                dfs(i, s);
                now.pop_back();
            }
        }
    }
};
