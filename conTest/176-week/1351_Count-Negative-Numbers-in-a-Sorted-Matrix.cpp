/*
Given a m * n matrix grid which is sorted in non-increasing order both row-wise and column-wise. 

Return the number of negative numbers in grid.

 

Example 1:

Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.
Example 2:

Input: grid = [[3,2],[1,0]]
Output: 0
Example 3:

Input: grid = [[1,-1],[-1,-1]]
Output: 3
Example 4:

Input: grid = [[-1]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100

*/


/*
 * 从左下角开始查找，一旦在某一行找到一个负数，说明这行右边的都是负数
 */
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        int s = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = m-1; i >= 0; i--) {
            for (int j = s; j < n; j++) {
                if (grid[i][j] < 0) {
                    res += (n-j);
                    s = j;
                    break;
                }
            }
        }
        return res;
    }
};
