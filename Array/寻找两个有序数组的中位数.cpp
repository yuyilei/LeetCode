/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/

/*
    将问题问题转化为两个有序数组，寻找第k个元素的问题。
    假设，第K个元素为X，是nums1中的第i个元素，如果将X插入nums2中吗，则X在nums2中是第 k-i+1 个元素，
    比nums2中第k-i个元素小，大于nums2中第k-i+2个元素。
    二分法
    数组nums1的长度为l1, 数组nums2的长度为l2，要第k个元素
    取 index1 = l1/(l1+l2)*(k-1), index2 = k-1-index1
    1. 如果 nums1[index1] == nums2[index2]，则 nums1[index1]就是第k个元素（前面总共有k-2元素）
    2. 如果 nums1[index1] > nums2[index2]，则 nums1[index1]后面的元素，nums2[index2]前面的元素肯定不是第k个元素
    3. 如果 nums1[index1] < nums2[index2]，则 nums1[index1]前面的元素，nums2[index2]后面的元素肯定不是第k个元素
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        if ( (l1+l2) % 2 )
            return findKthSortedArrays(nums1,nums2,(l1+l2)/2+1);
        else
            return (findKthSortedArrays(nums1,nums2,(l1+l2)/2) + findKthSortedArrays(nums1,nums2,(l1+l2)/2+1))/2.0;
    }
    double findKthSortedArrays(vector<int> nums1, vector<int> nums2, int k) {
        int l1 = nums1.size(), l2 = nums2.size();
        if ( l1 == 0 )
            return (double)nums2[k-1];
        if ( l2 == 0 )
            return (double)nums1[k-1];
        if ( k == 1 )
            return (double)(min(nums1[0],nums2[0]));
        int index1 = (1.0*l1*(k-1))/(l1+l2);
        int index2 = (k-1) - index1 - 1;
        if ( nums1[index1] == nums2[index2] )
            return (double)nums1[index1];
        if ( nums1[index1] > nums2[index2] ) {
            vector<int> t1 (nums1.begin(),nums1.begin()+index1+1);
            vector<int> t2 (nums2.begin()+index2+1,nums2.end());
            return findKthSortedArrays(t1,t2,k-index2-1);
        }
        if ( nums1[index1] < nums2[index2] ) {
            vector<int> t1 (nums1.begin()+index1+1,nums1.end());
            vector<int> t2 (nums2.begin(),nums2.begin()+index2+1);
            return findKthSortedArrays(t1,t2,k-index1-1);
        }
    }
};
