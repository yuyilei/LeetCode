/*
给定一个无重复元素的有序整数数组，返回数组区间范围的汇总。

示例 1:

输入: [0,1,2,4,5,7]
输出: ["0->2","4->5","7"]
解释: 0,1,2 可组成一个连续的区间; 4,5 可组成一个连续的区间。
示例 2:

输入: [0,2,3,4,6,8,9]
输出: ["0","2->4","6","8->9"]
解释: 2,3,4 可组成一个连续的区间; 8,9 可组成一个连续的区间。
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int len = nums.size();
        int left = 0, right = 0;
        for ( int i = 1 ; i <= len ; i++ ) {    // i == len 是为了把最后一个元素放进去
            if ( i < len && nums[i-1]+1 == nums[i] )
                right++;
            else {
                if ( left == right ) {
                    res.push_back(to_string(nums[left]));
                }
                else {
                    string now = to_string(nums[left]) + "->" + to_string(nums[right]);
                    res.push_back(now);
                }
                left = i;
                right = i;
            }
        }
        return res;
    }
};
