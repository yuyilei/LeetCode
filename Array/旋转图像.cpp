/*
给定一个 n × n 的二维矩阵表示一个图像。
将图像顺时针旋转 90 度。
你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()/2; 
        int m = matrix.size() - n;
        int len = matrix.size() - 1;
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < m ; j++ ) {
                int ti = i, tj = j; 
                int now = matrix[ti][tj];
                for ( int k = 0 ; k < 4 ; k++ ) {
                    int nexti = tj, nextj = len - ti;
                    int next = matrix[nexti][nextj];
                    matrix[nexti][nextj] = now;
                    now = next; 
                    ti = nexti;
                    tj = nextj;
                }
            }
        }
    }
};