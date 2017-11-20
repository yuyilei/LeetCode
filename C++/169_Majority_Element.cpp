// 解法一： 出现n/2次以上的数字一定在排序之后的数组的中间 
// 时间复杂度 : O(nlogn) 空间复杂度 : O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end()) ; 
        return nums[nums.size()/2] ; 
    }
};

// 解法二： 借助map，时间复杂度 :O(n) 空间复杂度：O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> tmp ; 
        for ( int i = 0 ; i < nums.size() ; i++ ){ 
            if ( !tmp.count(nums[i])) 
                tmp[nums[i]] = 0 ; 
            tmp[nums[i]]++ ; 
            if ( tmp[nums[i]] > nums.size() / 2 ) 
                return nums[i] ; 
        }
    }
};


// 解法三： 摩尔投票算法（计算一个序列中出现最多的数字) 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res, count = 0 ;  
        for ( auto num : nums ){
            if ( count == 0 ) 
                res = num ; 
            else if ( res == num ) 
                count++ ; 
            else if ( res != num ) 
                count-- ; 
        } 
        return res ; 
    }
};

// 分为两种情况 
// 1) count == 0 时，将当前元素赋给res（参选元素0 
// 2) count !=0 时。如果当前元素nums[i]!=res count--； 否则count++; （遇到不同的元素就count--，消去一个元素. 
// 数组中从res被赋值到count减到0的那一段可以被去除，余下部分的多数元素依然是原数组的多数元素。