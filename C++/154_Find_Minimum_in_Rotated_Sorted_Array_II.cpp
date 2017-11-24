class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1 ; 
        while ( left < right){
            int mid = (left+right)/2 ; 
            if ( nums[mid] > nums[right] )        // 后半段有序，所求数字在前半部分
                left = mid + 1 ; 
            else if ( nums[mid] < nums[right])    //  所求数字在后半段 
                right = mid ;  
            else right-- ;                        //  相等就把right--，相当于在数组中去除这个数字，但这个数字还是保存在mid 
        } 
        return nums[left] ; 
    }
};