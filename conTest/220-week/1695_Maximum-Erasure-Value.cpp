/*
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

 

Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-erasure-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        long res = 0;
        int len = nums.size();
        map<int, int> window;
        vector<long> sum (len, 0);
        sum[0] = nums[0];
        for (int i = 1; i < len; i++) {
            sum[i] = sum[i-1] + nums[i];
        }
        while (right < len) {
            window[nums[right]]++;
            while (left < right && window[nums[right]] > 1) {
                window[nums[left]]--;
                left++;
            }
            long l = (left == 0) ? 0 : sum[left-1];
            long r = sum[right];
            res = max(res, r - l);
            right++;
        }
        return res;
    }
};
