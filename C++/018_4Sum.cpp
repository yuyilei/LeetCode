class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res ; 
        if ( nums.size() < 4 )
            return res ; 
        sort(nums.begin(),nums.end()) ; 
        for ( int i = 0 ; i < nums.size() - 3 ; i++ ){ 
            while ( i > 0 && i < nums.size() -3 && nums[i-1] == nums[i] )
                i++ ; 
            for ( int j = i + 1 ; j < nums.size() - 2 ; j++ ){ 
                while ( j > i + 1 && j < nums.size() - 2 && nums[j] == nums[j-1] ) 
                    j++ ; 
                int l = j + 1 , r = nums.size() - 1 ; 
                while ( l < r ){
                    int sum = nums[i] + nums[j] + nums[l] + nums[r] ; 
                    if ( sum == target ) {
                        res.push_back({nums[i],nums[j],nums[l],nums[r]}) ; 
                        while ( ++l < r && nums[l-1] == nums[l] ) ; 
                        while ( l < --r && nums[r+1] == nums[r] ) ; 
                    } 
                    else if ( sum < target )
                        l++ ; 
                    else 
                        r-- ; 
                }
            }
        }
        return res ; 
    }
};