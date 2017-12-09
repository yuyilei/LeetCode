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
        stack<int> t1, t2 ; 
        ListNode *tmp = NULL , *res = NULL ; 
        int last = 0 ; 
        while ( l1 || l2 ){
            if ( l1 ){
                t1.push(l1->val) ; 
                l1 = l1->next ; 
            } 
            if ( l2 ){
                t2.push(l2->val) ; 
                l2 = l2->next ; 
            } 
        }
        while ( !t1.empty() || !t2.empty() ){
            int key1 = (!t1.empty())?t1.top():0 ; 
            int key2 = (!t2.empty())?t2.top():0 ; 
            int key = key1 + key2 + last ; 
            last = key/10 ; 
            if ( !t1.empty() ) t1.pop() ; 
            if ( !t2.empty() ) t2.pop() ;
            tmp = new ListNode(key%10) ; 
            tmp->next = res ;
            res = tmp ; 
        }
        if ( last > 0 ) {
            tmp = new ListNode(last) ; 
            tmp->next = res ; 
            res = tmp ; 
        }
        return res ; 
    }
};