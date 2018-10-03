/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
说明:
初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
*/
// 思路：不断地从后面进行合并，时间复杂度为 O(n) 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j, k;
        for ( i = m-1, j = n-1, k = m+n-1; i >= 0 && j >= 0 ; k--) {
            if ( nums2[j] > nums1[i] ) {
                nums1[k] = nums2[j];
                j--;
            }
            else {
                nums1[k] = nums1[i];
                i--;
            }
        }
        while ( j >= 0 ) {
            nums1[k--] = nums2[j--];
        }
    }
}; 