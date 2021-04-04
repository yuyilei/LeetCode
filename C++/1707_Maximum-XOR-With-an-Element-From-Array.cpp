/*
You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

 

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]
 

Constraints:

1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Trie {
public:
    Trie() {}
    void insert(int num) {
        Trie* root = this;
        for (int i = 31; i >= 0; i--) {
            int mask = (num >> i) & 1;
            if (root->next[mask] == nullptr) {
                root->next[mask] = new Trie();
            }
            root = root->next[mask];
        }
    }

    int search(int x) {
        Trie* root = this;
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int mask = (x >> i) & 1;
            if (root->next[!mask] != nullptr) {
                root = root->next[!mask];
                res = res*2 + !mask;
            }
            else if (root->next[mask] != nullptr){
                root = root->next[mask];
                res = res*2 + mask;
            }
            else {
                return -1;
            }
        }
        return x^res;
    }
private:
    Trie* next[2] = {nullptr};
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie* trie = new Trie();
        int index = 0, len = queries.size();
        vector<vector<int>> qs (len, vector<int> (3, 0));
        vector<int> res (len, -1);
        vector<int> idx (len, 0);
        for (int i = 0; i < len; i++) {
            qs[i][0] = queries[i][0];
            qs[i][1] = queries[i][1];
            qs[i][2] = i;
        }
        sort(nums.begin(), nums.end());
        sort(qs.begin(), qs.end(), cmp);
        for (int i = 0; i < len; i++) {
            while (index < nums.size() && nums[index] <= qs[i][1]) {
                trie->insert(nums[index]);
                index++;
            }
            if (index != 0)
                res[qs[i][2]] = trie->search(qs[i][0]);
        }
        return res;
    }
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
};
