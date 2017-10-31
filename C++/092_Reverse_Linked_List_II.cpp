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
    ListNode* reverseBetween(ListNode* head, int m, int n) { 
        ListNode *h = head , *tmp = NULL , *h1 = head , *h2 = head ; 
        for ( int i = 0 ; i < n ; h2 = h2->next , i++) ; // h2是n之后的链表 
        for ( int i = 0 ; i < n ; h = h->next, i++ ) {   // 这个循环获得m到n之间的倒置链表
            if ( i < m - 1 ) 
                continue ; 
            ListNode *s = new ListNode(h->val) ;
            s->next = tmp ;
            tmp = s ; 
        }
        for ( int i = 0 ; i < m - 2  ; h1 = h1->next , i++ ) ;  
        h1->next = tmp ;                                 // 将倒置链表连接到m之后 
        for ( ; h1->next ; h1 = h1->next ) ;
        h1->next = h2 ;                                  // 将原链表连接到n之后 
        return ( m == 1 ) ? head->next : head ; 
    }
};