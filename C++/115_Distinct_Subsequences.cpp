// 双层循环 加 二维数组在一定上是“递归”的体现，保留了现场（二维数组），并且能返回现场（双重循环）
class Solution {
public:
    int numDistinct(string s, string t) {
        int lens = s.length() , lent = t.length() ; 
        int res[lens+1][lent+1] = {0} ; 
        for ( int i = 0 ; i <= lens ; i++ ) 
            res[i][0] = 1 ; 
        for ( int i = 0 ; i <= lens ; i++ ){
            for ( int j = 0 ; j <= lent &&  j <= i ; j++ ){
                if ( i == j ) 
                    res[i][j] = s.substr(0,i) == t.substr(0,j) ; 
                else if ( s[i-1] != t[j-1] )   // 不相等，就说明s[i]的加入对字符匹配没有影响
                    res[i][j] = res[i-1][j] ; 
                else                           // 相等，选择 ，要么加入s[i]（res[i-1][j-1]) ，要么舍弃s[i] （res[i-1][j]，相当于s[i-1]!=t[j-1])
                    res[i][j] = res[i-1][j-1] + res[i-1][j] ; 
            }
        }
        return res[lens][lent] ; 
    }
};



class Solution {
public:
    int numDistinct(string s, string t) {
        int dp[t.size()+1][s.size()+1];
        for (int i = 0; i <=s.size(); i++) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= t.size(); i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (t[i-1] == s[j-1]) { 
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                } else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[t.size()][s.size()];
    }
};