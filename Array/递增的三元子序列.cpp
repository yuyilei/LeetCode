/*
给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。
说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。
*/

// 题目要求的是子序列，可以是不连续的
// 思路：
// 维持一个递增二元组，对nums[i] 来说，first，second是它前面的最小递增二元组
// 比如对于 5,6,2,3,4 ，在4处，最小递增二元组为(2,3)而不是(5，6)
// 遍历数组
// 如果 nums[i] 小于 first，就更新 first
// 如果 nums[i] 在first和second之间，就更新 second
// 如果 nums[i] 大于second 说明找到递增三元组
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if ( nums.size() < 3 )
            return false;
        int first = INT_MAX, second = INT_MAX;
        for ( int num : nums ) {
            if ( num < first )
                first = num;
            else if ( num > first && num < second )
                second = num;
            else if ( num > second )
                return true;
        }
        return false;
    }
};
