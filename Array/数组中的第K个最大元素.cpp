/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:

你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
*/

// 利用快速排序的思想
// 寻找第 len - k 小的元素
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        pos = len - k;
        return getPosthMin(nums, 0, len-1);
    }
private:
    int pos;
    int getPosthMin(vector<int>& nums, int left, int right) {
        int flag = nums[left], tleft = left, tright = right;
        while ( left < right ) {
            while ( left < right && nums[right] >= flag )
                right--;
            if ( left < right )
                nums[left] = nums[right];
            while ( left < right && nums[left] <= flag )
                left++;
            if ( left < right )
                nums[right] = nums[left];
        }
        nums[left] = flag;
        if ( left == pos )
            return flag;
        else if ( left < pos )
            return getPosthMin(nums, left+1, tright);
        else
            return getPosthMin(nums, tleft, left-1);
    }
};
