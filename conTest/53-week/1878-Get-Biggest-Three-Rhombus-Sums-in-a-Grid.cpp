/*
You are given an m x n integer matrix grid​​​.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:


Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

 

Example 1:


Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211
Example 2:


Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)
Example 3:

Input: grid = [[7,7,7]]
Output: [7]
Explanation: All three possible rhombus sums are the same, so return [7].
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
1 <= grid[i][j] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/get-biggest-three-rhombus-sums-in-a-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//  枚举法
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> res;
        set<int, greater<int>> s;    // set默认是从小到大排序，greater是从大到小排序
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                s.insert(grid[i][j]);
                for (int k = 1; ; k++) {
                    if (i-k<0 || j-k<0 || i+k>=m || j+k>=n) {
                        break;
                    }
                    int tmp = 0;
                    for (int e = 0; e < k; e++) {
                        tmp += grid[i-k+e][j-e];
                        tmp += grid[i+e][j-k+e];
                        tmp += grid[i+k-e][j+e];
                        tmp += grid[i-e][j+k-e];
                    }
                    s.insert(tmp);
                }
            }
        }
        for (auto each : s) {
            res.push_back(each);
            if (res.size() == 3)
                break;
        }
        return res;
    }
};
