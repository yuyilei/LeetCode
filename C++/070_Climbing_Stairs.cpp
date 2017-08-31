class Solution { // 其实就是前两项为1和2的斐波那契数列，但是用递归会超时
public:
    int climbStairs(int n) {
        int a = 1 , b = 2 , i = 2 , res ; 
        for ( res = n ; i < n ; i++ ){
            res = a + b ; 
            a = b ; 
            b = res ; 
        }
        return res ; 
    }
};