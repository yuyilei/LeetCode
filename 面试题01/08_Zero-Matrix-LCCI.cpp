/*
Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to 0.

 

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool row0 = false;                // 标记第零行是否有0
        bool col0 = false;                // 标记第零列是否有0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i != 0 && j != 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                    else {
                        if (!row0 && i == 0)
                            row0 = true;
                        if (!col0 && j == 0)
                            col0 = true;
                    }
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row0) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        if (col0) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};
