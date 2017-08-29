class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) { 
        int i , len = 0 ; 
        ListNode* tmp = head , *res = head ;
        for ( ; tmp != NULL ; tmp = tmp->next ) 
            len++ ; 
        if ( n == len ) 
            return head->next ; 
        for ( i = 1 ; i + n < len   ; head = head->next )
            i++ ;  
        head->next = head->next->next ; 
        return  res ; 
    }
};