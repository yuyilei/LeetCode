class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res ; 
        if ( digits == "") 
            return res ; 
        res.push_back("") ; 
        vector<string> tmp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"} ;
        for ( int  i = 0 ; i < digits.length() ; i++ ) {
            int len = res.size() ; 
            for ( int j = 0 ; j < len ; j++ ) {
                string temp = res[0] ; 
                res.erase(res.begin()) ; 
                for ( int k = 0 ; k < tmp[digits[i]-'0'].length() ; k++ ) {
                    res.push_back(temp+tmp[digits[i]-'0'][k]) ; 
                }
            }
        }
        return res ; 
    }
};