/*
Given an array of integers nums.

A pair (i,j) is called good if nums[i] == nums[j] and i < j.

Return the number of good pairs.

 

Example 1:

Input: nums = [1,2,3,1,1,3]
Output: 4
Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
Example 2:

Input: nums = [1,1,1,1]
Output: 6
Explanation: Each pair in the array are good.
Example 3:

Input: nums = [1,2,3]
Output: 0
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/

// 法一：
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        map<int, int> counter;
        for (int num: nums) {
            counter[num]++;
        }
        for (auto each: counter) {
            int n = each.second;
            if (n != 1) {
                int cur = 0;
                for (int i = 1; i < n; i++) {
                    cur += i;
                }
                res += cur;
            }
        }
        return res;
    }
};


// 法二：
// 每个数字都会使它之前与之相等的数字的对数加一
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        vector<int> cnt (101, 0);
        for (int num: nums) {
            res += cnt[num];
            cnt[num]++;
        }
        return res;
    }
};
