class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if ( l1 == NULL ) 
            return l2 ; 
        if ( l2 == NULL ) 
            return l1 ; 
        if ( l1->val > l2->val ) {
            l2->next = mergeTwoLists(l1,l2->next) ; 
            return l2 ; 
        } 
        l1->next = mergeTwoLists(l1->next,l2) ;  // else  
        return l1 ;
    }
};