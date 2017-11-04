/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return createBST(head,NULL) ; 
    }
    TreeNode *createBST(ListNode *s, ListNode *e){
        if ( s == e ) return NULL ; 
        ListNode *fast = s , *slow = s ; 
        while ( fast != e && fast->next != e ) {
            fast = fast->next->next ; 
            slow = slow->next ; 
        }
        TreeNode *root = new TreeNode(slow->val) ;  
        root->left = createBST(s,slow) ; 
        root->right = createBST(slow->next,e) ; 
        return root ; 
    }
};