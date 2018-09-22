/*
给定两个数组，编写一个函数来计算它们的交集。
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> counter; 
        vector<int> res;
        for ( int num : nums1 ) {
            if ( !counter.count(num) ) 
                counter[num] = 0;
            counter[num]++;
        }
        for ( int num : nums2 ) {
            if ( counter.count(num) && counter[num] != 0 ) {
                res.push_back(num);
                counter[num]--;
            }
        }
        return res;
    }
};