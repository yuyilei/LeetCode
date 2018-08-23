/*
广度优先，从当前点向周围扩散，长度从0开始，直到遇到为0的格子 
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(); 
        int maxlen = row + col - 2; 
        vector<vector<int>> res (row, vector<int> (col,maxlen+1)); 
        for ( int i = 0 ; i < row ; i++ ) {
            for ( int j = 0 ; j < col ; j++ ) {
                if ( matrix[i][j] == 0 ) {
                    res[i][j] = 0; 
                }
            }
        }
        for ( int i = 0 ; i < row ; i++ ) {
            for ( int j = 0 ; j < col ; j++ ) {
                for ( int len = 1 ; len <= maxlen ; len++ ) {
                    if ( res[i][j] != maxlen+1 ) {
                        break; 
                    } 
                    int c[4] = {1,1,-1,-1};
                    int d[4] = {1,-1,1,-1};
                    for ( int p = 0 ; p <= len ; p++ ) {
                        if ( res[i][j] != maxlen+1 ) {
                            break; 
                        } 
                        int q = len - p;
                        for ( int k = 0 ; k < 4; k++ ) {
                            int ti = i + p*c[k]; 
                            int tj = j + q*d[k]; 
                            if ( ti < 0 || ti >= row || tj < 0 || tj >= col )
                                continue;
                            if ( res[ti][tj] == 0 ) {
                                res[i][j] = len;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
}; 