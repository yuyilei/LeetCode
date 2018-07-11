/*
动态规划 
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> res (n+1,1);
        for ( int i = 1 ; i <= n ; i++ ){
            for ( int j = 1 ; i - j > 0 ; j++ )
                res[i] = max(res[i],max(j*(i-j),j*res[i-j])); 
        }
        return res[n];
    }
};