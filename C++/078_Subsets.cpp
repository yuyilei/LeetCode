class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res; 
        vector<int> tmp ; 
        this->nums = nums ; 
        getres(res,tmp,0) ; 
        return res ; 
    } 
private : 
    vector<int> nums ; 
    void getres(vector<vector<int> > & res , vector<int> &tmp , int pos ) {
        res.push_back(tmp) ; 
        for ( int i = pos ; i < nums.size() ; i++ ){
            tmp.push_back(nums[i]) ; 
            getres(res,tmp,i+1) ; 
            tmp.pop_back() ; 
        }
    }
};