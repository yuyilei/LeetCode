//题目条件里面有 0 < nums[i] < n 就说明可以把原数组作为哈希表 
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res ; 
        for ( int i = 0 ; i < nums.size() ; i++ ){
            int index = abs(nums[i]) - 1 ;            // 用绝对值取出
            if ( nums[index] < 0 )                    // 如果已经是负数，就说明已经出现过
                res.push_back(abs(nums[i])) ;         
            else 
                nums[index] = -nums[index] ; 
        }
        return res ; 
    }
};