/*
You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.

 

Example 1:

Input: nums = [9], maxOperations = 2
Output: 3
Explanation:
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.
Example 2:

Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
The bag with the most number of balls has 2 balls, so your penalty is 2 an you should return 2.
Example 3:

Input: nums = [7,17], maxOperations = 2
Output: 7
 

Constraints:

1 <= nums.length <= 105
1 <= maxOperations, nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-limit-of-balls-in-a-bag
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
 *  求最大值的最小或求最小值的最大，可以用二分法
 */
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int res = 0;
        int left = 1, right = 0;          // 最大和最小值分别是数组的最大值和1
        for (int num: nums) {
            right = max(right, num);
        }
        while (left <= right) {
            int mid = (left+right)/2;            // 检验能否通过最多maxOperations次操作得到mid
            int op = 0;
            for (int num: nums) {
                if (num > mid) {
                    op += (num-1)/mid;
                    if (op > maxOperations)
                        break;
                }
            }
            if (op <= maxOperations) {       // 可以得到mid
                res = mid;
                right = mid - 1;
            }
            else {                           // 不能得到mid
                left = mid + 1;
            }
        }
        return res;
    }
};
