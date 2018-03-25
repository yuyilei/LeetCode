// 方法一：
// 先用二分法把中间那个结点找到 
// 然后判断 target 是在哪一边，再用二分法查找。 
class Solution {
public:
    int findpivot(vector<int>& nums) {            
        int l = 0, r = nums.size() ; 
        while ( l < r ) {
            int mid = ( l + r ) / 2 ; 
            if ( nums[l] < nums[mid] ) 
                l = mid ; 
            else 
                r = mid ; 
        }
        return l ;                                    // 返回的index是，第一段有序序列最后一位的下标。 
    }                                                 // 比如 1,2,3,4,5 返回 4 ；        4，5，6，7，0，1，2 返回 4 
    
    int searchBypivot(vector<int>& nums, int pivot, int t) {
        if ( nums.size() == 0 ) 
            return -1 ; 
        int l = 0, r = nums.size() - 1 ; 
        if ( (t >= nums[l] && t <= nums[pivot]) )                          // target 在第一段
            r = pivot ; 
        else if ( pivot != r && t >= nums[pivot+1] && t <= nums[r] )       // target 在第二段
            l = pivot + 1 ; 
        else 
            return -1 ;                                                    // target 不在里面 
        
        while ( l <= r ) {                                                 // 这个就是普通的二分查找。                                         
            int mid = ( l + r ) / 2 ; 
            if ( nums[mid] == t ) 
                return mid ; 
            if ( t > nums[mid] ) 
                l = mid + 1 ; 
            else 
                r = mid - 1 ; 
        }
        return -1 ; 
    }
    
    int search(vector<int>& nums, int target) {
        int pivot = findpivot(nums) ; 
        return searchBypivot(nums,pivot,target) ; 
    }
};


//方法二：
// 晕死，，直接遍历也可以。。。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for ( int i = 0 ; i < nums.size() ; i++ ) 
                if ( nums[i] == target ) 
                        return i ; 
        return -1 ; 
    }
};