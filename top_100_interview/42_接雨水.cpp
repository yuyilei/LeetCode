/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。



上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

*/


// 找出最高点
// 分别从左边和右边向中间遍历，如果当前值比上一个值小，说明可以接雨水
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int res = 0;
        int max_index = 0;
        for (int i = 1; i < height.size(); i++) {
            if (height[max_index] < height[i])
                max_index = i;
        }
        int tmp = height[0];
        for (int i = 1; i <= max_index; i++) {
            if (height[i] < tmp)
                res += (tmp-height[i]);
            else
                tmp = height[i];
        }
        tmp = height[height.size()-1];
        for (int i = height.size()-1; i > max_index; i--) {
            if (tmp > height[i-1])
                res += (tmp-height[i-1]);
            else
                tmp = height[i-1];
        }
        return res;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        int res = 0;
        int len = height.size();
        vector<int> left (len, 0);
        vector<int> right (len, 0);
        // left 是i左边的最大值
        for (int i = 1; i < len; i++) {
            left[i] = max(left[i-1], height[i-1]);
        }
        // right 是i右边的最大值
        for (int i = len - 2; i >= 0; i--) {
            right[i] = max(right[i+1], height[i+1]);
        }
        for (int i = 0; i < len; i++) {
            int min_height = min(left[i], right[i]);
            if (min_height > height[i])
                res += (min_height - height[i]);
        }
        return res;
    }
};
