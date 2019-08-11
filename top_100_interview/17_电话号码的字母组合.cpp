/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。

*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty())
            return res;
        map<char, vector<string>> dict;
        int start = 0;
        for (int i = 2; i <= 9; i++) {
            int step = (i==7 || i==9) ? 4: 3;
            for (int j = 0; j < step; j++) {
                char tmp = 'a'+start;
                string s(1,tmp);
                dict['0'+i].push_back(s);
                start++;
            }
        }
        res.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            vector<string> now;
            char cur = digits[i];
            int len = res.size();
            for (int j = 0; j < len; j++) {
                for (int k = 0; k < dict[cur].size(); k++) {
                    string tmp = res[j] + dict[cur][k];
                    now.push_back(tmp);
                }
            }
            res = now;
        }
        return res;
    }
};
