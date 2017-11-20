class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int res1, res2, count1=0, count2=0 ;
        vector<int> res ; 
        if ( nums.empty() ) return res ; 
        for ( auto num:nums){
            if ( res1 == num )
                count1++ ; 
            else if ( res2 == num ) 
                count2++ ; 
            else if ( count1 == 0 ) {
                count1 = 1 ;
                res1 = num ; 
            } 
            else if ( count2 == 0 ) {
                count2 = 1 ;
                res2 = num ;  
            } 
            else {
                count1-- ; 
                count2-- ; 
            }
        } 
        count1 = 0 ; count2 = 0 ; 
        for ( auto num:nums ){
            if ( res1 == num ) count1++ ;
            if ( res2 == num ) count2++ ; 
        }
        if ( count1 > nums.size()/3 ) res.push_back(res1) ; 
        if ( count2 > nums.size()/3 ) res.push_back(res2) ; 
        return res ; 
    }
};