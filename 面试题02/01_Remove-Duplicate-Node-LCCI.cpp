/*
Write code to remove duplicates from an unsorted linked list.

Example1:

 Input: [1, 2, 3, 3, 2, 1]
 Output: [1, 2, 3]
Example2:

 Input: [1, 1, 1, 1, 2]
 Output: [1, 2]
Note:

The length of the list is within the range[0, 20000].
The values of the list elements are within the range [0, 20000].
Follow Up:

How would you solve this problem if a temporary buffer is not allowed?

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head || !head->next)
            return head;
        vector<bool> v (20001, false);
        ListNode* res = head;
        ListNode* pre = NULL;
        while (head) {
            if (v[head->val]) {
                pre->next = head->next;
            }
            else {
                v[head->val] = true;
                pre = head;
            }
            head = head->next;
        }
        return res;
    }
};
