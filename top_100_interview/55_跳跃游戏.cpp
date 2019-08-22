/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

*/

/*
如果所有元素都不为0， 那么一定可以跳到最后；
从后往前遍历，如果遇到nums[i] = 0，就找i前面的元素j，使得nums[j] > i - j。如果找不到，则不可能跳跃到num[i+1]，返回false。
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        int len = nums.size();
        for (int i = len-2; i >= 0; i--) {
            if (nums[i] == 0) {
                int j = i-1;
                for (; j >= 0; j--) {
                    if (nums[j] > i-j)
                        break;
                }
                if (j < 0)
                    return false;
            }
        }
        return true;
    }
};
