/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1); 
        dummy->next = head;
        ListNode* curr= dummy; 
        ListNode* temp = head; 
        int count= 1; 
        if(head== NULL || head->next== NULL) return NULL; 
        while(temp){
            temp= temp->next; 
            count++; 
        }
        temp = head; 
        int k = count-n; 
        while(--k){
           curr = curr->next; 
        }
        curr->next =curr->next->next; 
        return dummy->next;
    }
};