class Solution {
public:
    vector<vector<int>> res ;
    vector<int> tmp ; 
    vector<vector<int>> combinationSum3(int k, int n) {
        getres(k,n,1) ; 
        return res ; 
    }
    void getres(int k, int n, int pos){ 
        if ( n == 0 ){
            if ( k == 0 ) 
                res.push_back(tmp) ; 
            return ; 
        }
        for ( int i = pos ; i < 10 ; i++ ){
            tmp.push_back(i) ; 
            getres(k-1,n-i,i+1) ; 
            tmp.pop_back() ; 
        }
    }
};