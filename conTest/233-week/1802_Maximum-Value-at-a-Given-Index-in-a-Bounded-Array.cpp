/*
You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.

 

Example 1:

Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].
Example 2:

Input: n = 6, index = 1,  maxSum = 10
Output: 3
 

Constraints:

1 <= n <= maxSum <= 109
0 <= index < n


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-value-at-a-given-index-in-a-bounded-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
 * 二分法
 */

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum-(n-1);
        int res = 1;
        while (left <= right) {
            int mid = (left+right)/2;
            if (can(n, index, mid, maxSum)) {
                res = mid;
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return res;
    }
private:
    bool can(int n, int index, int value, long maxSum) {
        long left = compute(value, index+1);
        long right = compute(value, n-index);
        return left+right-value <= maxSum;
    }
    long compute(long value, long len) {
        if (value > len) {
            return sum(1, value) - sum(1, value-len);
        }
        else {
            return sum(1, value) + (len-value);   // 不足的部分用1补足
        }
    }
    long sum(long start, long end) {             // 计算从start到end等差数列的和
        return (end+start)*(end-start+1)/2;
    }
};
