/*
打乱一个没有重复元素的数组。

示例:

// 以数字集合 1, 2 和 3 初始化数组。
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
solution.shuffle();

// 重设数组到它的初始状态[1,2,3]。
solution.reset();

// 随机返回数组[1,2,3]打乱后的结果。
solution.shuffle();
*/

class Solution {
public:
    Solution(vector<int>& nums) {
        original = nums;
        len = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res (original);
        for ( int i = 0 ; i < len ; i++ ) {
            int next_index = i + (rand() % (len-i));  // 从当前元素到最后一个元素中随机选一个数进行交换 
            swap(res[i], res[next_index]);
        }
        return res;
    }
private:
    vector<int> original;
    int len;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
