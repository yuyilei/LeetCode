/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 ≤ i ≤ j < n.

Follow up: Could you do this in O(n) runtime?

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [0]
Output: 0
Example 3:

Input: nums = [2,4]
Output: 6
Example 4:

Input: nums = [8,10,2]
Output: 10
Example 5:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
 

Constraints:

1 <= nums.length <= 2 * 104
0 <= nums[i] <= 231 - 1


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
  前缀树
*/
class Trie {
public:
    Trie() {

    }
    void insert(int value) {
        Trie* root = this;
        for (int i = 30; i >= 0; i--) {
            int mask = (value >> i) & 1;
            if (root->next[mask] == nullptr) {
                root->next[mask] = new Trie();
            }
            root = root->next[mask];
        }
    }
    int search(int value) {
        Trie* root = this;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            int mask = (value >> i) & 1;
            if (root->next[!mask] != nullptr) {
                res = res*2 + !mask;
                root = root->next[!mask];
            }
            else {
                res = res*2 + mask;
                root = root->next[mask];
            }
        }
        return res ^ value;
    }
private:
    Trie* next[2] = {nullptr};
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        for (int num: nums) {
            trie->insert(num);
        }
        int res = 0;
        for (int num: nums) {
            int tmp = trie->search(num);
            res = max(res, tmp);
        }
        return res;
    }
};
