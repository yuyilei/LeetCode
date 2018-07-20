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