/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释:
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。

*/


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty())
            return;
        int len = nums.size();
        k = k % len;
        reverse(nums, 0, len-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, len-1);
    }
private:
    void reverse(vector<int>& nums, int s, int e) {
        while (s < e) {
            swap(nums[s++], nums[e--]);
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty())
            return;
        int len = nums.size();
        k %= len;
        for (int i = 0; i < k; i++) {
            int tmp = nums[len-1];
            for (int j = len-1; j > 0; j--) {
                nums[j] = nums[j-1];
            }
            nums[0] = tmp;
        }
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k %= len;
        for (int start = 0; start < nums.size() && k != 0; len -= k, start += k, k %= len) {
            for (int i = 0; i < k; i++) {
                swap(nums[start+i], nums[nums.size()-k+i]);
            }
        }
    }
};
