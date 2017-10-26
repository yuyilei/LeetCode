class Solution {
public:
    int res = 0 ; 
    int totalNQueens(int n){
        long tmp = (1<<n)-1 ; 
        getres (tmp,0,0,0) ; 
        return res ; 
    }
private:
    void getres(int tmp, long row, long ld, long rd){ 
        if ( row != tmp ) {
            long all = tmp & ~(row | ld | rd) ; // all的二进制表示是所有这一行所有的能放的是位置，0为不能放，1为能放 
            while ( all ){
                long last = all & -all ;        // last是最后一位1的位置 
                all -= last ; 
                getres(tmp,row|last, (ld|last)<<1, (rd|last)>>1) ;
            }
        }
        else 
            res++ ; 
    }
};