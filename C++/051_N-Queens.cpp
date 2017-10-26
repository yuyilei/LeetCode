class Solution {
public:
    vector<vector<string>> res ; 
    int tmp ; 
    vector<vector<string>> solveNQueens(int n) {
        vector<string> t (n,string(n,'.')); 
        tmp = (1<<n)-1 ; // tmp是n位的二进制的1组成的数字 
        getres(t,0,0,0,0) ; 
        return res ;
    }
    void getres(vector<string> &t, long row, long ld, long rd, int now ){
        if ( row != tmp ){
            long all = tmp & ~(row|ld|rd) ; 
            while ( all ){
                long last = all & -all ; 
                t[now][log2(last)] = 'Q' ;  //  把这一行（now)的最后一个
                getres(t, row|last, (ld|last)<<1, (rd|last)>>1, now+1) ; 
                t[now][log2(last)] = '.' ; 
                all -= last ; 
            }
        }
        else 
            res.push_back(t) ; 
    }
};