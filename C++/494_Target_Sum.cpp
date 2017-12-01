class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0 ; 
        for ( auto item : nums ) 
            sum += item ; 
        if ( sum < S || (sum + S) % 2 )
            return 0 ; 
        int target = ( sum + S ) / 2 ; 
        vector<int> tmp (target+1,0) ; 
        tmp[0] = 1 ; 
        for ( auto item : nums )
            for ( int i = target ; i >= item ; i-- )
                tmp[i] += tmp[i-item] ; 
        return tmp[target] ; 
    }
}; 