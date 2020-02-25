/*
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

 

Example 1:



Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
Example 2:



Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false
Example 3:



Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false
Example 4:



Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
Output: false
 

Constraints:

1 <= n <= 10^4
leftChild.length == rightChild.length == n
-1 <= leftChild[i], rightChild[i] <= n - 1

*/


/*
 * 二叉树的条件：
 * 1. 有且只有一个root
 * 2. 每个节点只有一个parent
 */

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent (n,-1);
        for (int i = 0; i < n; i++) {
            int l = leftChild[i];
            int r = rightChild[i];
            if (l != -1 && l == r) {
                return false;
            }
            if ((l != -1 && parent[l] != -1) || (r != -1 && parent[r] != -1)) {
                return false;
            }
            if (l != -1) {
                parent[l] = i;
            }
            if (r != -1) {
                parent[r] = i;
            }
        }
        int root = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                root++;
                if (root > 2)
                    return false;
            }
        }
        if (root != 1)
            return false;
        return true;
    }
};

