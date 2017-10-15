class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > res ; 
        vector<int> tmp; 
        for ( int i = 0 ; i < numRows ; i++ ) {
            tmp.push_back(1) ; 
            for ( int j = i - 1 ; j >= 1  ; j-- ) 
                tmp[j] += tmp[j-1] ;
            res.push_back(tmp) ;  
        }
        return res ; 
    }
};