/*
给定一个排序数组，在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if ( nums.size() == 0 ) 
            return 0; 
        int slow = 0, fast = 0;
        for ( ; fast < nums.size() ; fast++ ) {
            if ( nums[slow] != nums[fast] ) {
                slow++; 
                nums[slow] = nums[fast];
            }
        }
        return slow+1; 
    }
}; 