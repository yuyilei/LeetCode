// 从最后一行开始，将下一层的左右两个较小的加到上一层，最后直接输出第一个元素，只要一个辅助空间  
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for ( int i = triangle.size()-1 ; i > 0 ; i-- ){
            for ( int j = 0 ; j < triangle[i].size() - 1 ; j++ ){
                int tmp = min(triangle[i][j],triangle[i][j+1]) ; 
                triangle[i-1][j] += tmp ; 
            }
        }
        return triangle[0][0] ; 
    }
};