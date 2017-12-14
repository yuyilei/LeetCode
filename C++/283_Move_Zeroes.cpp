class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size(), slow = 0, fast = 0 ; 
        for ( ; fast < len ; fast++ ){
            if ( nums[fast] != 0 ) 
                nums[slow++] = nums[fast] ; 
        }
        while ( slow < fast ) 
            nums[slow++] = 0 ;
    }
};