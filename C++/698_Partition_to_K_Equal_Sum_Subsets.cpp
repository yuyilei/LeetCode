// 法一：
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0 ; 
        for ( auto num : nums )
            sum += num ; 
        if ( sum % k ) return false ; 
        sort(nums.begin(),nums.end()) ; 
        vector<int> tmp (k,0) ;
        return getres(nums,sum/k,tmp,nums.size()-1) ; 
    } 
    bool getres(vector<int> nums, int target, vector<int> &tmp, int index) {
        if ( index == -1 ) {
            for ( auto item : tmp ) 
                if ( item != target ) 
                    return false ; 
            return true ; 
        } 
        int now = nums[index] ; 
        for ( int i = 0 ; i < tmp.size() ; i++ ) {
            if ( tmp[i] + now > target ) 
                continue ; 
            tmp[i] += now ; 
            if ( getres(nums,target,tmp,index-1) ) 
                return true ; 
            tmp[i] -= now ; 
        }
        return false ;
    } 
};



// 法二：
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0 ; 
        for ( auto num : nums ) 
            sum += num ; 
        if ( sum % k ) 
            return false ; 
        vector<bool> flag (nums.size(),false) ; 
        return getres(nums,k,sum/k,0,0,flag) ; 
    } 
    bool getres(vector<int> nums, int k, int target, int index, int now, vector<bool>& flag) {
        if ( k == 1 ) 
            return true ;
        if ( now == target ) 
            return getres(nums,k-1,target,0,0,flag) ; 
        for ( int i = index ; i < nums.size() ; i++ ) {
            if ( flag[i] ) 
                continue ;  
            flag[i] = true ; 
            if (getres(nums,k,target,i+1,now+nums[i],flag) ) 
                return true ; 
            flag[i] = false ; 
        } 
        return false ; 
    }
};