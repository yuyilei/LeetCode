class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res ; 
        vector<string> tmp; 
        getres(s,0,tmp,res) ; 
        return res; 
    } 
    void getres(string s, int pos, vector<string>tmp, vector<vector<string>> &res){
        if ( pos == s.size() ){
            res.push_back(tmp) ; 
            return ; 
        } 
        for ( int i = pos ; i < s.size() ; i++ ){
            if ( isPalindrome(s.substr(pos,i-pos+1)) ){
                tmp.push_back(s.substr(pos,i-pos+1)) ; 
                getres(s, i+1, tmp, res) ; 
                tmp.pop_back() ; 
            }
        }
    } 
    bool isPalindrome(string t){
        int s = 0, e = t.length() - 1; 
        while ( s < e )
            if ( t[s++] != t[e--] ) 
                return false ; 
        return true ; 
    }
};