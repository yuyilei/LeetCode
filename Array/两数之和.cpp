/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int,int> counter; 
        map<int,vector<int>> index;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            if ( !counter.count(nums[i]) ) 
                counter[nums[i]] = 0;
            counter[nums[i]]++; 
            index[nums[i]].push_back(i);
        }
        for ( int num : nums ) {
            int other = target - num;
            counter[num]--;
            if ( counter.count(other) && counter[other] != 0 ) {
                res.push_back(index[num][0]);
                if ( other == num ) {
                    res.push_back(index[other][1]);
                }
                else {
                    res.push_back(index[other][0]);
                }
                break;
            } 
        }
        return res;
    }
}; 