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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL , *tmp = new ListNode(0) ;
        res = tmp ; 
        int last = 0 ; 
        while ( l1 || l2 ){
            int key1 = ( l1 ) ? l1->val : 0 ; 
            int key2 = ( l2 ) ? l2->val : 0 ; 
            tmp->next = new ListNode( (key1+key2+last) % 10 ) ; 
            last = (key1+key2+last)/10 ; 
            tmp = tmp->next ; 
            if ( l1 ) l1 = l1->next ; 
            if ( l2 ) l2 = l2->next ; 
        } 
        if ( last > 0 )
            tmp->next = new ListNode(last) ; 
        return res->next ; 
    }
};