/*
Given a (0-indexed) integer array nums and two integers low and high, return the number of nice pairs.

A nice pair is a pair (i, j) where 0 <= i < j < nums.length and low <= (nums[i] XOR nums[j]) <= high.

 

Example 1:

Input: nums = [1,4,2,7], low = 2, high = 6
Output: 6
Explanation: All nice pairs (i, j) are as follows:
    - (0, 1): nums[0] XOR nums[1] = 5
    - (0, 2): nums[0] XOR nums[2] = 3
    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 2): nums[1] XOR nums[2] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5
Example 2:

Input: nums = [9,8,4,2,1], low = 5, high = 14
Output: 8
Explanation: All nice pairs (i, j) are as follows:
​​​​​    - (0, 2): nums[0] XOR nums[2] = 13
    - (0, 3): nums[0] XOR nums[3] = 11
    - (0, 4): nums[0] XOR nums[4] = 8
    - (1, 2): nums[1] XOR nums[2] = 12
    - (1, 3): nums[1] XOR nums[3] = 10
    - (1, 4): nums[1] XOR nums[4] = 9
    - (2, 3): nums[2] XOR nums[3] = 6
    - (2, 4): nums[2] XOR nums[4] = 5
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 2 * 104
1 <= low <= high <= 2 * 104


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-pairs-with-xor-in-a-range
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Trie {
public:
    Trie() {}
    void insert(int x) {
        Trie* root = this;
        for (int i = 15; i >= 0; i--) {
            int mask = (x >> i) & 1;
            if (root->next[mask] == nullptr) {
                root->next[mask] = new Trie();
            }
            root = root->next[mask];
            root->cnt++;                 // 此节点以下，不包括此节点的节点个数
        }
    }

    int query(int x, int high) {         // 查询当前的数中与x异或的结果小于high的最大结果
        int res = 0;
        Trie* root = this;
        for (int i = 15; i >= 0; i--) {
            int u = (x >> i) & 1;
            int h = (high >> i) & 1;
            if (u == 0 && h == 0) {     // u ^ 0 = 0, u ^ 1 = 1
                root = root->next[0];   // 只能选择走0分支
            }
            if (u == 0 && h == 1) {
                if (root->next[0])
                    res += root->next[0]->cnt;
                root = root->next[1];  // 选择走1的分支，同时0的分支的数符合要求
            }
            if (u == 1 && h == 0) {    // u ^ 1 = 0, u ^ 0 = 1
                root = root->next[1];  // 只能选择走1分支
            }
            if (u == 1 && h == 1) {
                if (root->next[1])
                    res += root->next[1]->cnt;
                root = root->next[0];  // 选择走0的分支，同时1的分支的数符合要求
            }
            if (root == nullptr)
                return res;
        }
        res += root->cnt;
        return res;
    }
private:
    Trie* next[2] = {nullptr};
    int cnt = 0;
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int res = 0;
        Trie* trie = new Trie();
        for (int i = 0; i < nums.size(); i++) {
            trie->insert(nums[i]);
            int l = trie->query(nums[i], low-1);
            int h = trie->query(nums[i], high);
            res += (h-l);
        }
        return res;
    }
};
