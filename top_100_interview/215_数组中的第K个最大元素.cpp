/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty() || nums.size() < k)
            return -1;
        return findKth(nums, nums.size()-k, 0, nums.size()-1);
    }
private:
    int findKth(vector<int>& nums, int k, int s, int e) {
        if (s > e)
            return -1;
        int index = partition(nums, s, e);
        if (index == k)
            return nums[index];
        else if (index > k)
            return findKth(nums, k, s, index-1);
        else
            return findKth(nums, k, index+1, e);
    }
    int partition(vector<int>& nums, int s, int e) {
        int flag = nums[s];
        int i = s, j = e;
        while (i < j) {
            while (i < j && nums[j] >= flag)
                j--;
            swap(nums[i], nums[j]);
            while (i < j && nums[i] <= flag)
                i++;
            swap(nums[i], nums[j]);
        }
        nums[i] = flag;
        return i;
    }
};
