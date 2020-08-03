/*
Given an array nums of integers, a move consists of choosing any element and decreasing it by 1.

An array A is a zigzag array if either:

Every even-indexed element is greater than adjacent elements, ie. A[0] > A[1] < A[2] > A[3] < A[4] > ...
OR, every odd-indexed element is greater than adjacent elements, ie. A[0] < A[1] > A[2] < A[3] > A[4] < ...
Return the minimum number of moves to transform the given array nums into a zigzag array.

 

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation: We can decrease 2 to 0 or 3 to 1.
Example 2:

Input: nums = [9,6,1,6,2]
Output: 4
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 1000

*/

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        // ans1: odd is larger, ans2: even is larger
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++) {
            int d1 = 0, d2 = 0;
            // 下标为偶数，要通过减法把偶数位置的数降到比奇数位低
            if (i % 2 == 0) {
                if (i > 0 && nums[i-1] <= nums[i])
                    d1 = nums[i] - nums[i-1] + 1;
                if (i < n-1 && nums[i+1] <= nums[i])
                    d2 = nums[i] - nums[i+1] + 1;
                ans1 += max(d1, d2);
            }
            // 下标为奇数，通过减法将奇数位置的数降到比偶数位低
            else {
                if (nums[i-1] <= nums[i])
                    d1 = nums[i] - nums[i-1] + 1;
                if (i < n-1 && nums[i+1] <= nums[i])
                    d2 = nums[i] - nums[i+1] + 1;
                ans2 += max(d1, d2);
            }
        }
        return min(ans1, ans2);
    }
};
