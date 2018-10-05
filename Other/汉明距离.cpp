/*
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
给出两个整数 x 和 y，计算它们之间的汉明距离。
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;
        while ( x > 0 || y > 0 ) {
            int tx = x & 1;
            int ty = y & 1;
            if ( tx ^ ty )
                res++;
            x >>= 1;
            y >>= 1;
        }
        return res;
    }
};


// 改进：
class Solution {
public:
    int hammingDistance(int x, int y) {
        int xy = x ^ y;
        int res = 0;
        while ( xy ) {
            res += (xy & 1);
            xy >>= 1;
        }
        return res;
    }
};
