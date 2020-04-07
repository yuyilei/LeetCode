/*
Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.

 

Example:

Input: the node c from the linked list a->b->c->d->e->f
Output: nothing is returned, but the new linked list looks like a->b->d->e->f

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 复制后面的每个节点，其实没必要
class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node->next) {
            node->val = node->next->val;
            if (node->next->next)
                node = node->next;
            else
                node->next = NULL;
        }
    }
};


// 改进，只复制一个节点
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
