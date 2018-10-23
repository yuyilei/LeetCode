/*
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddstart = new ListNode(0);
        ListNode* evenstart = new ListNode(0);
        ListNode* odd = oddstart;
        ListNode* even = evenstart;
        while ( head ) {
            odd->next = head;
            odd = odd->next;
            head = head->next;
            if ( !head )
                break;
            even->next = head;
            even = even->next;
            head = head->next;
        }
        odd->next = evenstart->next;
        even->next = NULL;
        return oddstart->next;
    }
};
