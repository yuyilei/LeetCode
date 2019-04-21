/*
编写一个程序，找到两个单链表相交的起始节点。



例如，下面的两个链表：

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3
在节点 c1 开始相交。



注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if ( !headA || !headB )
            return NULL;
        int lenA = 0, lenB = 0;
        for ( ListNode *tmp = headA ; tmp ; tmp = tmp->next )
            lenA++;
        for ( ListNode *tmp = headB ; tmp ; tmp = tmp->next )
            lenB++;
        while ( lenA > lenB ) {
            headA = headA->next;
            lenA--;
        }
        while ( lenA < lenB ) {
            headB = headB->next;
            lenB--;
        }
        for ( ; headA && headB ; headA = headA->next, headB = headB->next ) {
            if ( headA == headB )
                return headA;
        }
        return NULL;
    }
};


// 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if ( !headA || !headB ) 
            return NULL;
        int lenA = 0, lenB = 0;
        for ( ListNode *tmp = headA ; tmp ; tmp = tmp->next ) 
            lenA++;
        for ( ListNode *tmp = headB ; tmp ; tmp = tmp->next ) 
            lenB++;
        while ( lenA > lenB ) {
            lenA--;
            headA = headA->next;
        }
        while ( lenB > lenA ) {
            lenB--;
            headB = headB->next; 
        }
        while ( headA && headB && headA != headB ) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
