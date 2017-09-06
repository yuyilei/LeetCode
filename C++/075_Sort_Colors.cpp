// 题目要求不能用内置的排序，所以我写了一个冒泡排序!!
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i , j , len = nums.size() ; 
        for ( i = 0 ; i < len ; i++ ){
            for ( j = i + 1 ; j < len ; j++ ){
                if ( nums[i] > nums[j] ) 
                    swap(nums[i],nums[j]) ; 
            }
        }
    }
};
// 很特殊的方法，把0，1，2的个数数出来，再逐个赋值
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int tmp[3] = {0} , i ; 
        for ( i = 0 ; i < nums.size() ; i++ ){
            tmp[nums[i]]++ ; 
        } 
        for ( i = 0 ; i < nums.size() ; i++ ){
            if ( tmp [0] ){
                nums[i] = 0 ; 
                tmp[0]-- ; 
            } 
            else if ( tmp[1] ) {
                nums[i] = 1 ;
                tmp[1]-- ; 
            } 
            else if ( tmp[2] ) {
                nums[i] = 2 ; 
                tmp[2]-- ; 
            }
        }
    }
};