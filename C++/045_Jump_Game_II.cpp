// last表示上一次达到的最大距离，当前位置i大于last时，说明需要向前走一步，把last更新到reach 
// reach表示能到达的最远距离，nums[i]+i表示当前位置能到达的最远距离 
class Solution {
public:
    int jump(vector<int>& nums) {   
        int reach = 0 , last = 0 , res = 0 ;
        for ( int i = 0 ; i <= reach && i < nums.size() ; i++ ) {
            if ( i > last ) { 
                res++ ; 
                last = reach ; 
            } 
            reach = max(reach,nums[i]+i) ; 
        } 
        return  res ;
    }
};