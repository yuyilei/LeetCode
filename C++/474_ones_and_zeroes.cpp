/*
动态规划 
其实有一点疑问，为什么是从上而下的？
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > res(m+1,vector<int> (n+1,0));
        for ( string s : strs ){
            int num0 = 0, num1 = 0; 
            for ( char c : s )
                ( c == '1' ) ? num1++ : num0++; 
            for ( int i = m ; i >= num0 ; i-- ){
                for ( int j = n ; j >= num1 ; j-- ){
                    res[i][j] = max(res[i][j],res[i-num0][j-num1]+1);
                }
            }
        }
        return res[m][n];
    }
};