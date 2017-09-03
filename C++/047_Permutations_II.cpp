// 解法一： 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res ; 
        sort(nums.begin(),nums.end()) ; 
        res.push_back(nums) ; 
        while(next_permutation(nums.begin(),nums.end())) 
            res.push_back(nums) ;
        return res ; 
    }
};
// 解法二：
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > res ; 
        set<vector<int> > tmp ; 
        getres(tmp,res,nums,0) ; 
        return res ; 
    }
    void getres(set<vector<int> > &tmp, vector<vector<int> > &res , vector<int> nums , int pos) {
        if ( pos == nums.size() - 1 ){
            if ( tmp.count(nums) == 0 ){
                res.push_back(nums) ; 
                tmp.insert(nums) ; 
            }
            return ; 
        } 
        for ( int i = pos ; i < nums.size() ; i++ ){
            swap(nums[i],nums[pos]) ; 
            getres(tmp,res,nums,pos+1) ; 
            swap(nums[i],nums[pos]) ; 
        }
    }
};