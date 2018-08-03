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
        if ( !headA || !headB ) {
            return NULL; 
        } 
        int numA = 1, numB = 1; 
        for ( auto tmpA = headA ; tmpA ; tmpA = tmpA->next ) 
            numA++; 
        for ( auto tmpB = headB ; tmpB ; tmpB = tmpB->next ) 
            numB++; 
        while ( numA != numB ) {
            if ( numA > numB ) { 
                numA--; 
                headA = headA->next; 
            }
            else {
                numB--;
                headB = headB->next; 
            }
        }
        for ( ; headA && headB ; headA = headA->next, headB = headB->next ) {
            if ( headA == headB ) 
                return headA; 
        } 
        return NULL; 
    }
};