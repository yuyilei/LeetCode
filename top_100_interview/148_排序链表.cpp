/*
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

示例 1:

输入: 4->2->1->3
输出: 1->2->3->4
示例 2:

输入: -1->5->3->4->0
输出: -1->0->3->4->5


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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = slow;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return mergeList(sortList(head), sortList(slow));
    }
private:
    ListNode* mergeList(ListNode* a, ListNode* b) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while (a && b) {
            if (a->val < b->val) {
                cur->next = a;
                a = a->next;
            }
            else {
                cur->next = b;
                b = b->next;
            }
            cur = cur->next;
        }
        if (a)
            cur->next = a;
        if (b)
            cur->next = b;
        return res->next;
    }
};
