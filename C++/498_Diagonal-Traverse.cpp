/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:

 

Note:

The total number of elements of the given matrix will not exceed 10,000.

*/

// 哈希表
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return {};
        vector<int> res;
        map<int, map<int, int>> dict;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dict[i+j][j] = matrix[i][j];
            }
        }
        bool reverse = false;
        for (auto d: dict) {
            if (reverse) {
                for (map<int, int>::reverse_iterator it = d.second.rbegin(); it != d.second.rend(); it++) {
                    res.push_back(it->second);
                }
            }
            else {
                for (map<int, int>::iterator it = d.second.begin(); it != d.second.end() ; it++) {
                    res.push_back(it->second);
                }
            }
            reverse = !reverse;
        }
        return res;
    }
};


