/*
Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi < numsi+1. Note that a subarray of size 1 is ascending.

 

Example 1:

Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
Example 2:

Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
Example 3:

Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.
Example 4:

Input: nums = [100,10,1]
Output: 100
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-ascending-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        nums.push_back(0);
        int cur = 0, res = 0;
        int len = nums.size();
        cur = nums[0];
        for (int i = 1; i < len; i++) {
            if (nums[i-1] >= nums[i]) {
                res = max(res, cur);
                cur = nums[i];
            }
            else {
                cur += nums[i];
            }
        }
        return res;
    }
};
