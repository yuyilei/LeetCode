/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 



以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

 



图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

 

示例:

输入: [2,1,5,6,2,3]
输出: 10

*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        heights.push_back(0);
        int res = 0;
        stack<int> index;
        for (int i = 0; i < heights.size(); i++) {
            while (!index.empty() && heights[index.top()] > heights[i]) {
                int top = index.top();
                index.pop();
                res = max(res, heights[top]*((index.empty() ? i : i-index.top()-1)));
            }
            index.push(i);
        }
        return res;
    }
};
