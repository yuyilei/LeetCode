/*
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
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
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。
*/

// 用小顶堆 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        int n = matrix.size();
        for ( int i = 0 ; i < n ; i++ ) {
            for ( int j = 0 ; j < n ; j++ ) {
                q.push(matrix[i][j]);
                if ( q.size() > k )
                    q.pop();
            }
        }
        return q.top();
    }
};

// 使用二分法   
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); 
        int res = 0;
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while ( low <= high ) {
            int mid = low + (high - low)/2;
            int count1 = helper(matrix, mid);
            // 矩阵中小于mid的元素的个数小于k 
            if ( count1 < k ) {
                res = mid;
                low = mid + 1; 
            }
            else 
                high = mid - 1;
        }
        return res;
    }
private:
    // 统计矩阵中小于key的元素的个数 
    int helper(vector<vector<int>>& matrix, int key) {
        int n = matrix.size();
        int count1 = 0; 
        for ( int i = 0 ; i < n ; i++ ) {
            int left = 0, right = n - 1;
            int tmp = 0;
            // 对每一行使用二分法 
            while ( left <= right ) {
                int mid = (left + right)/2;
                if ( matrix[i][mid] < key ) {
                    tmp = mid + 1;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            count1 += tmp;
        }
        return count1;
    }
};
