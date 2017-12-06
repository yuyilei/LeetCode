class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0, lastone = 1 ; 
        vector<int> res ; 
        for ( auto num : nums ) 
            sum ^= num ; 
        while ( !(lastone & sum) ) 
            lastone <<= 1 ; 
        int res1 = 0 , res2 = 0 ; 
        for ( auto  num : nums ) {
            if ( num & lastone ) 
                res1 ^= num ; 
            else 
                res2 ^= num ;
        }
        res.push_back(res1) ; 
        res.push_back(res2) ; 
        return res ;
    }
};