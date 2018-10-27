/*
编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。
*/

class Solution {
public:
    set<int> tmp;
    int changeN(int n) {
        int res = 0;
        while ( n ) {
            res += ( n % 10 ) * ( n % 10 );
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        if ( tmp.count(n) != 0 )
            return false;
        tmp.insert(n);
        int next_n = changeN(n);
        if ( next_n == 1 )
            return true;
        return isHappy(next_n);
    }
};
