/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
*/

// 字母异位词在排序之后的的单词是一样的，所以利用一个map维护。
// string 也可以用 sort函数
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> tmp;
        for ( auto str : strs ) {
            string now = str;
            sort(now.begin(),now.end());
            tmp[now].push_back(str);
        }
        for ( auto it : tmp )
            res.push_back(it.second);
        return res;
    }
};
