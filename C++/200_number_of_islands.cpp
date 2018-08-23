/*
深度优先，遇到一个为1的格子，把岛屿的数量加一，然后用深度优先把周围全部为1的岛屿设为0（收缩） 
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if ( grid.size() == 0 || grid[0].size() == 0 ) 
            return 0; 
        int res = 0; 
        int row = grid.size(), col = grid[0].size(); 
        for ( int i = 0 ; i < row ; i++ ) {
            for ( int j = 0 ; j < col ; j++ ) {
                if ( grid[i][j] == '1' ) {
                    res++;
                    shrink(grid,i,j); 
                }
            }
        }
        return res;
    }
    void shrink(vector<vector<char>>& grid, int p, int q) {
        grid[p][q] = '0';
        int c[4] = {1,-1,0,0};
        int d[4] = {0,0,1,-1};
        for ( int i = 0 ; i < 4 ; i++ ) {
            int tp = p + c[i];
            int tq = q + d[i]; 
            if ( tp < 0 || tp >= grid.size() || tq < 0 || tq >= grid[0].size() ) {
                 continue;
            }
            if ( grid[tp][tq] == '1' ) 
               shrink(grid,tp,tq);  
        }
    }
}; 