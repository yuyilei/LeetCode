/*
Given a rows * columns matrix mat of ones and zeros, return how many submatrices have all ones.

 

Example 1:

Input: mat = [[1,0,1],
              [1,1,0],
              [1,1,0]]
Output: 13
Explanation:
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2.
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
Example 2:

Input: mat = [[0,1,1,0],
              [0,1,1,1],
              [1,1,1,0]]
Output: 24
Explanation:
There are 8 rectangles of side 1x1.
There are 5 rectangles of side 1x2.
There are 2 rectangles of side 1x3.
There are 4 rectangles of side 2x1.
There are 2 rectangles of side 2x2.
There are 2 rectangles of side 3x1.
There is 1 rectangle of side 3x2.
Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
Example 3:

Input: mat = [[1,1,1,1,1,1]]
Output: 21
Example 4:

Input: mat = [[1,0,1],[0,1,0],[1,0,1]]
Output: 5
 

Constraints:

1 <= rows <= 150
1 <= columns <= 150
0 <= mat[i][j] <= 1

*/

/*
 *  left[i][j] 为 (i, j)在这一行左边最多有几个连续的1
 *  然后遍历每个位置，计算以(i, j) 为右下角的矩形个数
 */
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> left (n, vector<int> (m, 0));
        int left_sum = 0;
        for (int i = 0; i < n; i++) {
            left_sum = 0;
            for (int j = 0; j < m; j++) {
                left_sum++;
                if (mat[i][j] == 0)
                    left_sum = 0;
                left[i][j] = left_sum;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0)
                    continue;
                int min_left = 151;
                for (int k = i; k >= 0 && mat[k][j] == 1; k--) {           // 累加所有以(i, j)为右下角的矩形个数
                    min_left = min(min_left, left[k][j]);                  // min_left为第i行到第k行的最小left，也就是最大能够组成的矩形宽度
                    res += min_left;
                }
            }
        }
        return res;
    }
};
