class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (vector<int>:: iterator it = nums.begin() ; it != nums.end() ; ) {
            if ( *it == val ){
                it = nums.erase(it) ; //  删除之后指向下一个元素 
            } 
            else 
                it++ ; 
        }
        return nums.size() ; 
    }
};