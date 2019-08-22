/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty())
            return 1;
        bool hasOne = false;
        for (int num: nums) {
            if (num == 1) {
                hasOne = true;
                break;
            }
        }
        if (!hasOne)
            return 1;
        if (hasOne && nums.size() == 1)
            return 2;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] <= 0 || nums[i] > len)
                nums[i] = 1;
        }
        for (int i = 0; i < len; i++) {
            int absnum = abs(nums[i]);
            if (absnum == len) {
                nums[0] = -abs(nums[0]);
            }
            else {
                nums[absnum] = -abs(nums[absnum]);
            }
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > 0)
                return i;
        }
        if (nums[0] > 0)
            return len;
        return len+1;
    }
};


// 通过不了，会溢出
// 找一个long long当bitmap
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) {
            return 1;
        }
        long long bitmap = 0;
        int len = nums.size();
        for (int num: nums) {
            if (num >= 1 && num <= len) {
                if ((bitmap & (1 << num)) == 0) {
                    bitmap += (1 << num);
                }
            }
        }
        for (int i = 1; i <= len; i++) {
            if ((bitmap & (1 << i)) == 0)
                return i;
        }
        return len+1;
    }
};
