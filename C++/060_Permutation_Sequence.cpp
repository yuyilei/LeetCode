class Solution {
public:
    string getPermutation(int n, int k) {
        string ret ;
        vector<int> v(n) ;
        for(int i = 0 ; i < n ; i ++)
            v[i] = i+1 ;
        while ( n ) {
            int ind = (k-1) / fac(n-1);
            ret += (v[ind]+'0') ;
            k -= ind * fac(n-1) ;
            v.erase(v.begin()+ind) ; 
            n-- ; 
        }
        return ret;
    }
    int fac(int n) {
        int res = 1 ;
        for ( int i = 1 ; i <= n ; i++ ) 
            res *= i ; 
        return res ;
    }
};