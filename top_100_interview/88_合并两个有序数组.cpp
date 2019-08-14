/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0 || nums1.size() < m+n)
            return;
        int len = nums1.size();
        m--;
        n--;
        for (int i = len-1; i >= 0 && m >= 0 && n >= 0; i--) {
            if (nums1[m] > nums2[n]) {
                nums1[i] = nums1[m--];
            }
            else {
                nums1[i] = nums2[n--];
            }
        }
        while (n >= 0) {
            nums1[n] = nums2[n];
            n--;
        }
    }
};
