/*
动态规划 
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> res(target+1,0);
        res[0] = 1;
        for ( int i = 1 ; i <= target ; i++ ){
            for ( int j = 0 ; j < nums.size() && nums[j] <= i ; j++ ){
                res[i] += res[i-nums[j]];
            }
        }      
        return res[target];
    }
};