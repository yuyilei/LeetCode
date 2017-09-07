class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == NULL || head->next == NULL ) 
            return head ; 
        ListNode * res = NULL , * start = NULL ; 
        int tmp ; 
        while ( head ) { 
            tmp = head->val ; 
            if ( ( head->next && tmp != head->next->val) || head->next == NULL ){ // 数字的值与下一个节点中的值不相等，或下一个节点不存在
                if ( res == NULL ) {  // 链表中还没有元素
                    res = head ; 
                    start = res ; 
                } 
                else {  //在链表最后追加元素 
                    res->next = head ; 
                    res = res->next ; 
                } 
            } 
            while ( head && tmp == head->val ) // 到达下一个与当前数字不相等的节点
                    head = head->next ;  
        } 
        if ( res == NULL ) 
            return NULL ; 
        res->next = NULL ; // 将后面不必要的节点清除 
        return start ; 
    }
};