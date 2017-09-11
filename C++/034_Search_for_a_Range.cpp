class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = { -1 ,-1 } ; 
        for ( int i = 0 ; i < nums.size() ; i++ ){
            if ( nums[i] > target ) 
                break ; 
            if ( nums[i] == target ){
                res[0] = (res[0] == -1) ? i : res[0] ; 
                res[1] = i ;
            }
        }
        return res ; 
    }
};