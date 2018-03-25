/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 法一： 比较直观，直接构造，但是浪费空间
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tmp = new ListNode(0) ; 
        ListNode* res = tmp ; 
        while ( head ) {
            if ( head->val != val ) {
                tmp->next = new ListNode(head->val) ; 
                tmp = tmp->next ; 
            } 
            head = head->next ; 
        } 
        return res->next ; 
    }
};


// 需要稍微想一下，但是比较节约空间，两种方法应该时间复杂度差不多 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res = new ListNode(0) ; 
        res->next = head ;
        head = res ; 
        while ( head->next ) {
            if ( head->next->val == val ) 
                head->next = head->next->next ;
            else 
                head = head->next ; 
        } 
        return res->next ; 
    }
};