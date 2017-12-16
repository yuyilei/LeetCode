class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0 ; 
        for ( auto item : nums )
            sum += item ; 
        if ( sum % 2 ) 
            return false ;
        sum /= 2 ;
        vector<int> tmp (sum+1) ; 
        tmp[0] = 1 ; 
        for ( auto item : nums ) {
            for ( int i = sum ; i  >= item ; i-- )
                tmp[i] += tmp[i-item] ;  
        }
        return tmp[sum] != 0 ; 
    }
};