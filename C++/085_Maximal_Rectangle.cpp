class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if ( matrix.empty() || matrix[0].empty() ) 
            return 0; 
        int res = 0, n = matrix.size(), m = matrix[0].size();
        for ( int i = 0 ; i < n ; i++ ){
            vector<int> heights (m,0); 
            for ( int j = 0 ; j < m ; j++ ){
                int t = i; 
                while ( t >= 0 && matrix[t--][j] == '1' )
                    heights[j]++; 
            } 
            res = max(res,largestRectangleArea(heights)); 
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> index;
        heights.push_back(0); 
        int i = 0, res = 0;
        while ( i < heights.size() ){
            if ( index.empty() || heights[index.top()] <= heights[i] ){
                index.push(i++); 
            } 
            else{
                int t = index.top(); 
                index.pop(); 
                res = max(res,heights[t]*(index.empty()?i:i-index.top()-1));
            }
        }
        return res;
    }
};