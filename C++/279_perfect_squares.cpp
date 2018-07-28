class Solution {
public:
    int numSquares(int n) {
        vector<int> tmp;
        vector<int> res (n+1,0); 
        for ( int i = 1 ; i*i <= n ; i++ )
            tmp.push_back(i*i); 
        for ( int i = 1 ; i <= n ; i++ ) 
             res[i] = i; 
        for ( int i = 1 ; i <= n ; i++ ){
            for ( int j = 0 ; j < tmp.size() && i >= tmp[j] ; j++ ){
                res[i] = min(res[i],res[i-tmp[j]]+1);
            }
        }
        return res[n];
    }
};