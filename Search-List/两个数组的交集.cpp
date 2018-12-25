/*

给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
*/


// 一:

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        for ( auto num : s1 ) {
            if ( s2.find(num) != s2.end() )
                res.push_back(num);
        }
        return res;
    }
};


// 二：

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i = 0, j = 0;
        while ( i < nums1.size() && j < nums2.size() ) {
            if ( nums1[i] < nums2[j] ) {
                i++;
            }
            else if ( nums1[i] > nums2[j] ) {
                j++;
            }
            else {
                if ( res.empty() || res.back() != nums1[i] )
                    res.push_back(nums1[i]);
                i++; j++;
            }
        }
        return res;
    }
};
