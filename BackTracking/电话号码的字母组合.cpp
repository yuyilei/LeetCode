/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string> m;
        initMap();
        vector<string> res;
        for ( auto digit : digits ) {
            combine(digit,res);
        }
        return res;
    }
private:
    map<char,string> m;
    void initMap() {
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
    }
    void combine(char n, vector<string> &res) {
        if ( res.empty() ) {
            for ( char c : m[n] ) {
                string now (1,c);
                res.push_back(now);
            }
        }
        else {
            vector<string> tmp;
            for ( string s : res ) {
                for ( char c : m[n] ) {
                    string now = s + c;
                    tmp.push_back(now);
                }
            }
            res = tmp;
        }
    }
};
