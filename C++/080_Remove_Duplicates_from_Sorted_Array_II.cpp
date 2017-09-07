class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if ( nums.size() < 3 )
            return nums.size() ; 
        int i = 0 , j = 0 , now , res , tmp ; 
        while ( j < nums.size() ) {
            nums[i] = nums[j++] ; 
            now = nums[i++] ;   
            tmp = 1 ;  
            while ( nums[j] == now && j < nums.size() ){
                if ( tmp ){
                    nums[i++] = now ; 
                    tmp = 0 ; 
                } 
                j++ ; 
            }
        }
        return i ; 
    }
};