/*
峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。

示例 1:

输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
示例 2:

输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5
解释: 你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
说明:

你的解法应该是 O(logN) 时间复杂度的。
*/

// 二分查找
// 每次比较中间节点与中间节点的后继节点，改变left或right
// 直到left == right
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while ( left < right ) {
            int mid = ( left + right ) / 2;
            if ( nums[mid] < nums[mid+1] )
                left = mid+1;
            else if ( nums[mid] > nums[mid+1] )
                right = mid;
        }
        return left;
    }
};


// 这么写更加直观 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while ( left <= right ) {
            int mid = (left + right) / 2;
            int pre = (mid - 1 < 0) ? INT_MIN : nums[mid-1];
            int next = (mid + 1 > nums.size() - 1) ? INT_MIN : nums[mid+1];
            if ( pre <= nums[mid] && next <= nums[mid] ) 
                return mid;
            if ( pre > nums[mid] ) 
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return -1;
    }
};
