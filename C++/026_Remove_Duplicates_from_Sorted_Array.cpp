class Solution {
public:
    int removeDuplicates(vector<int>& nums) { 
        if ( nums.size() == 0 || nums.size() == 1 ) 
            return nums.size() ;
        int last = nums[0] , res = 1 ; 
        vector<int>:: iterator it = nums.begin() ; 
        it++ ; 
        for ( ; it != nums.end() ; ){
            if ( *it == last ) {
                nums.erase(it) ;
            }
            else {
                last = *it ; 
                it++ ; 
                res++ ; 
            }
        }
        return res ; 
    }
};