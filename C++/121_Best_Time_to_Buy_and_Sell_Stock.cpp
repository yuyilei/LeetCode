class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        if ( prices.size() <= 1 ) 
            return 0 ; 
        if ( prices.size() == 2 ) 
            return (prices[1]>prices[0]) ? prices[1] - prices[0] : 0 ; 
        int l = 1 , r = prices.size() - 2 , res = 0 ;
        int sell = prices[prices.size() - 1] , buy = prices[0] ; 
        while ( l <= r ) { 
            if  ( prices[r] - buy < sell - prices[l] ){
                buy = min(buy,prices[l]) ;
                l++ ;  
            } 
            else {
                sell = max(sell,prices[r]) ; 
                r-- ;
            }
            res = ( sell > buy ) ? ( sell - buy ) : 0 ; 
        }
        return res ; 
    }
};