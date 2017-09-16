class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res ; 
        if (nums.size() <= 2 ) 
            return res ; 
        sort(nums.begin(),nums.end()) ; 
        for ( int i = 0 ; i < nums.size()-2 && nums[i] <= 0 ; i++ ){
            if ( i > 0  && nums[i] == nums[i-1] ) // 跳过重复元素  
                continue ;  
            int l = i + 1 , r = nums.size() -1 ; 
            while ( l < r ) {
                if ( nums[i]+nums[l]+nums[r] == 0 ){
                    res.push_back({nums[i],nums[l],nums[r]}) ; 
                    while ( ++l < r && nums[l] == nums[l-1] ) ;   // 
                    while ( l < --r && nums[r] == nums[r+1] ) ;   // 跳过重复元素 
                } 
                else if ( nums[i]+nums[l]+nums[r] < 0 )
                    l++ ; 
                else 
                    r-- ; 
            }
        }
        return res ; 
    }
};