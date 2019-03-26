/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m+n-1;
        int i = m-1, j = n-1;
        while ( i >= 0 && j >= 0 && index >= 0 ) {
            if ( nums2[j] > nums1[i] )
                nums1[index--] = nums2[j--];
            else
                nums1[index--] = nums1[i--];
        }
        while ( i >= 0 && index >= 0 )
            nums1[index--] = nums1[i--];
        while ( j >= 0 && index >= 0 )
            nums1[index--] = nums2[j--];
    }
};
