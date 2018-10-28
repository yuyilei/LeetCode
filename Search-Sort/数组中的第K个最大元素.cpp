/*

在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
*/

// 快速选择 ：时间复杂度 O(N)，空间复杂度 O(1)


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        int left = 0, right = nums.size() - 1;
        while ( left < right ) {
            int tmp_index = partition(nums,left,right);
            if ( tmp_index == index )
                break;
            if ( tmp_index > index )
                right = tmp_index - 1;
            else
                left = tmp_index + 1;
        }
        return nums[index];
    }
    int partition(vector<int>& nums, int left, int right) {
        // nums[left] 作为 flag...
        int i = left + 1, j = right;
        while ( true ) {
            while ( i < right && nums[i] <= nums[left] )
                i++;
            while ( j > left && nums[j] >= nums[left] )
                j--;
            if ( i >= j )
                break;
            swap(nums,i,j);
        }
        swap(nums,left,j);
        return j;
    }
    void swap(vector<int> &nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
