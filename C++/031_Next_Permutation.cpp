//解法一： 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = nums.size()-1 , i , tmp ; 
        while ( index && nums[index] <= nums[index-1] ) // 从最后一位开始找，找到不是递增的第一个元素的下标index
            index-- ; 
        if ( index == 0 ) {                             // 表示这个序列已经是最后一个排序，只要倒转一下，返回第一个就行了
            reverse(nums.begin(),nums.end()) ; 
            return ; 
        }
        index-- ; 
        for ( i = index + 1 , tmp = index ; i < nums.size() ; i++ ) {   //  从index开始找最小的比nums[index]的数字的下标tmp
            if ( nums[i] <= nums[index] ) 
                break ;
            tmp = i ; 
        } 
        swap(nums[tmp],nums[index]) ;   // 交换两个数字
        reverse(nums.begin()+index+1, nums.end()) ;    // 将nums[index]之后的序列倒转 
    }
};

// 解法二: 
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end() ) ;     // 他居然直接有这种函数，晕。。。。。
    }
};