class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end()); 
        int res = INT_MAX , tmp = INT_MAX ; 
        for ( int i = 0 ; i < nums.size() - 2 ; i++ ){
            while ( i > 0 && nums[i] == nums[i-1] )
                i++ ;  
            int l = i + 1 , r = nums.size() - 1 ; 
            while ( l < r ) { 
                int sum = nums[i] + nums[l] + nums[r] ; 
                if ( sum == target ) 
                    return target ; 
                if ( sum > target ) {
                    if ( sum - target < tmp ) {
                        tmp = sum - target ;
                        res = sum ;  
                    } 
                    while ( l < --r && nums[r+1] == nums[r] ) ; 
                } 
                else {
                    if (target - sum < tmp ) {
                        tmp = target - sum ; 
                        res = sum ; 
                    }
                    while ( ++l < r && nums[l-1] == nums[r] ) ; 
                }
            }
        }
        return res ; 
    }
};