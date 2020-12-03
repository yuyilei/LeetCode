/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 会超时
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        len = nums.size();
        res = len;
        cout << len << endl;
        oper(nums, x, 0, len-1);
        if (!find)
            return -1;
        return res;
    }
private:
    int res = 0;
    int len = 0;
    bool find = false;
    void oper(vector<int> &nums, int x, int l, int r) {
        if (l > r || ((l != r) && res <= len-(r-l)))
            return;
        if (x == nums[l] || x == nums[r]) {
            res = min(res, len-(r-l));
            find = true;
        }
        if (x - nums[l] > 0) {
            oper(nums, x - nums[l], l+1, r);
        }
        if (x - nums[r] > 0) {
            oper(nums, x - nums[r], l, r-1);
        }
    }
};


/*
找长度最长的滑动窗口
*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int len = nums.size();
        int res = len;
        long long sum = 0;
        for (int n: nums)
            sum += n;
        long long target = sum - x;
        if (target == 0)
            return res;
        int left = 0, right = 0;
        long long tmp = 0;
        while (right <= len) {
            while (tmp > target && left < right) {
                tmp -= nums[left];
                left++;
            }
            if (tmp == target) {
                res = min(res, len-(right-left));
            }
            if (right < len)
                tmp += nums[right];
            right++;
        }
        return (res == len) ? -1 : res;
    }
};
