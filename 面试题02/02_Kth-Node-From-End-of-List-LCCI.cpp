/*
Implement an algorithm to find the kth to last element of a singly linked list. Return the value of the element.

Note: This problem is slightly different from the original one in the book.

Example:

Input:  1->2->3->4->5 和 k = 2
Output:  4
Note:

k is always valid.

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
    int kthToLast(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (k > 0) {
            k--;
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->val;
    }
};
