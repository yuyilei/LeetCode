// 法一： 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, tmp = x ^ y ; 
        for ( int i = 0 ; i < 32 ; i++ ) 
            res += ( tmp >> i ) & 1 ;
        return res ; 
    }
};

// 法二： 
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0 ;
        for ( int i = 0 ; i < 32 ; i++ ){
            int xx = ( x >> i ) & 1 ; 
            int yy = ( y >> i ) & 1 ; 
            res +=  ( xx != yy ) ; 
        }
        return res ; 
    }
}; 