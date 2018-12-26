/*

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if ( matrix.empty() || matrix[0].empty() )
            return res;
        int m = matrix.size(), n = matrix[0].size();
        int sum = m*n;
        int i = 0, j = 0;
        m--;
        while ( res.size() < sum ) {
            for ( int k = 0 ;  k < n ; k++ ) {
                res.push_back(matrix[i][j++]);
            }
            if ( res.size() >= sum )
                break;
            n--;
            j--;
            i++;
            for ( int k = 0 ; k < m ; k++ ) {
                res.push_back(matrix[i++][j]);
            }
            if ( res.size() >= sum )
                break;
            m--;
            i--;
            j--;
            for ( int k = 0 ; k < n ; k++ ) {
                res.push_back(matrix[i][j--]);
            }
            if ( res.size() >= sum )
                break;
            n--;
            j++;
            i--;
            for ( int k = 0 ; k < m ; k++ ) {
                res.push_back(matrix[i--][j]);
            }
            m--;
            i++;
            j++;
        }
        return res;
    }
};
