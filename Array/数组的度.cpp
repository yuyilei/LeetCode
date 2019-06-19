/*
给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。

你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

示例 1:

输入: [1, 2, 2, 3, 1]
输出: 2
解释:
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
示例 2:

输入: [1,2,2,3,1,4,2]
输出: 6
注意:

nums.length 在1到50,000区间范围内。
nums[i] 是一个在0到49,999范围内的整数。

*/

// 先统计数组中每个元素出现的次数
// 然后找出数组的度，和对应的元素
// 对于每个元素，从两边到中间，统计其最短相同的子数组
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> counter;
        // 统计出现次数
        for (int num : nums) {
            counter[num]++;
        }
        // max_count为度
        // tmp中存对应的数组
        int max_count = 1;
        vector<int> tmp;
        for (map<int,int>::iterator it = counter.begin() ; it != counter.end() ; it++) {
            if (it->second > max_count) {
                max_count = it->second;
                tmp.clear();
                tmp.push_back(it->first);
            }
            else if (it->second == max_count && max_count != 1) {
                tmp.push_back(it->first);
            }
        }
        // 如果度为1，直接返回1
        if (max_count == 1)
            return 1;
        int len = nums.size();
        int res = len;
        // 遍历tmp
        for (int i = 0 ; i < tmp.size() ; i++) {
            int now = len;
            // 从边到中间
            for (int j = 0 ; j < len && nums[j] != tmp[i] ; j++ )
                now--;
            for (int j = len-1 ; j >= 0 && nums[j] != tmp[i] ; j-- )
                now--;
            res = min(res, now);
            // res的最小值为max_count，如果res = max_cout就不用再遍历了
            if (res == max_count)
                break;
        }
        return res;
    }
};
