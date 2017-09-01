// 解法一: 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map <int,int> counts ; 
        for ( vector<int>::iterator it = nums.begin() ; it != nums.end() ; it++ ){
            if ( counts.count(*it) ){
                counts[*it]++ ; 
            }  
            else {
                counts[*it] = 1 ; 
            }
        }
        for ( map<int,int>::iterator it = counts.begin() ; it != counts.end() ; it++ ) {
            if ( it->second == 1 ){
                return it->first ; 
            }
        }
    }
};
// 解法二： 
// 这才是正宗的解法！！
//考虑每个元素的为一个32位的二进制数，这样每一位上出现要么为1 ，要么为0。对数组，统计每一位上1 出现的次数count，必定是3N或者3N+1 次。让count对3取模，能够获得到那个只出现1次的元素该位是0还是1。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size() , i , count , j , tmp , res = 0 ; 
        for ( j = 0 ; j < 32 ; j++ ){  
            tmp = 1 << j ; 
            for ( i = 0 , count = 0 ; i < len ; i++ ){
                if ( nums[i] & tmp ) {
                    count ++ ; 
                }
            }
            if ( count % 3 ){
                res |= tmp ;   
            }
        }
        return res ; 
    }
};