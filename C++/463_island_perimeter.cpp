/*
对每一个为1的点遍历周围的四个点，如果超出范围或者为0，就将周长加一 
*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if ( grid.size() == 0 || grid[0].size() == 0 ) 
            return 0; 
        int res = 0; 
        int c[4] = {1,-1,0,0};
        int d[4] = {0,0,1,-1};
        for ( int i = 0 ; i < grid.size() ; i++ ) {
            for ( int j = 0 ; j < grid[0].size() ; j++ ) {
                if ( grid[i][j] == 1 ) {
                   for ( int k = 0 ; k <= 3 ; k++ ) {
                       int ti = i + c[k];
                       int tj = j + d[k];
                       if ( ti < 0 || ti >= grid.size() || tj < 0 || tj >= grid[0].size() ) {
                           res++; 
                       }
                       else if ( grid[ti][tj] == 0 ) {
                           res++;
                       }
                   } 
                }
            }
        }
        return res;
    }
};