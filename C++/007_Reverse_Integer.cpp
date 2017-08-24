class Solution {
public:
    int reverse(int x) {
        int flag = 0 ;
        int temp ;
        if ( x < 0 ) {
            flag = 1 ;
            x = -x ;
        }
        int res = 0 ;
        while ( x ) {
            temp  = (flag) ? (0-res) : res ;
            if ( temp > INT_MAX /10 || temp < INT_MIN /10 ) // 这两种情况是temp的最大值和最小值,不能在相加之后判断，因为溢出之后大小会改变，应该在相加之前判断
                return 0 ;
            res = res*10 + (x%10) ;
            x /= 10 ;
        }
        return (flag)? -res : res ; // 不能return temp ，因为循环只执行一次时，temp为0
    }
};
