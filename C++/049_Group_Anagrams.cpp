class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res ;
        map<string,vector<string> > tmp ;
        for(auto str: strs) {
            string temp = str ;
            sort(temp.begin(), temp.end()) ;
            tmp[temp].push_back(str) ;
        }
        for (auto item: tmp ){
            res.push_back(item.second) ;
        }
        return res ;
    }
};
