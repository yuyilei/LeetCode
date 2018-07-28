/*
动态规划
res[i][j]表示 s3 中前 i+j 能不能构成 
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if ( s1.size() + s2.size() != s3.size() ) 
            return false;
        int m = s1.size(), n = s2.size();
        vector<vector<bool>> res (m+1,vector<bool> (n+1,false));
        res[0][0] = true;
        for ( int i = 0 ; i <= m ; i++ ){
            for ( int j = 0 ; j <= n ; j++ ){
                if ( i == 0 && j == 0 )
                    continue;
                if ( i == 0 )
                    res[i][j] = ( res[i][j-1] && s3[j-1] == s2[j-1] ); 
                else if ( j == 0 )
                    res[i][j] = ( res[i-1][j] && s3[i-1] == s1[i-1] );
                else 
                    res[i][j] = ( res[i][j-1] && s3[i+j-1] == s2[j-1] ) || ( res[i-1][j] && s3[i+j-1] == s1[i-1]); 
            }
        }
        return res[m][n];
    }
};