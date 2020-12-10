/*
Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.

An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.

We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first position they differ is at the final number, and 4 is less than 5.

 

Example 1:

Input: nums = [3,5,2,6], k = 2
Output: [2,6]
Explanation: Among the set of every possible subsequence: {[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]}, [2,6] is the most competitive.
Example 2:

Input: nums = [2,4,3,3,5,4,9,6], k = 4
Output: [2,3,3,4]
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-most-competitive-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> res (k, 0);
        stack<int> s;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            int cur = nums[i];
            while (!s.empty() && (s.top() > cur && s.size()+len-i-1>=k)) {
                s.pop();
            }
            if (s.empty() || s.top() <= cur || s.size()+len-i<=k) {
                s.push(cur);
            }
        }
        while (s.size() > k) {
            s.pop();
        }
        for (int i = 0; i < k; i++) {
            res[k-i-1] = s.top();
            s.pop();
        }
        return res;
    }
};
