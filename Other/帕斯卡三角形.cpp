/*
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for ( int i = 1 ; i <= numRows ; i++ ) {
            vector<int> tmp (i,1);
            res.push_back(tmp);
        }
        for ( int i = 2 ; i <= numRows ; i++ ) {
            for ( int j = 1 ; j < i - 1 ; j++ ) {
                res[i-1][j] = res[i-2][j-1] + res[i-2][j];
            }
        }
        return res;
    }
};
