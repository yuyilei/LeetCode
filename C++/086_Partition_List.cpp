/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 遍历原链表，根据val的值将生成两个链表，最后连接这两个链表 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = NULL, *h2 = NULL, *t1 = NULL, *t2 = NULL ;
        while (head){
            if ( (head->val) < x ){
                if ( h1 ){
                    t1->next = head ; 
                    t1 = t1->next ; 
                } 
                else h1 = t1 = head ;
            } 
            else {
                if ( h2 ){
                    t2->next = head ; 
                    t2 = t2->next ; 
                } 
                else h2 = t2 = head ; 
            }
            head = head->next ;
        }
        if ( t2 ) t2->next = NULL ; 
        if ( t1 ) t1->next = h2 ;
        return (h1) ? h1 : h2 ; 
    }
};