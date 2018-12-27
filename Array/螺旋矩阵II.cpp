/*
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:

输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res (n,vector<int> (n,0));
        int now = 1;
        int i = 0, j = 0;
        while ( now <= n*n ) {
            for ( ; j < n ; j++ ) {
                if ( res[i][j] != 0 )
                    break;
                res[i][j] = now++;
            }
            j--;
            i++;
            for ( ; i < n ; i++ ) {
                if ( res[i][j] != 0 )
                    break;
                res[i][j] = now++;
            }
            j--;
            i--;
            for ( ; j >= 0 ; j-- ) {
                if ( res[i][j] != 0 )
                    break;
                res[i][j] = now++;
            }
            j++;
            i--;
            for ( ; i >= 0 ; i-- ) {
                if ( res[i][j] != 0 )
                    break;
                res[i][j] = now++;
            }
            j++;
            i++;
        }
        return res;
    }
};
