/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/
class Solution {
public:
    void swap(vector<int>& nums, int a, int b) {
        int x = nums[a]; 
        nums[a] = nums[b];
        nums[b] = x; 
    }
    void moveZeroes(vector<int>& nums) {
        int num0 = 0; 
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( nums[i] != 0 ) {
                continue; 
            }
            for ( int j = i, step ; j < nums.size() - num0 ; ) {
                step = 1; 
                while ( j + step < nums.size() - num0 && nums[j+step] == 0 ) 
                    step++; 
                if ( j + step < nums.size() ) {
                    swap(nums,j,j+step); 
                }
                j = j + step;
            }
            num0++;
        }
    }
}; 