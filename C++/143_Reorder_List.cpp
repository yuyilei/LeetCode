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
    void reorderList(ListNode* head) {
        if ( !head || !(head->next))
            return ; 
        int len = 0 ; 
        for ( ListNode *t = head ; t ; len++ , t = t->next ) ; 
        int mid = (len+1)/2 ; 
        ListNode *tmp = NULL , *h = head , *res = head , *last ; 
        for ( int i = 0 ; i < mid ; h = h-> next , i++ ) ;   
        for ( tmp = h , h = h->next ; h ; h = h->next){  // 制作后半边的链表 
            ListNode *s = new ListNode(h->val) ;
            s->next = tmp ; 
            tmp = s ; 
        } 
        for ( int i = 0 ; i < (len-mid) ; i++ ){   // 把后半边的链表中的节点一个一个的放到前半部分
            ListNode *k = res->next ; 
            res->next = new ListNode(tmp->val) ; 
            res->next->next = k ; 
            last = res->next ; 
            res = res->next->next ; 
            tmp = tmp->next ; 
        }  
        if ( len % 2 )
            res->next = NULL ; 
        else 
            last->next = NULL ;
    }
};