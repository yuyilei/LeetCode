/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]
*/

// 回溯法
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if ( s.size() < 4 || s.size() > 12 )
            return res;
        vector<string> now;
        dfs(s,res,now,0);
        return res;
    }
    void dfs(string s, vector<string> &res, vector<string> &now, int index) {
        if ( now.size() == 4 ) {
            if ( index != s.size() )
                return;
            string tmp = now[0];
            for ( int i = 1 ; i < now.size() ; i++ ) {
                tmp = tmp + "." + now[i];
            }
            res.push_back(tmp);
            return;
        }
        for ( int i = index ; i < s.size() && i < index + 3 ; i++ ) {
            string tmp = s.substr(index,i-index+1);
            if ( isVaild(tmp) ) {
                now.push_back(tmp);
                dfs(s,res,now,i+1);
                now.pop_back();
            }
        }
    }
    bool isVaild(string tmp) {
        int k = stoi(tmp);
        if ( k < 0 || k >= 256 )
            return false;
        if ( k != 0 && tmp[0] == '0' )
            return false;
        if ( k == 0 && tmp.size() > 1 )
            return false;
        return true;
    }
};
