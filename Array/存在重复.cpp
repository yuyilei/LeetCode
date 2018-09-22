/*
给定一个整数数组，判断是否存在重复元素。
如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
*/

/*
利用set 
set集合是c++ stl库中自带的一个容器，set具有以下两个特点：
1、set中的元素都是排好序的
2、set集合中没有重复的元素
C++ STL中标准关联容器set, multiset, map, multimap内部采用的就是一种非常高效的平衡检索二叉树：红黑树，也成为RB树(Red-Black Tree)。
RB树的统计性能要好于一般平衡二叉树，所以被STL选择作为了关联容器的内部结构。
有如下性质:
map和set的插入删除效率比用其他序列容器高；
每次insert之后，以前保存的iterator不会失效； 
当数据元素增多时，set的插入和搜索速度变化较慢，利用二叉树查找，数据数量增加一倍，搜索次数加一。 
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s; 
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            s.insert(nums[i]); 
        }
        return s.size() != nums.size();
    }
}; 