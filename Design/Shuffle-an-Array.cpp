/*
打乱一个没有重复元素的数组。

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

/*
洗牌算法：
1）将第1个元素与n个元素中的任意一个交换(包括自己)。这时结果中第1个元素已经确定。
2）将第2个元素与n-1个元素中作任意一个交换(包括自己)。
3）重复上面步骤，直到剩1个元素为止。
*/
class Solution {
public:
    Solution(vector<int> nums) {
        pre.assign(nums.begin(),nums.end());
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return pre;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> now = pre;
        int len = now.size();
        for ( int i = 0 ; i < len ; i++ ) {
            int k = (rand() % (len - i)) + i;
            swap(now,i,k);
        }
        return now;
    }
private:
    vector<int> pre;
    void swap(vector<int> &now, int a, int b) {
        int tmp = now[a];
        now[a] = now[b];
        now[b] = tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
