class Solution {  // 做这种题，一定要画个图！！
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *res , *start ,*tmp , *last = NULL ; 
        if ( head == NULL || head->next == NULL )
            return head ; 
        start = head->next ; 
        while ( head != NULL ) { 
            if ( head->next == NULL ) {
                res = head ; 
                break ; 
            }
            tmp = head->next->next ;
            res = head->next ;
            if ( last ) 
                last->next = res ; 
            res->next = head ; 
            last = head ; 
            res->next->next = tmp ; 
            head = tmp ;  
        } 
        return start ;
    }
};