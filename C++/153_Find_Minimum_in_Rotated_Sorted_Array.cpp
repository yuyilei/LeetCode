// 解法一： 直接查找 事件复杂度 O(n)
class Solution {
public:
    int findMin(vector<int>& nums){
        for ( int i = 0 ; i < nums.size() - 1 ; i++ )
            if ( nums[i] > nums[i+1] ) 
                return nums[i+1] ; 
        return nums[0] ; 
    }
};

// 解法二：二叉搜索 O(log(n)) 
class Solution {
public: 
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1 ;  // 通过两个指针渐渐逼近所要查找的数
        while ( left < right ){
            int mid = (left+right)/2 ; 
            if ( nums[mid] > nums[right] )  // 说明后半段递增，要找的数在前半段
                left = mid + 1 ; 
            else                            // 反之，要找的数在后半段   
                right = mid ;
        }
        return nums[left] ;      
    }
};