/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 要求 O(nlogn)的时间复杂度，空间复杂度为常数，排除快速排序，堆排序太复杂，使用归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if ( !head || !head->next ) 
            return head ; 
        ListNode *h1 = head ; 
        ListNode* h2 = getmid(head) ; 
        h1 = sortList(h1) ; 
        h2 = sortList(h2) ; 
        return merge(h1,h2) ; 
    } 
    ListNode* getmid(ListNode* head){                                     // 使用快慢指针获得中间值
        ListNode *fast = head->next, *slow = head->next, *pre = head ; 
        while ( true ){
            if ( !fast->next || !fast->next->next ) 
                break ; 
            fast = fast->next->next ;
            pre = slow ; 
            slow = slow->next ; 
        }
        pre->next = NULL ;                                               // 切断！！关键一步 
        return slow ; 
    } 
    ListNode* merge(ListNode* h1, ListNode*h2) {
        ListNode *head = new ListNode(0) ; 
        ListNode *tail = head ; 
        while ( h1 && h2 ){
            if ( h1->val < h2->val ){
                tail->next = h1 ; 
                h1 = h1->next ; 
            } 
            else {
                tail->next = h2 ; 
                h2 = h2->next ; 
            }
            tail = tail->next ; 
            tail->next = NULL ; 
        } 
        if ( h1 ) 
            tail->next = h1 ; 
        if ( h2 ) 
            tail->next = h2 ; 
        return head->next ; 
    }
};