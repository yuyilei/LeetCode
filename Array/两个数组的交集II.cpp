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

/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if ( nums1.empty() || nums2.empty() )
            return {};
        if ( nums1.size() < nums2.size() )
            return getintersect(nums1, nums2);
        else
            return getintersect(nums2, nums1);
    }
private:
    vector<int> getintersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> counter;
        for ( int num : nums1 )
            counter[num]++;
        vector<int> res;
        for ( int i = 0 ; i < nums2.size() ; i++ ) {
            if ( counter[nums2[i]] != 0 ) {
                res.push_back(nums2[i]);
                counter[nums2[i]]--;
                if ( res.size() == nums1.size() )
                    return res;
            }
        }
        return res;
    }
};


// 先排序
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if ( nums1.empty() || nums2.empty() ) 
            return {};
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while ( i < nums1.size() && j < nums2.size() ) {
            if ( nums1[i] < nums2[j] ) 
                i++;
            else if ( nums2[j] < nums1[i] ) 
                j++;
            else {
                res.push_back(nums1[i]);
                i++; j++;
            }
        }
        return res;
    }
};
