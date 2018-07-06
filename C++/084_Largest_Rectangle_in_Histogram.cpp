// 这个解法从网上找的，我其实不是很懂
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0) ; 
        stack<int> index ; 
        int res = 0 ; 
        for ( int i = 0 ; i < heights.size() ; i++ ) {
            while (!index.empty() && heights[index.top()]>=heights[i]) {
                int h = heights[index.top()] ; 
                index.pop() ; 
                int tmp = h * (index.empty()?i:i-index.top()-1) ; 
                res = max(res,tmp) ; 
             } 
            index.push(i) ; 
        } 
        while (!index.empty()) {
            int h = heights[index.top()] ; 
            int tmp = h*(index.empty()?heights.size():heights.size()-index.top()-1) ; 
            index.pop() ; 
            res = max(res,tmp) ; 
        } 
        return res ; 
    }
};

// 简洁一点的写法 

class Solution {
public:
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