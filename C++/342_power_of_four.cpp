class Solution {
public:
    bool isPowerOfFour(int num) {
        if ( num <= 0 ) 
            return false;
        return !(num&(num-1)) && ( (num & 0x55555555) == num) ;
    }
};