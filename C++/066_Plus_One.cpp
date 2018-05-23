class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res ;
        int c = 1 ; 
        for ( int i = digits.size() - 1 ; i >= 0 ; i-- ) {
            res.push_back( (digits[i]+c)%10 ) ; 
            c = ( digits[i] + c ) / 10 ; 
        }
        if ( c != 0 ) 
            res.push_back(c) ; 
        reverse(res.begin(),res.end()) ;
        return res ; 
    }
};