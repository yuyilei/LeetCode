class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m+n-1 , p = m-1, q = n-1 ;
        for ( ; p >= 0 && q >= 0 ; i-- ) {
            if ( nums1[p] < nums2[q] ) 
                nums1[i] = nums2[q--] ; 
            else 
                nums1[i] = nums1[p--] ; 
        }    
        while ( q >= 0 && i >= 0 ) 
            nums1[i--] = nums2[q--] ; 
    }
};