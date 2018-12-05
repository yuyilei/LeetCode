/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/

// 先找出峰值 　
class Solution {
public:
    int trap(vector<int>& height) {
        if ( height.empty() )
            return 0;
        int maxx = 0, maxIndex = 0;
        int res = 0;
        for ( int i = 0 ; i < height.size() ; i++ ) {
            if ( height[i] > maxx ) {
                maxx = height[i];
                maxIndex = i;
            }
        }
        for ( int i = 0, lmax = height.front() ; i < maxIndex ; i++ ) {
            if ( height[i] < lmax ) {
                res += (lmax - height[i]);
            }
            else {
                lmax = height[i];
            }
        }
        for ( int i = height.size()-1, rmax = height.back() ; i > maxIndex ; i-- ) {
            if ( height[i] < rmax ) {
                res += (rmax - height[i]);
            }
            else {
                rmax = height[i];
            }
        }
        return res;
    }
};
