/*
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。

示例:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

返回 13。
说明:
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。



*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        int s = matrix[0][0];
        int e = matrix[row-1][col-1];
        while (s < e) {
            int mid = (s + e)/2;
            int count = 0;
            int i = row-1, j = 0;
            while (i >= 0 && j < col) {
                if (matrix[i][j] <= mid) {
                    count += (i+1);
                    j++;
                }
                else {
                    i--;
                }
            }
            if (count < k)
                s = mid+1;
            else
                e = mid;
        }
        return s;
    }
};
