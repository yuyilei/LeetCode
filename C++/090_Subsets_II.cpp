class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& num) {
        sort(num.begin(),num.end()) ; 
        vector<vector<int> > res ; 
        vector<int> tmp ; 
        nums = num ; 
        getres(res,tmp,0) ; 
        return res ; 
    } 
private : 
    vector<int>nums ; 
    void getres(vector<vector<int> >&res , vector<int>tmp , int pos ) { 
        res.push_back(tmp) ;  
        for ( int i = pos ; i < nums.size() ; i++ ) {
            tmp.push_back(nums[i]) ; 
            getres(res,tmp,i+1) ; 
            tmp.pop_back() ; 
            while ( i<nums.size()-1 && nums[i]==nums[i+1]) i++ ; 
        } 
    }
};