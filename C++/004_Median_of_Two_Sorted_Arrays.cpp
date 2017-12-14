class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size() ; 
        if ( len % 2 == 1 ) 
            return findK(nums1,nums2,0,0,len/2+1) ; 
        return ( findK(nums1,nums2,0,0,len/2) + findK(nums1,nums2,0,0,len/2+1) ) / 2 ; 
    }
    double findK(vector<int>nums1, vector<int>nums2, int l1, int l2, int k ) {
        if ( l1 >= nums1.size() ) 
            return nums2[l2+k-1] ; 
        if ( l2 >= nums2.size() ) 
            return nums1[l1+k-1] ; 
        if ( k == 1 ) 
            return min(nums1[l1],nums2[l2]) ; 
        int mid1 = ( l1+k/2-1 < nums1.size() ) ? nums1[l1+k/2-1] : INT_MAX ; 
        int mid2 = ( l2+k/2-1 < nums2.size() ) ? nums2[l2+k/2-1] : INT_MAX ; 
        if ( mid1 > mid2 )
            return findK(nums1,nums2,l1,l2+k/2,k-k/2) ; 
        return findK(nums1,nums2,l1+k/2,l2,k-k/2) ; 
    }
};


// 分为两种情况，两数组的元素总数为奇数和偶数，最后转化为在两数组中找第K个元素的情况。
// nums1[k / 2] nums2[k / 2] 比较，如果 nums2[k / 2] > nums2[k / 2] 那么，所求的元素必然不在nums2的前k/2个元素中，删去nums2中的前k/2个元素。 找第k-k/2个元素