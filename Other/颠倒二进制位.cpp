/*
颠倒给定的 32 位无符号整数的二进制位。
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int pos = 31;
        uint32_t res = 0;
        while ( n ) {
            res += ((n & 1) << pos);
            pos--;
            n >>= 1;
        }
        return res;
    }
};
