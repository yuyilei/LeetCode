/*
给定一个长度为 n 的整数数组，你的任务是判断在最多改变 1 个元素的情况下，该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，满足 array[i] <= array[i + 1]。

示例 1:

输入: [4,2,3]
输出: True
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
示例 2:

输入: [4,2,1]
输出: False
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
说明:  n 的范围为 [1, 10,000]。

*/


// 当 nums[i] > nums[i+1] 时，可以修改nums[i] 或 nums[i+1] ，取决于nums[i-1]和nums[i+1]的大小
// 当 nums[i-1] > nums[i+1]，修改 nums[i+1] = nums[i]
// 否则，修改 nums[i] = nums[i-1]

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() < 3)
            return true;
        int len = nums.size();
        bool flag = false;
        // 检查第一个元素和第二个元素的关系
        if (nums[0] > nums[1]) {
            flag = true;
            nums[0] = nums[1];
        }
        for ( int i = 1 ; i < len - 1 ; i++ ) {
            if (nums[i] > nums[i+1]) {
                if (flag)
                    return false;
                flag = true;
                if (nums[i-1] > nums[i+1])
                    nums[i+1] = nums[i];
                else
                    nums[i] = nums[i-1];
            }
        }
        return true;
    }
};
