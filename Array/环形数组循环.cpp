/*
给定一个含有正整数和负整数的环形数组 nums。 如果某个索引中的数 k 为正数，则向前移动 k 个索引。相反，如果是负数 (-k)，则向后移动 k 个索引。因为数组是环形的，所以可以假设最后一个元素的下一个元素是第一个元素，而第一个元素的前一个元素是最后一个元素。

确定 nums 中是否存在循环（或周期）。循环必须在相同的索引处开始和结束并且循环长度 > 1。此外，一个循环中的所有运动都必须沿着同一方向进行。换句话说，一个循环中不能同时包括向前的运动和向后的运动。
 

示例 1：

输入：[2,-1,1,2,2]
输出：true
解释：存在循环，按索引 0 -> 2 -> 3 -> 0 。循环长度为 3 。
示例 2：

输入：[-1,2]
输出：false
解释：按索引 1 -> 1 -> 1 ... 的运动无法构成循环，因为循环的长度为 1 。根据定义，循环的长度必须大于 1 。
示例 3:

输入：[-2,1,-1,-2,-2]
输出：false
解释：按索引 1 -> 2 -> 1 -> ... 的运动无法构成循环，因为按索引 1 -> 2 的运动是向前的运动，而按索引 2 -> 1 的运动是向后的运动。一个循环中的所有运动都必须沿着同一方向进行。
 

提示：

-1000 ≤ nums[i] ≤ 1000
nums[i] ≠ 0
1 ≤ nums.length ≤ 5000
 

进阶：

你能写出时间时间复杂度为 O(n) 和额外空间复杂度为 O(1) 的算法吗？
*/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if ( nums.empty() )
            return false;
        int len = nums.size();
        for ( int i = 0 ; i < len ; i++ ) {
            int start = i;
            int now = i;
            int step = 0;
            bool flag = nums[i] > 0;             // 标记这个循环是正向还是反向的
            do {
                if ( (nums[now] > 0) != flag )    // 如果循环中出现不符合的，就跳出循环
                    break;
                step++;
                int next = (((now + nums[now]) % len) + len) % len;  // 为了保证next一定是正数
                now = next;
            } while (now != start && step <= len);   // step <= len 防止死循环
            if (now == start && step != 1)           // 出现循环且step不为1
                return true;
        }
        return false;
    }
};
