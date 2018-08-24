/*
深度优先: 一边收缩，一边计算面积  
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if ( grid.size() == 0 || grid[0].size() == 0 ) 
            return 0; 
        int res = 0;
        for ( int i = 0 ; i < grid.size() ; i++ ) {
            for ( int j = 0 ; j < grid[0].size() ; j++ ) {
                if ( grid[i][j] == 1 ) {
                    int tmpres = shrink(grid,i,j);
                    res = max(res,tmpres); 
                }
            }
        }
        return res;
    }
    
    int shrink(vector<vector<int>>& grid, int p, int q) {
        if ( grid[p][q] == 0 ) 
            return 0; 
        grid[p][q] = 0;
        int count = 1; 
        int c[4] = {1,-1,0,0};
        int d[4] = {0,0,1,-1};
        for ( int i = 0 ; i < 4 ; i++ ) {
            int tp = p + c[i];
            int tq = q + d[i]; 
            if ( tp < 0 || tp >= grid.size() || tq < 0 || tq >= grid[0].size() ) 
                continue;
            count += shrink(grid,tp,tq);
        }
        return count;
    }
};