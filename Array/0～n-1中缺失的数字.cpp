/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

 

示例 1:

输入: [0,1,3]
输出: 2
示例 2:

输入: [0,1,2,3,4,5,6,7,9]
输出: 8
 

限制：

1 <= 数组长度 <= 10000

*/

// 有序首先要考虑二分法!!!
// 0-n-1的数字，正好对应下标，对于有序数组, 大小为i的数应当处于下标为i的位置上, 如果不在, 说明在该数字之前发生了错位
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 二分法只能检查某个数字之前是否发生错位，所以当缺少n，也就是前面都没有发生错位的情况检查不出来，所以先检查最后一位
        if (nums.back() == nums.size() - 1)
            return nums.size();
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (left+right)/2;
            if (nums[mid] != mid) {
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        return nums[left] != left ? nums[left]-1 : nums[left]+1;
    }
};
