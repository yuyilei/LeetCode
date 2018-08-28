/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> sum;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        SumTree(root);
        map<int,int> counter;
        int max_count = 0;
        for ( int i = 0 ; i < sum.size() ; i++ ) {
            if ( counter.count(sum[i]) == 0 ) {
                counter[sum[i]] = 0;
            }
            counter[sum[i]]++;
            max_count = max(max_count,counter[sum[i]]);
        }
        vector<int> res;
        for ( map<int, int>::iterator iter = counter.begin() ; iter != counter.end() ; iter++ ) {
            if ( iter->second == max_count ) {
                res.push_back(iter->first);
            }
        }
        return res;
    }
    int SumTree(TreeNode* root) {
        if ( !root )
            return 0;
        if ( !root->left && !root->right ) {
            sum.push_back(root->val);
            return root->val;
        }
        int res = root->val + SumTree(root->left) + SumTree(root->right);
        sum.push_back(res);
        return res;
    }
};