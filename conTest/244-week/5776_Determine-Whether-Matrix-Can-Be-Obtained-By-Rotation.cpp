/*
Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

 

Example 1:


Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
Example 2:


Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
Output: false
Explanation: It is impossible to make mat equal to target by rotating mat.
Example 3:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
Output: true
Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
 

Constraints:

n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] and target[i][j] are either 0 or 1.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/determine-whether-matrix-can-be-obtained-by-rotation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (isEqual(mat, target)) {
                return true;
            }
            mat = rotate(mat);
        }
        return false;
    }
private:
    vector<vector<int>> rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> res (n, vector<int> (n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[j][n-1-i] = mat[i][j];
            }
        }
        return res;
    }
    bool isEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j])
                    return false;
            }
        }
        return true;
    }
};
