/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res (2,-1);
        if (nums.empty())
            return res;
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (left+right)/2;
            if (nums[mid] == target) {
                left = mid;
                right = mid;
                break;
            }
            if (nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        if (left > right)
            return res;
        while (left >= 0 && nums[left] == target)
            left--;
        while (right < nums.size() && nums[right] == target)
            right++;
        res[0] = left+1;
        res[1] = right-1;
        return res;
    }
};


//  两次二分查找，分别找出左右边界
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.empty())
            return res;
        int len = nums.size();
        int left = 0, right = len-1;
        while (left < right) {
            int mid = (left+right)/2;
            if (nums[mid] >= target)
                right = mid;
            else
                left = mid+1;
        }
        if (nums[left] != target)
            return res;
        res[0] = left;
        right = len-1;
        while (left < right) {
            int mid = (left+right+1)/2;
            if (nums[mid] <= target)
                left = mid;
            else
                right = mid-1;
        }
        res[1] = right;
        return res;
    }
};
