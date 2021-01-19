/*
Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

 

Example 1:

Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
Example 2:

Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valids tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,4,5)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
Example 3:

Input: nums = [2,3,4,6,8,12]
Output: 40
Example 4:

Input: nums = [2,3,5,7]
Output: 0
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
All elements in nums are distinct.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/tuple-with-same-product
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> count;               // 此处不需要排序，使用unordered_map效率更高
        int len = nums.size();
        int res = 0;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i+1; j < len; j++) {
                count[nums[i]*nums[j]]++;
            }
        }
        for (auto c: count) {
            int n = c.second;
            res += n*(n-1)*4;
        }
        return res;
    }
};
