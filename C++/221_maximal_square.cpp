/*
还是动态规划
本题求最大正方形，解法与求最大矩形相似，不同的是，矩形 == 长 * 宽，长方形 = min(长,宽) * min(长,宽)
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if ( matrix.empty() || matrix[0].empty() )
            return 0;
        int n = matrix.size(), m = matrix[0].size();
        int res = 0;
        for ( int i = 0 ; i < n ; i++ ){
            vector<int> heights (m,0);
            for ( int j = 0 ; j < m ; j++ ){
                int t = i;
                while ( t >= 0 && matrix[t--][j] == '1' )
                heights[j]++;
            }
            res = max(res,largestSquareArea(heights));
        }
        return res;
    }
    int largestSquareArea(vector<int>& heights){
        int res = 0, i = 0;
        stack<int> index;
        heights.push_back(0);
        while ( i < heights.size() ){
            if ( index.empty() || heights[i] >= heights[index.top()]){
                index.push(i++);
            } 
            else{
                int col = heights[index.top()];
                index.pop();
                int row = ( index.empty() ) ? i : ( i - index.top() - 1) ;
                int t = min(col,row);
                res = max(res,t*t);
            }
        }
        return res;
    }
}; 