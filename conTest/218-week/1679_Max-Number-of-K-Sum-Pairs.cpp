/*
You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.

 

Example 1:

Input: nums = [1,2,3,4], k = 5
Output: 2
Explanation: Starting with nums = [1,2,3,4]:
- Remove numbers 1 and 4, then nums = [2,3]
- Remove numbers 2 and 3, then nums = []
There are no more pairs that sum up to 5, hence a total of 2 operations.
Example 2:

Input: nums = [3,1,3,4,3], k = 6
Output: 1
Explanation: Starting with nums = [3,1,3,4,3]:
- Remove the first two 3's, then nums = [1,4,3]
There are no more pairs that sum up to 6, hence a total of 1 operation.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-number-of-k-sum-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int, int> counter;
        int res = 0;
        for (int num: nums) {
            int diff = k - num;
            if (counter.find(diff) != counter.end() && counter[diff] > 0) {
                res++;
                counter[diff]--;
            }
            else {
                counter[num]++;
            }
        }
        return res;
    }
};


// 排序 + 双指针
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int res = 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) {
                res++;
                left++;
                right--;
            }
            else if (sum < k) {
                left++;
            }
            else {
                right--;
            }
        }
        return res;
    }
};
