/*
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口 k 内的数字。滑动窗口每次只向右移动一位。

返回滑动窗口最大值。

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
注意：

你可以假设 k 总是有效的，1 ≤ k ≤ 输入数组的大小，且输入数组不为空。

进阶：

你能在线性时间复杂度内解决此题吗？
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if ( k == 0 || k > nums.size() )
            return {};
        vector<int> res;
        priority_queue<pair<int,int>> q;   // 大顶堆 
        for ( int i = 0 ; i < k ; i++ ) {
            q.push({nums[i],i});
        }
        res.push_back(q.top().first);
        for ( int i = k ; i < nums.size() ; i++ ) {
            while ( !q.empty() && q.top().second <= i - k ) {   // 注意检查堆是否为空  
                q.pop();
            }
            q.push({nums[i],i});
            res.push_back(q.top().first);
        }
        return res;
    }
};
