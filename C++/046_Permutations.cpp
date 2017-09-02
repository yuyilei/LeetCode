// 解法一
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res ; 
        sort(nums.begin(),nums.end()) ; 
        res.push_back(nums) ; 
        while ( next_permutation(nums.begin(),nums.end()) )  // 该函数会改变区间[beg , end)内的元素次序，使它们符合“下一个排列次序” , 对映的是prev_permutation 
            res.push_back(nums) ; 
        return res ; 
    }
} ;

// 解法二 
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res ; 
        getres(nums,res,0) ; 
        return res ; 
    }
    void getres(vector<int> nums , vector<vector<int> > &res , int pos ){
        if ( pos == nums.size() ) {
            res.push_back(nums) ; 
            return ; 
        }
        for ( int i = pos ; i < nums.size() ; i++ ){
            swap(nums[i],nums[pos]) ; 
            getres(nums,res,pos+1) ; 
            swap(nums[i],nums[pos]) ; 
        }
    }
} ;  